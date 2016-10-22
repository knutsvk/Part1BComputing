#include <cmath>
#include <cstdlib>

DIM = 2; 

struct CelestialObject
{
    // General celestial object, initialised as the sun
    double mass = 1.9891e30;
    double position[DIM] = {0.0, 0.0};
    double velocity[DIM] = {0.0, 0.0};
};

void gravity(CelestialObject planet, CelestialObject sun, double &force);
void euler(CelestialObject &planet, CelestialObject sun, double dt);
void print(CelestialObject planet);
