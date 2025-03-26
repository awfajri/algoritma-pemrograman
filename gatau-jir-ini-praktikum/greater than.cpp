#include <iostream>
using namespace std;

int main()
{
    int angka1, angka2, angka3;

    cout << "Selamat datang di program pemilihan angka terbesar" << endl;
    cout << "Silahkan masukan angka1: ";
    cin >> angka1;
    cout << "Silahkan masukan angka2: ";
    cin >> angka2;
    cout << "Silahkan masukan angka3: ";
    cin >> angka3;

    // Menggunakan operator logika && untuk membandingkan setiap pasangan angka
    if (angka1 >= angka2 && angka1 >= angka3)
    {
        cout << "Angka terbesar adalah: " << angka1 << endl;
    }
    else if (angka2 >= angka1 && angka2 >= angka3)
    {
        cout << "Angka terbesar adalah: " << angka2 << endl;
    }
    else
    {
        cout << "Angka terbesar adalah: " << angka3 << endl;
    }

    return 0;
}