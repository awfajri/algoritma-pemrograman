#include <iostream>
#include <iomanip> // untuk manipulasi output format
using namespace std;

int main() {
    int n; // Jumlah siswa
    
    cout << "Enter the number of students: ";
    cin >> n;

    // Array untuk menyimpan data siswa
    int id[n], midTest[n], finalTest[n], presence[n], task[n];
    string name[n];
    double finalGrade[n];

    // Input data untuk setiap siswa
    for (int i = 0; i < n; i++) {
        cout << "\nData number " << i+1 << endl;
        cout << "Enter Student's ID: ";
        cin >> id[i];
        cout << "Enter Student's Name: ";
        cin >> name[i];
        cout << "Enter Mid Test value: ";
        cin >> midTest[i];
        cout << "Enter Final Test value: ";
        cin >> finalTest[i];
        cout << "Enter presence value: ";
        cin >> presence[i];
        cout << "Enter Tasks value: ";
        cin >> task[i];
        
        // Menghitung nilai akhir
        finalGrade[i] = (0.3 * midTest[i]) + (0.4 * finalTest[i]) + (0.1 * presence[i]) + (0.2 * task[i]);
    }

    // Output hasil
    cout << "\nStudents Result\n";
    cout << "----------------------------------------------------------------------------\n";
    cout << "Num   ID       Name      Mid Test  Final Test  Presence  Tasks  Final Grade\n";
    cout << "----------------------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << setw(3) << i+1 << setw(7) << id[i] << setw(10) << name[i] << setw(10) << midTest[i] 
             << setw(12) << finalTest[i] << setw(10) << presence[i] << setw(7) << task[i] 
             << setw(12) << fixed << setprecision(2) << finalGrade[i] << endl;
    }
    cout << "----------------------------------------------------------------------------\n";
    cout << "\nprogram created by auf\n";
    return 0;
}
