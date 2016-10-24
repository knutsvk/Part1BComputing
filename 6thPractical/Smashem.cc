#include <cstdio>
#include <ctime>
#include "Particle.h"

int main(int argc, char *argv[])
{
    int N = 10;
    if(argc > 1)
        N = atoi(argv[1]);

    Particle *assembly; 
    assembly = new Particle[N+2];

    initialiseWall(assembly[0], 0.0);
    initialiseWall(assembly[N+1], static_cast<double>(N+1));

    srandom(time(NULL));
    for(int i = 1; i <= N; i++)
    {
        initialiseRandom(assembly[i], static_cast<double>(i));
    }

    double t = 0.0;
    printf("%4.2g\t", t);
    printAssembly(assembly, N);
    double dt = 0.01;
    double nextPrint = dt;
    double T = 10.0;
    double tSmash, tPrint;
    while(t < T)
    {
        tSmash = nextCollision(assembly, N);
        tPrint = nextPrint - t;

        if(tSmash < tPrint)
        {
            printf("# SMASH");
            for(int i = 1; i <= N; i++)
                move(assembly[i], tSmash);

            for(int i = 0; i <= N; i++)
            {
                if(touchingEachOther(assembly[i], assembly[i+1]))
                    collide(assembly[i], assembly[i+1]);
            }

            t += tSmash;
        }
        else
        {
            for(int i = 1; i <= N; i++)
                move(assembly[i], tPrint);

            t += tPrint;
            nextPrint = t + dt;

            printf("%8.4g\t", t);
            printAssembly(assembly, N);

        }
    }

    return 0;
}
