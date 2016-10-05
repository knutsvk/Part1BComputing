#include <iostream>
using namespace std; 

int main()
{
    double cups, dl, factor = 2.366;

    cout << "Amount of cups: ";
    cin >> cups; 

    dl = cups * factor; 
    cout << cups << " cups equals  " << dl << " deciliters. " << endl;

    return 0;
}
