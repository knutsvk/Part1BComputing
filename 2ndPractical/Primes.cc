#include <iostream>
using namespace std; 

int main()
{
    int N; 
    cout << "How many primes do you want to see? ";
    cin >> N; 
    cout << "OK! The " << N << " first prime numbers are: " << endl; 

    int i = 1;
    int primesFound = 0; 
    bool isPrime = true; 
    while(primesFound < N)
    {
        i++;
        for(int j = 2; j < i/2; j++)
        {
            if(i % j == 0)
                isPrime = false; 
        }
        if(isPrime)
        {
            primesFound++;
            cout << primesFound << "\t" << i << endl; 
        }
        else 
        {
            isPrime = true; 
        }
    }
    return 0;
}
