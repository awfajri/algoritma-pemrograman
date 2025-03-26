#include <iostream>
using namespace std;

void myFunction(string country = "Indonesia")
{
    cout << country << "\n";
}

int main()
{
    myFunction("singapura");
    myFunction("malaysia");
    myFunction();
    myFunction("USA");
    return 0;
}