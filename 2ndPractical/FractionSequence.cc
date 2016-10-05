#include <iostream>
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
        x = 1 + 1.0 / x; 
        i++;
    }

    return 0;
}
