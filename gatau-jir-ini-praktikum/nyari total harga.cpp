#include <iostream>
using namespace std;

int main()
{
    float Item_Price, Total_Price;
    string Item_Name, Item_Code;
    int Num_Item;
    cout << "masukan harga barang: ";
    cin >> Item_Price;
    cout << "masukan jumlah barang: ";
    cin >> Num_Item;
    cout << "masukan nama barang:";
    cin >> Item_Name;
    cout << "masukan kode barang:";
    cin >> Item_Code;
    Total_Price = Num_Item * Item_Price;

    cout << "\njadi total price nya adalah:" << Total_Price;
}
// Auf Fajri Ramadhani