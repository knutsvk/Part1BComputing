#include "Particle.h"

void initialiseWall(Particle &p, double pos)
{
    p.x = pos;
    p.p = 0;
    p.im = 0;
    p.v = 0;
    p.T = 0;
    p.a = 0.01;
}

void initialiseRandom(Particle &p, double xmin, double xmax)
{
    p.x = xmin + (xmax - xmin) * ranf();
    p.im = ranf();
    p.v = ranf() - 0.5;
    p.p = p.v / p.im;
    p.T = 0.5 * p.p * p.v;
    p.a = xmax-p.x < p.x-xmin ? (xmax-p.x) * ranf() : (p.x-xmin) * ranf();
}

void print(Particle p)
{
    printf("%8.4g\t%8.4g\t%8.4g\t%8.4g\t%8.4g\t%8.4g\n", 
            p.x, p.p, p.im, p.v, p.T, p.a);
}

void printAssembly(Particle *p, int N)
{
    for(int i = 1; i <= N; i++)
    {
        printf("%.8fg\t", p.x);
    }
    printf("\n");
}

void move(Particle &p, double t)
{
    p.x += p.v * t; 
}

void collide(Particle &p1, Particle &p2)
{
    // Compute new velocities 
    double u1 = (p1.v * p2.im + p1.im * (2 * p2.v - p1.v)) / (p1.im + p2.im);
    double u2 = (p2.v * p1.im + p2.im * (2 * p1.v - p2.v)) / (p1.im + p2.im);
    // Update velocities
    p1.v = u1; 
    p2.v = u2;
    // Update momenta
    p1.p = p1.v / p1.im;
    p2.p = p2.v / p2.im;
    // Update kinetic energy
    p1.T = 0.5 * p1.v * p1.v / p1.im;
    p2.T = 0.5 * p2.v * p2.v / p2.im;
}

bool touchingEachOther(Particle p1, Particle p2)
{
    // TODO: Implement
    return false;
}

double collisionTime(Particle p1, Particle p2)
{
    // TODO: Take into consideration radius of particles
   return (p1.x - p2.x) / (p2.v - p1.v); 
}

double nextCollision(Particle *p, int N)
{
    double shortestTime = collisionTime(p[0], p[1]);
    double t; 
    for(int i = 1; i <= N; i++)
    {
        t = collisionTime(p[i], p[i+1]); 
        if(t < shortestTime)
            shortestTime = t; 
    }
    return shortestTime;
}
