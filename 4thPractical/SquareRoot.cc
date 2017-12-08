#include <cstdlib>
#include <iostream>

using namespace std;

double f(int c, double x); 
void updateDomain(double &a, double &b, int c, double p);
double squareRoot(int c, double tol);

int main(int argc, char* argv[])
{
    int N = 10; 
    double tol = 1.0e-14;

    if(argc > 1)
    {
        N = atoi(argv[1]);
    }
    if(argc > 2)
    {
        tol = atof(argv[2]);
    }

    while(N < 2 | N > 10000)
    {
        cout << "N: ";
        cin >> N; 
    }

    printf("x\tsqrt(x)\t\trel error\n");
    for(int n = 2; n <= N; n++)
    {
        double ans = squareRoot(n, tol);
        double err = (n - ans*ans) / n;
        if (err < 0.0)
        {
            err *= -1.0;
        }
        printf("%d\t%.5f\t\t%.2e\n", n, ans, err);
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
    {
        b = p;
    }
    else
    {
        a = p;
    }
}

double squareRoot(int c, double tol)
{
    double a = 1, b = 100, p, err; 
    
    do
    {
        p = (a + b) / 2.0; 
        err = (b - a) / 2.0; 
        updateDomain(a, b, c, p);
    } 
    while(err > tol);

    return p;
}
