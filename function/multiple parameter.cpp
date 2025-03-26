#include <iostream>
using namespace std;

void myFunction(string fname, int age)
{
    cout << fname << " is " << age << " years old. \n";
}

int main()
{
    myFunction("jokowi", 3);
    myFunction("auf", 18);
    myFunction("ade", 52);
    return 0;
}