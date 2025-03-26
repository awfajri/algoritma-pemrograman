#include <iostream>
using namespace std;

int greatestValue(int x, int y);
int x, y;
int main()
{
    cout << "mencari nilai tertingi: \n";
    cout << "masukan nilai x: ";
    cin >> x;
    cout << "masukan nilai y: ";
    cin >> y;
    cout << "Value tertinggi " << greatestValue(x, y);
    return 0;
}
greatestValue(int x, int y)
{
    if (x > y)
    {
        cout << "adalah x : ";
        return x;
    }
    else
    {
        cout << "adalah y : ";
        return y;
    }
}