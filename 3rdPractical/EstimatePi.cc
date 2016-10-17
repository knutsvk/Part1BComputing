// EstimatePi.cc
//   usage:
//      ./EstimatePi [N]
//   example:
//      ./EstimatePi        (Run with default value of N)
//      ./EstimatePi 300    (Run with N=300)

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

int main(int argc, char* argv[])
{
    int N = 10; 
    double term, sum, pi, err, relerr; 

    // Use command-line argument if given
    if(argc>1)
        N = atoi(argv[1]);

    // Write out a summary of parameters
    cout << "# " << argv[0] << ",\tN = " << N << ". " << endl;

    // Write out column headers for output
    cout << "#i\t1/i^2\tsum\tpi\terror\trelerror" << endl; 

    // Sum together N first terms 
    for(int i = 1; i <= N; i++) 
    {
        term = 1.0 / (i * i); 
        sum += term; 
        pi = sqrt(6 * sum);
        err = abs(M_PI - pi);
        relerr = err / M_PI; 
        cout << i << "\t" << term << "\t" << sum << "\t" << pi << "\t" << err
            << "\t" << relerr << endl; 
    }

    return 0;
}
