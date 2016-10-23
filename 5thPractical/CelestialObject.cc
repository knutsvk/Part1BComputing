#include "CelestialObject.h"

void initialiseSun(CelestialObject &sun)
{
    /* Initialise a celestial object as the sun, at rest in the origin */

    sun.mass = 1.9891e30;
    sun.position[0] = 0.0;
    sun.position[1] = 0.0;
    sun.velocity[0] = 0.0;
    sun.velocity[1] = 0.0;
}

void initialiseEarth(CelestialObject &earth)
{
    /* Initialise a celestial object as the Eearth, placed 1 astronomical unit
     * to the right of the origin, travelling with the Earth's mean speed  */

    earth.mass = 5.972e24;
    earth.position[0] = AU;
    earth.position[1] = 0.0;
    earth.velocity[0] = 0.0;
    earth.velocity[1] = EMS;
}

double distance(CelestialObject planet)
{
    /* Returns the distance of a planet to the origin */

    double sum = 0.0;
    for(int i = 0; i < DIM; i++)
        sum += planet.position[i] * planet.position[i];
    return sqrt(sum); 
}

double speed(CelestialObject planet)
{
    /* Returns the speed of a planet */ 

    double sum = 0.0;
    for(int i = 0; i < DIM; i++)
        sum += planet.velocity[i] * planet.velocity[i];
    return sqrt(sum); 
}

double potentialEnergy(CelestialObject planet, CelestialObject sun)
{
    /* Returns the potential energy of a planet orbiting a sun */
    // TODO
    return 0;
}

double kineticEnergy(CelestialObject planet)
{
    /* Returns the kinetic energy of a celestial object */

    return 0.5 * planet.mass * speed(planet) * speed(planet);
}

double energy(CelestialObject planet, CelestialObject sun)
{
    /* Returns the total energy of a planet orbiting a sun */
    return potentialEnergy(planet, sun) + kineticEnergy(planet);
}

double angularMomentum(CelestialObject planet)
{
    /* Returns the angular momentum of a planet */

    return speed(planet) / distance(planet);
}

void updateForce(CelestialObject &planet, CelestialObject sun)
{
    /* Updates the gravitational force acting on a planet due to the presence
     * of a nearby star */

    double A = - G * planet.mass * sun.mass;
    double r = distance(planet);

    for(int i = 0; i < DIM; i++)
        planet.force[i] = A * planet.position[i] / (r * r * r);
}

void incrementPosition(CelestialObject &planet, double dt)
{
    /* Given a time step, increments the position of the planet based on its
     * velocity */
    for(int i = 0; i < DIM; i++)
    {
        planet.position[i] += dt * planet.velocity[i];
    }
}

void incrementVelocity(CelestialObject &planet, double dt)
{
    /* Given a time step, increments the velocity of the planet based on the
     * forces acting on it */
    for(int i = 0; i < DIM; i++)
    {
        planet.velocity[i] += dt * planet.force[i] / planet.mass;
    }
}

void euler(CelestialObject &planet, CelestialObject sun, double &t, double dt)
{
    /* Advance planet's orbit in time by time step dt according to Euler's
     * method */

    updateForce(planet, sun);
    incrementPosition(planet, dt);
    incrementVelocity(planet, dt);
    t += dt;
}

void leapfrog(CelestialObject &planet, CelestialObject sun, double &t, double dt)
{
    /* Advance planet's orbit in time by time step dt according to the leapfrog
     * method */

    incrementPosition(planet, 0.5 * dt);
    t += 0.5 * dt; 
    updateForce(planet, sun);
    incrementVelocity(planet, dt);
    incrementPosition(planet, 0.5 * dt);
    t += 0.5 * dt; 
}

void printp(CelestialObject planet, CelestialObject sun)
{
    /* Print state of a given celestial planetect */ 

    printf("%12.6g\t%12.6g\t%12.6g\t%12.6g\t%12.6g\t%12.6g\t%12.6g\t%12.6g\n", 
            planet.position[0], planet.position[1], 
            planet.velocity[0], planet.velocity[1], 
            angularMomentum(planet), potentialEnergy(planet, sun),
            kineticEnergy(planet), energy(planet, sun));
}
