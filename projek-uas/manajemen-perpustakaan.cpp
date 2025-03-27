#include <iostream>
#include <string>
#include <map>
#include <ctime>

using namespace std;

const int MAX_BUKU = 100;  // Batas maksimal jumlah buku

struct Buku {
    string judul;
    bool dipinjam;
};

struct Anggota {
    string nama;
    string password;
    map<string, time_t> historiPeminjaman;  // Menyimpan waktu peminjaman buku
    int penalti = 0;
};

// Fungsi untuk menampilkan menu utama anggota
int tampilkanMenuUtama() {
    cout << "\n=== Menu Perpustakaan ===\n";
    cout << "1. Peminjaman Buku\n";
    cout << "2. Pengembalian Buku\n";
    cout << "3. Cek Status Peminjaman\n";
    cout << "4. Lihat Histori Peminjaman\n";
    cout << "5. Lihat Penalti\n";
    cout << "6. Keluar\n";
    int pilihan;
    cout << "Pilih menu: ";
    cin >> pilihan;
    return pilihan;
}

// Fungsi untuk menampilkan menu admin
int tampilkanMenuAdmin() {
    cout << "\n=== Menu Admin ===\n";
    cout << "1. Tambah Buku\n";
    cout << "2. Lihat Daftar Buku\n";
    cout << "3. Keluar\n";
    int pilihan;
    cout << "Pilih menu: ";
    cin >> pilihan;
    return pilihan;
}

// Fungsi untuk registrasi anggota baru
Anggota registrasiAnggota(map<string, Anggota>& daftarAnggota) {
    string nama, password;
    cout << "Masukkan nama: ";
    cin >> nama;
    cout << "Masukkan password: ";
    cin >> password;

    Anggota anggotaBaru = {nama, password, {}, 0};
    daftarAnggota[nama] = anggotaBaru;
    cout << "Registrasi berhasil!\n";
    return anggotaBaru;
}

// Fungsi untuk login anggota
Anggota* login(map<string, Anggota>& daftarAnggota) {
    string nama, password;
    cout << "Masukkan nama: ";
    cin >> nama;
    cout << "Masukkan password: ";
    cin >> password;

    if (daftarAnggota.find(nama) != daftarAnggota.end() && daftarAnggota[nama].password == password) {
        cout << "Login berhasil!\n";
        return &daftarAnggota[nama];
    } else {
        cout << "Nama atau password salah.\n";
        return nullptr;
    }
}

// Fungsi untuk login admin
bool loginAdmin(string adminUsername, string adminPassword) {
    string nama, password;
    cout << "Masukkan username admin: ";
    cin >> nama;
    cout << "Masukkan password admin: ";
    cin >> password;

    if (nama == adminUsername && password == adminPassword) {
        cout << "Login admin berhasil!\n";
        return true;
    } else {
        cout << "Username atau password admin salah.\n";
        return false;
    }
}

// Fungsi untuk menampilkan daftar buku yang tersedia
int pilihBukuTersedia(Buku daftarBuku[], int jumlahBuku) {
    cout << "\nDaftar Buku Tersedia:\n";
    bool bukuTersedia = false;
    for (int i = 0; i < jumlahBuku; i++) {
        if (!daftarBuku[i].dipinjam) {
            cout << i + 1 << ". " << daftarBuku[i].judul << endl;
            bukuTersedia = true;
        }
    }

    if (!bukuTersedia) {
        cout << "Tidak ada buku yang tersedia saat ini.\n";
        return -1;
    }

    int pilihan;
    cout << "Pilih buku yang ingin dipinjam (masukkan nomor): ";
    cin >> pilihan;
    return pilihan - 1;
}

// Fungsi untuk meminjam buku
bool peminjamanBuku(Buku daftarBuku[], int jumlahBuku, Anggota& anggota) {
    int pilihan = pilihBukuTersedia(daftarBuku, jumlahBuku);

    if (pilihan >= 0 && pilihan < jumlahBuku && !daftarBuku[pilihan].dipinjam) {
        daftarBuku[pilihan].dipinjam = true;
        anggota.historiPeminjaman[daftarBuku[pilihan].judul] = time(0);  // Catat waktu peminjaman
        cout << "Buku '" << daftarBuku[pilihan].judul << "' berhasil dipinjam.\n";
        return true;
    } else {
        cout << "Pilihan tidak valid atau buku sudah dipinjam.\n";
        return false;
    }
}

// Fungsi untuk mengembalikan buku
bool pengembalianBuku(Buku daftarBuku[], int jumlahBuku, Anggota& anggota) {
    cout << "\nDaftar Buku yang Dipinjam:\n";
    int index = 0;
    for (int i = 0; i < jumlahBuku; i++) {
        if (daftarBuku[i].dipinjam && anggota.historiPeminjaman.find(daftarBuku[i].judul) != anggota.historiPeminjaman.end()) {
            cout << i + 1 << ". " << daftarBuku[i].judul << endl;
            index = i;
        }
    }

    int pilihan;
    cout << "Pilih buku yang ingin dikembalikan (masukkan nomor): ";
    cin >> pilihan;
    pilihan -= 1;

    if (pilihan >= 0 && pilihan < jumlahBuku && daftarBuku[pilihan].dipinjam) {
        daftarBuku[pilihan].dipinjam = false;
        time_t waktuPinjam = anggota.historiPeminjaman[daftarBuku[pilihan].judul];
        time_t waktuKembali = time(0);
        anggota.historiPeminjaman.erase(daftarBuku[pilihan].judul);

        // Cek penalti jika lebih dari 7 hari
        int durasiHari = (waktuKembali - waktuPinjam) / (60 * 60 * 24);
        if (durasiHari > 7) {
            anggota.penalti += (durasiHari - 7) * 5000;  // Rp5000 per hari terlambat
            cout << "Buku terlambat dikembalikan, penalti sebesar Rp" << anggota.penalti << "\n";
        } else {
            cout << "Buku dikembalikan tepat waktu.\n";
        }
        return true;
    } else {
        cout << "Pilihan tidak valid atau buku belum dipinjam.\n";
        return false;
    }
}

// Fungsi untuk menampilkan histori peminjaman
void lihatHistori(Anggota& anggota) {
    cout << "\nHistori Peminjaman Buku:\n";
    for (const auto& entry : anggota.historiPeminjaman) {
        cout << "- " << entry.first << " (Dipinjam)\n";
    }
}

// Fungsi untuk menampilkan penalti
int lihatPenalti(Anggota& anggota) {
    cout << "\nPenalti Anda: Rp" << anggota.penalti << endl;
    return anggota.penalti;
}

// Fungsi untuk menampilkan status daftar buku (dipinjam atau tersedia)
void tampilkanDaftarBuku(Buku daftarBuku[], int jumlahBuku) {
    if (jumlahBuku == 0) {
        cout << "Belum ada buku di perpustakaan.\n";
        return;
    }

    cout << "\nStatus Buku:\n";
    for (int i = 0; i < jumlahBuku; i++) {
        cout << i + 1 << ". " << daftarBuku[i].judul 
             << (daftarBuku[i].dipinjam ? " (Dipinjam)\n" : " (Tersedia)\n");
    }
}

// Fungsi untuk menambah buku baru (admin)
void tambahBuku(Buku daftarBuku[], int& jumlahBuku) {
    if (jumlahBuku >= MAX_BUKU) {
        cout << "Batas maksimal buku tercapai!\n";
        return;
    }

    string judulBaru;
    cout << "Masukkan judul buku baru: ";
    cin.ignore();  // Mengatasi masalah input buffer
    getline(cin, judulBaru);
    daftarBuku[jumlahBuku] = {judulBaru, false};
    jumlahBuku++;
    cout << "Buku '" << judulBaru << "' berhasil ditambahkan!\n";
}

int main() {
    Buku daftarBuku[MAX_BUKU];  // Array statis untuk menyimpan daftar buku
    int jumlahBuku = 0;  // Awalnya tidak ada buku di perpustakaan

    map<string, Anggota> daftarAnggota;
    Anggota* anggotaAktif = nullptr;

    string adminUsername = "admin";  // Username admin
    string adminPassword = "admin123";  // Password admin

    int pilihan;
    do {
        cout << "\n=== Sistem Perpustakaan ===\n";
        cout << "1. Registrasi\n";
        cout << "2. Login Anggota\n";
        cout << "3. Login Admin\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            registrasiAnggota(daftarAnggota);
        } else if (pilihan == 2) {
            anggotaAktif = login(daftarAnggota);

            // Jika login berhasil
            if (anggotaAktif != nullptr) {
                int subPilihan;
                do {
                    subPilihan = tampilkanMenuUtama();

                    switch (subPilihan) {
                        case 1:
                            peminjamanBuku(daftarBuku, jumlahBuku, *anggotaAktif);
                            break;
                        case 2:
                            pengembalianBuku(daftarBuku, jumlahBuku, *anggotaAktif);
                            break;
                        case 3:
                            tampilkanDaftarBuku(daftarBuku, jumlahBuku);
                            break;
                        case 4:
                            lihatHistori(*anggotaAktif);
                            break;
                        case 5:
                            lihatPenalti(*anggotaAktif);
                            break;
                        case 6:
                            cout << "Keluar dari sistem.\n";
                            break;
                        default:
                            cout << "Pilihan tidak valid. Coba lagi.\n";
                    }
                } while (subPilihan != 6);
            }
        } else if (pilihan == 3) {
            if (loginAdmin(adminUsername, adminPassword)) {
                int adminPilihan;
                do {
                    adminPilihan = tampilkanMenuAdmin();

                    switch (adminPilihan) {
                        case 1:
                            tambahBuku(daftarBuku, jumlahBuku);
                            break;
                        case 2:
                            tampilkanDaftarBuku(daftarBuku, jumlahBuku);
                            break;
                        case 3:
                            cout << "Keluar dari menu admin.\n";
                            break;
                        default:
                            cout << "Pilihan tidak valid. Coba lagi.\n";
                    }
                } while (adminPilihan != 3);
            }
        } else if (pilihan == 4) {
            cout << "Terima kasih telah menggunakan sistem perpustakaan.\n";
        } else {
            cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilihan != 4);

    return 0;
}


