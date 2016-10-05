#include <iostream>
using namespace std; 

int main()
{
    double x, y; 
    int N = 20; 
    int i = 1; 

    cout << "Enter x: " << endl; 
    cin >> x; 
    y = x; 
    
    cout << "i\tsum" << endl; 
    while(i <= N)
    {
        printf("%d\t%.8f\n", i, y);
        y = x + 1.0 / y; 
        i++;
    }

    return 0;
}
