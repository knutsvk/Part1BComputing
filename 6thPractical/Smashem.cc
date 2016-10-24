#include <cstdio>
#include "Particle.h"

int main(int argc, char *argv[])
{
    int N = 10;
    if(argc > 1)
        N = atoi(argv[1]);

    Particle *assembly;
    assembly = new Particle[N+2];
    initialiseWall(assembly[0], 0.0);
    initialiseWall(assembly[N+1], 10.0);
    for(int i = 1; i <= N; i++)
        initialiseRandom(assembly[i], assembly[i-1].x + assembly[i-1].a, 10.0);

    double t = 0.0;
    double dt = 0.01;
    double nextPrint = dt;
    double T = 1.0;
    double tSmash, tPrint;
    while(t < T)
    {
        tSmash = nextCollision(assembly, N);
        tPrint = nextPrint - t;

        if(tSmash < tPrint)
        {
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

            printf("%8.4g\t", t);
            printAssembly(assembly, N);

            t += tPrint;
            nextPrint = t + dt;
        }
    }

    return 0;
}
