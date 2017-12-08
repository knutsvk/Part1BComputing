#include "CelestialObject.h"
#include <iostream>
#include <random>

using namespace std;

int main(int argc, char* argv[])
{
    // Declare and initialise random number generator with angular distribution 
    std::random_device rng;     // obtain a random number from hardware
    std::mt19937 eng(rng());    // seed the generator
    std::uniform_real_distribution<> angle(0, 2*M_PI); // define the range

    // Declare and initialise sun
    CelestialObject sun;
    initialiseSun(sun);

    // Mercury, Venus, Tellus, Mars
    CelestialObject planets[4];
    initialisePlanet(planets[0], 0.330e24,  57.9e9, 47.4e3, angle(rng));
    initialisePlanet(planets[1], 4.870e24, 108.2e9, 35.0e3, angle(rng));
    initialisePlanet(planets[2], 5.970e24, 149.6e9, 29.8e3, angle(rng));
    initialisePlanet(planets[3], 0.642e24, 227.9e9, 24.1e3, angle(rng));

    double t = 0.0;
    double dt = 3600 * 24;      // Time steps of one day
    double T = 5 * 365 * dt;    // Final time 5 years

    cout << "x\ty\tu\tv\tomega\tE_p\tE_k\tE" << endl; 

    // Start simulating in time!
    while(t < T)
    {
        // For each planet
        for(int i = 0; i < 4; i++)
        {
            // Print state
            printp(planets[i], sun);

            // Move forward in time (ODE time step)
            leapfrog(planets[i], sun, t, dt);
        }
    }
    return 0;
};

