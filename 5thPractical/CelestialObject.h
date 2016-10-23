#include <cmath>
#include <cstdio>

#define DIM 2
const double G = 6.67408e-11;   // Gravitational constant
const double AU = 1.496e11;     // Astronomical unit
const double EMS = 3.0e4;       // Earth mean speed

struct CelestialObject
{
    // General celestial object, initialised as the sun
    double mass;
    double position[DIM];
    double velocity[DIM];
    double force[DIM];
};

void initialiseSun(CelestialObject &sun);
void initialiseEarth(CelestialObject &earth);

double distance(CelestialObject planet);
double speed(CelestialObject planet);
double potentialEnergy(CelestialObject planet);
double kineticEnergy(CelestialObject planet);
double energy(CelestialObject planet);
double angularMomentum(CelestialObject planet);

void updateForce(CelestialObject &planet, CelestialObject sun);
void incrementPosition(CelestialObject &planet, double dt);
void incrementVelocity(CelestialObject &planet, double dt);

void euler(CelestialObject &planet, CelestialObject sun, double &t, double dt);
void leapfrog(CelestialObject &planet, CelestialObject sun, double &t, double dt);
void rk4(CelestialObject &planet, CelestialObject sun, double &t, double dt);

void printp(CelestialObject planet);
