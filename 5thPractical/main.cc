#include "CelestialObject.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    // Initialise celestial objects
    CelestialObject sun, earth;
    earth.mass = 5.972e24;
    earth.position[0] = 1.496e11;
    earth.position[1] = 0.0;
    earth.velocity[0] = 0.0;
    earth.velocity[1] = 3.0e4;

    double t = 0.0;
    double dt = 3600*24;
    double T = 3600*24*365;

    iter = 0;
    cout << "Day\tx\ty" << endl; 
    while(t < T)
    {
        if(t + dt > T)
            dt = T - t; 

        euler(earth, sun, dt);
        iter++;
        cout << iter << "\t" << earth.position[0] << "\t" << earth.position[1]
            << endl; 
    }

    return 0;
};

