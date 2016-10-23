#include "CelestialObject.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    // Initialise celestial objects
    CelestialObject sun, earth;
    initialiseSun(sun);
    initialiseEarth(earth);

    double t = 0.0;
    double dt = 3600 * 24;  // Time steps of one day
    double T = 365 * dt;    // Final time one year

    cout << "day\tx\ty\tu\tv\tomega\tE_p\tE_k\tE" << endl; 
    while(t < T)
    {
        printf("%d\t", int(t / dt));
        printp(earth, sun);

        leapfrog(earth, sun, t, dt);
    }
    return 0;
};

