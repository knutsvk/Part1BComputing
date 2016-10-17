// EstimateLog2.cc
//   usage:
//      ./EstimateLog2 [<tol> [<seed>]]
//   example:
//      ./EstimateLog2                 (Run with default value of tol and seed)
//      ./EstimateLog2 0.01 9237832      (Run with tol=0.01 and seed=9237832)
//   * uses random() to get a random integer
//   * gets parameters from command line

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

#define ranf() \
    ((double)random()/(1.0+(double)0x7fffffff)) // Uniform from interval [0,1)
                                                // obtained by division by 2**31

int main(int argc, char* argv[])
{
    int outcome, N, count_in=0 , seed=9873242;
    double fraction_in, tol=0.01; 

    if(argc>1)
    {
        tol = atof(argv[1]);
    }
    if(argc>2) 
    {
        seed = atoi(argv[2]);
    }
    N = 10 * ceil((log(2) - 0.5) * (log(2) - 0.5) / (tol * tol));
    // Write out a summary of parameters
    cout << "# " << argv[0] << " tol=" << tol << " N=" << N << " seed=" << seed << endl;

    // Initialise random number generator
    srandom(seed);

    // Perform N experiments.
    for(int n=1; n<=N; n++) 
    {
        double x = 1.0 + ranf();  // ranf() returns a real number in [0,1)
        double y = 0.5 + 0.5 * ranf();
        outcome = (x*y <= 1.0) ? 1 : 0;
        count_in += outcome ;
        fraction_in = static_cast<double>(count_in)/n;
    }

    cout << "ln(2) is approximately " << 0.5 * fraction_in + 0.5 << " (error = " 
        << abs(log(2) - 0.5 * fraction_in - 0.5) << ")" << endl; 

    return 0;
}
