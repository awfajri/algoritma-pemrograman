#include <iostream>
using namespace std;

double basicSalary(int workingHours)
{
    return 2000 * workingHours;
}

double overtime(int workingHours)
{
    if (workingHours > 7)
    {
        return (workingHours - 7) * 2000 * 0.015;
    }
    else
    {
        return 0;
    }
}

double mealsAllowance(int workingHours)
{
    if (workingHours >= 8)
    {
        return 3500;
    }
    else
    {
        return 0;
    }
}

double transportAllowance(int workingHours)
{
    if (workingHours >= 9)
    {
        return 4000;
    }
    else
    {
        return 0;
    }
}

double totalSalary(int workingHours)
{
    return basicSalary(workingHours) + overtime(workingHours) + mealsAllowance(workingHours) + transportAllowance(workingHours);
}

int main()
{
    string NIP, name;
    int workingHours;

    cout << "Masukkan NIP: ";
    cin >> NIP;
    cout << "Masukkan Nama: ";
    cin >> name;
    cout << "Masukkan Jam Kerja: ";
    cin >> workingHours;

    double basic = basicSalary(workingHours);
    double ot = overtime(workingHours);
    double meal = mealsAllowance(workingHours);
    double trans = transportAllowance(workingHours);
    double total = totalSalary(workingHours);

    cout << "\nRincian Gaji:\n";
    cout << "NIP: " << NIP << endl;
    cout << "Nama: " << name << endl;
    cout << "Gaji Pokok: $" << basic << endl;
    cout << "Lembur: $" << ot << endl;
    cout << "Tunjangan Makan: $" << meal << endl;
    cout << "Tunjangan Transportasi: $" << trans << endl;
    cout << "Total Gaji: $" << total << endl;

    return 0;
}