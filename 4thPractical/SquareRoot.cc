#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

double f(int c, double x); 
void updateDomain(double &a, double &b, int c, double p);
double squareRoot(int c);

int main(int argc, char* argv[])
{
    int N = 10; 

    // Use command-line argument if given
    if(argc > 1)
    {
        N = atoi(argv[1]);
    }

    // Ensure N is in appropriate range
    while(N < 2 | N > 100)
    {
        cout << "N: ";
        cin >> N; 
    }

    printf("num\tsqrt\trelerr\n");
    for(int n = 2; n <= N; n++)
    {
        printf("%d\t%.5f\t%.2e\n", n, squareRoot(n), 
                fabs(sqrt(n) - squareRoot(n)) / sqrt(n));
    }

    return 0;
}

double f(int c, double x)
{
    return c - x * x;
}

void updateDomain(double &a, double &b, int c, double p)
{
    if(f(c, a) * f(c, p) < 0)
        b = p;
    else
        a = p;
}

double squareRoot(int c)
{
    double tol = 1e-4, a = 1, b = 10, p, err; 
    
    do
    {
        p = 0.5 * (a + b); 
        err = (b - a) / 2; 
        updateDomain(a, b, c, p);
    } 
    while(err > tol);

    return p;
}
