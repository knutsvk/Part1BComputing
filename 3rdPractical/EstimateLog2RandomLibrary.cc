// EstimateLog2.cc
//   usage:
//      ./EstimateLog2 [<tol>]
//   example:
//      ./EstimateLog2          (Run with default value of tol)
//      ./EstimateLog2 0.01     (Run with tol=0.01)

#include <iostream>
#include <random>
#include <cmath>

using namespace std;

int main(int argc, char* argv[])
{
    // Declaration of variables
    int outcome, N, count_in=0;
    double fraction_in, tol=0.01, x, y; 

    // Initialize random number generator from real distribution
    default_random_engine generator;
    uniform_real_distribution<double> distribution(0.5, 1);

    // Use specified tolerance if given at runtime
    if(argc>1)
        tol = atof(argv[1]);

    // Compute the required number of points for desired accuracy
    N = 10 * ceil((log(2) - 0.5) * (log(2) - 0.5) / (tol * tol));
    
    // Write out a summary of parameters
    cout << "# " << argv[0] << " tol=" << tol << " N=" << N << endl;

    // Initialise y in [0.5, 1]
    y = distribution(generator);

    // Perform N experiments.
    for(int n=1; n<=N; n++) 
    {
        // Get x in [1, 2]
        x = 2 * y;  
        y = distribution(generator);

        // Outcome 1 if in unit circle, else 0
        outcome = (x*y <= 1.0) ? 1 : 0;
        count_in += outcome ;

        // Compute the fraction of points which have been in the circle
        fraction_in = static_cast<double>(count_in)/n;
    }
    
    double estimate = (fraction_in + 1.0) / 2.0;

    cout << "ln(2) ≈ " << estimate << " (error = " << abs(log(2) - estimate) << ")" << endl; 

    return 0;
}
