#include <cstdlib>
#include <cstdio>
#include <cmath>

struct Particle
{
    double x;   // Position
    double p;   // Momentum
    double im;  // Inverse mass
    double v;   // Velocity
    double T;   // Kinetic energy
    double a;   // Radius
};

void initialiseWall(Particle &p, double pos);
void initialiseRandom(Particle &p, double pos);

void print(Particle p);
void printAssembly(Particle *p, int N);

void move(Particle &p, double t);
void collide(Particle &p1, Particle &p2);

bool touchingEachOther(Particle p1, Particle p2);
double collisionTime(Particle p1, Particle p2);
double nextCollision(Particle *p, int N);

#define ranf() \
    ((double)random()/(1.0+(double)0x7fffffff)) // Uniform from interval [0,1)
                                                // obtained by division by 2**31
