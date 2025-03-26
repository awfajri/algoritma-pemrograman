#include <iostream>
using namespace std;

int main()
{
    const float PI = 3.14;
    float circumference;
    float Surface;
    float Volume;
    int Radius;

    cout << "\nNilai jari jarinya berapa ";
    cin >> Radius;

    circumference = 2 * PI * (Radius);
    Volume = 1.3 * PI * (Radius * Radius * Radius);
    Surface = 4 * PI * (Radius * Radius);
    cout << "\njadi circumference-nya adalah " << circumference << endl;
    cout << "\njadi Volume-nya adalah " << Volume << endl;
    cout << "\njadi Surface-nya adalah " << Surface << endl;
    return 0;
}

// auf fajri ramadhani
