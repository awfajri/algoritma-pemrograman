#include <iostream>

using namespace std;

// Global variable x
int x = 5;

void myFunction()
{
    // We can use x here
    cout << x << "\n";
}

int main()
{
    myFunction();

    // We can also use x here
    cout << x;
    return 0;
}