#include <iostream>

using namespace std;

int main()
{
    double v, t, s;

    cout << "Masukkan kecepatan km/jam (v): ";
    cin >> v;

    cout << "Masukkan jarak (s): ";
    cin >> t;

    t = s / v;

    cout << "jarak (s) yang ditempuh adalah: " << s << " jam" << endl;

    return 0;
}