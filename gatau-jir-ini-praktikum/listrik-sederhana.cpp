#include <iostream>
using namespace std;

// Fungsi untuk menghitung resistansi total pada rangkaian seri
double totalResistansiSeri(int n, double R[])
{
    double R_total = 0;
    for (int i = 0; i < n; i++)
    {
        R_total += R[i];
    }
    return R_total;
}

// Fungsi untuk menghitung resistansi total pada rangkaian paralel
double totalResistansiParalel(int n, double R[])
{
    double R_total = 0;
    for (int i = 0; i < n; i++)
    {
        R_total += 1 / R[i];
    }
    return 1 / R_total;
}

int main()
{
    int n;
    cout << "Masukkan jumlah resistor: ";
    cin >> n;

    double R[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan nilai resistansi R" << i + 1 << " (dalam ohm): ";
        cin >> R[i];
    }

    int pilihan;
    cout << "\nPilih jenis rangkaian:\n";
    cout << "1. Rangkaian Seri\n";
    cout << "2. Rangkaian Paralel\n";
    cin >> pilihan;

    if (pilihan == 1)
    {
        double R_seri = totalResistansiSeri(n, R);
        cout << "Total resistansi pada rangkaian seri adalah: " << R_seri << " ohm\n";
    }
    else if (pilihan == 2)
    {
        double R_paralel = totalResistansiParalel(n, R);
        cout << "Total resistansi pada rangkaian paralel adalah: " << R_paralel << " ohm\n";
    }
    else
    {
        cout << "Pilihan tidak valid!\n";
    }

    return 0;
}
