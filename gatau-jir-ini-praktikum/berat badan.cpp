#include <iostream>

using namespace std;

int main()
{
    double height, weight, idealWeight;
    char retry;
start:
    // input berat dan tinggi badan
    cout << "Enter your height in centimeters: ";
    cin >> height;

    cout << "Enter your weight in kilograms: ";
    cin >> weight;

    // Hitung berat badan ideal (BMI)
    idealWeight = (height - 100) - (0.1 * (height - 100));
    // Output ideal atau tidak
    if (weight >= idealWeight - 2 && weight <= idealWeight + 2)
    {
        cout << "Your weight is ideal." << endl;
    }
    else
    {
        cout << "Your weight is not ideal." << endl;
    }
    cout << "want to repeat?[y/n]?";
    cin >> retry;
    if ((retry == 'y') || (retry == 'y'))
        goto start;

    return 0;
}
// Auf fajri ramadhani
// 2410631170059