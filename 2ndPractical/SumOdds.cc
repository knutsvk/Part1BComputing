#include <iostream>
using namespace std; 

int main()
{
    int N, sum = 0; 

    cout << "Amount of odd numbers to sum: ";
    cin >> N; 

    for( int i = 1; i <= N; i++ )
    {
        sum += ( 2 * i - 1 ); 
    }

    if( sum != N * N )
    {
        cout << "Something is wrong!" << endl; 
        return 1; 
    }
    else
    {
        cout << "The sum of the first " << N << " odd numbers is " << sum << endl;
        return 0;
    }
}
