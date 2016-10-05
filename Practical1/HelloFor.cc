#include <iostream>
using namespace std;

int main()
{
    int lucky, largest; 

    cout << "What's the lucky number?" << endl;
    cin >> lucky; 
    cout << "OK, how high should we count?" << endl; 
    cin >> largest; 
    cout << endl; 

    for (int i=1; i<=largest; i++) 
    {
        cout << i;
        if(i == lucky) 
        {
            cout << "\t - That was lucky!" << endl;
        } 
        else 
        {
            cout << endl;
        }
    }
}
