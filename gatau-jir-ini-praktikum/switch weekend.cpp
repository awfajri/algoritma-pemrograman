#include <iostream>
using namespace std;
int main()
{
    int day;
    char retry;
start:
    cout << "hari ke?:";
    cin >> day;
    switch (day)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        cout << "weekday" << endl;
        break;
    case 6:
    case 7:
        cout << "weekend" << endl;
        break;
    default:
        cout << "wrong num" << endl;
    }
    cout << "want to repeat?[y/n]?";
    cin >> retry;
    if ((retry == 'y') || (retry == 'y'))
        goto start;
    return 0;
}