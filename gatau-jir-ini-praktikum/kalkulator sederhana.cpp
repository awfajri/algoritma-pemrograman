#include <iostream>

using namespace std;

int main()
{
    char operasi;
    float angka1, angka2, hasil;

    cout << "Aplikasi Kalkulator sederhana\n";
    cout << "Auf Fajri Ramadhani - 1F\n";
    cout << "Pilih operasi yang ingin dilakukan:\n";
    cout << "+ untuk penjumlahan\n";
    cout << "- untuk pengurangan\n";
    cout << "* untuk perkalian\n";
    cout << "/ untuk pembagian\n";
    cin >> operasi;

    cout << "Masukkan angka pertama: ";
    cin >> angka1;

    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    switch (operasi)
    {
    case '+':
        hasil = angka1 + angka2;
        break;
    case '-':
        hasil = angka1 - angka2;
        break;
    case '*':
        hasil = angka1 * angka2;
        break;
    case '/':
        if (angka2 == 0)
        {
            cout << "Tidak dapat membagi dengan nol.\n";
        }
        else
        {
            hasil = angka1 / angka2;
        }
        break;
    default:
        cout << "Operasi tidak valid.\n";
        return 1;
    }

    cout << "Hasil: " << hasil << endl;

    return 0;
}