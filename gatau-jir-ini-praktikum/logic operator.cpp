#include <iostream>
using namespace std;

int main()
{
    int x, y;
    char retry;
start:
    cout << "masukan nilai x :";
    cin >> x;
    cout << "masukan nilai y :";
    cin >> y;
    if ((x >= 0) && (y >= 0))
        cout << "x dan y positif" << endl;
    else
        cout << "x atau y negatif" << endl;
    cout << "want to repeat?[y/n]?";
    cin >> retry;
    if ((retry == 'y') || (retry == 'y'))
        goto start;
    return 0;
}