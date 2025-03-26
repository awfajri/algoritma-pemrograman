#include <iostream>
using namespace std;

int main()
{
    int month, year, days;
    char retry;
    // input bulan dan tahun

start:
    cout << "month (1-12) :";
    cin >> month;
    cout << "year :";
    cin >> year;

    // menentukan jumlah hari berdasarkan bulan
    if (month == 1 || month == 3 || month == 5 || month == 8 || month == 10 || month == 12)
    {
        days = 31;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        days = 30;
    }
    else if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) // tahun kabisat
        {
            days = 29;
        }
        else
        {
            days = 28;
        }
    }
    else
    {
        cout << "invalid month!" << endl;
        goto start;
    }
    cout << "the number of days in month " << month << ", year " << year << " is " << days << " days " << endl;
    cout << "want to repeat?[y/n]?";
    cin >> retry;
    if ((retry == 'y') || (retry == 'y'))
        goto start;
    return 0;
    // Auf fajri ramadhani
    // 2410631170059
}