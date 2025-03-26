#include <iostream>

using namespace std;

int main()
{
    double weight, height, bmi;

    cout << "Body Mass Index (BMI) Calculator" << endl;
    cout << "---------------------------------" << endl;
    cout << "Enter your weight (in kg): ";
    cin >> weight;
    cout << "Enter your height (in meters): ";
    cin >> height;

    bmi = weight / (height * height);

    cout << "Your BMI is: " << bmi << endl;

    if (bmi < 18.5)
    {
        cout << "You are underweight." << endl;
    }
    else if (bmi < 25)
    {
        cout << "You are normal weight." << endl;
    }
    else if (bmi < 30)
    {
        cout << "You are overweight." << endl;
    }
    else
    {
        cout << "You are obese." << endl;
    }

    return 0;
}