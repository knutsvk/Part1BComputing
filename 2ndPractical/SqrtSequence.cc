#include <iostream>
#include <cmath>
using namespace std; 

int main()
{
    double x = 1; 
    int N = 20; 
    int i = 1; 
    
    cout << "i\tsum" << endl; 
    while(i <= N)
    {
        printf("%d\t%.8f\n", i, x);
        x = sqrt(1 + x);
        i++;
    }

    return 0;
}
