#include <iostream>
using namespace std;

int main()
{
    int code;
    cout << "destinasi turis: " << endl
         << endl;
    cout << "1. bandung 2. yogya 3. bali 4. lombok" << endl
         << endl;
    cout << "masukan kode destinasi";
    cin >> code;
    if (code == 1)
    {
        cout << "\ndestinasi : bandung";
    }
    else if (code == 2)
    {
        cout << "\ndestinasi : yogya";
    }
    else if (code == 3)
    {
        cout << "\ndestinasi : bali";
    }
    else if (code == 4)
    {
        cout << "\ndestinasi : lombok";
    }
    else
    {
        cout << "wrong code";
    }
    return 0;
}