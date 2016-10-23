#include "CelestialObject.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    // Initialise celestial objects
    CelestialObject sun, earth;
    initialiseSun(sun);
    initialiseEarth(earth);

    // Set given initial conditions
    earth.position[0] = 1.5 * AU;
    earth.position[1] = 2.0 * AU;
    earth.velocity[0] = 0.4 * EMS;
    earth.velocity[1] = 0.0; 

    double t = 0.0;
    double dt = 3600 * 24;      // Time steps of one day
    double T = 2 * 365 * dt;    // Final time two years

    cout << "day\tx\ty\tu\tv\tomega\tE_p\tE_k\tE" << endl; 
    while(t < T)
    {
        printf("%d\t", int(t / dt));
        printp(earth, sun);

        leapfrog(earth, sun, t, dt);
    }
    return 0;
};

