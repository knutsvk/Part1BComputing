#include "CelestialObjects.h"

void gravity(CelestialObject planet, CelestialObject sun, double &force)
{
    /* Find the gravitational force acting on a planet which orbits the sun */

    // Declare and initialise variables
    double G = 6.67384e-11;     // Gravitational constant
    double m = planet.mass;
    double M = sun.mass;
    double A = - G * M * m; 
    double x[DIM];
    double denominator = 0.0;

    // Compute distances and denominator
    // (squared sum of distances to power of 3/2)
    for(int i = 0; i < DIM; i++)
    {
        x[i] = planet.position[i] - sun.position[i];
        denominator += x[i] * x[i];
    }
    denominator = pow(denominator, 1.5);

    // Compute force
    for(int i = 0; i < DIM; i++)
    {
        force[i] = A * x[i] / denominator; 
    }
}

void euler(CelestialObject &planet, CelestialObject sun, double &t, double dt)
{
    /* Advance planet's orbit in time by time step dt according to Euler's
     * method */

    // Declare and compute force acting on planet
    double force; 
    gravity(planet, sun, force);

    // Update position and velocity
    for(int i = 0; i < DIM; i++)
    {
        planet.position[i] += dt * planet.velocity[i]; 
        planet.velocity[i] += dt * force[i]
    }

    // Increase current time
    t += dt; 
}

void print(CelestialObject planet)
{
    printf("Celestial object with mass %g, currently located at (%.2f, %.2f), moving with velocity (%g, %g).\n", planet.mass, planet.position[0], planet.position[1], planet.velocity[0], planet.velocity[1]);
}
