#include <iostream>
using namespace std;

// Membuat class
class Data{
    public:
    string nama, nim;
    int umur;
};

int main(){

    // Membuat objek dari Class Data
    Data d1;

    // Memasukkan nilai kedalam objek
    d1.nama = "Jeremy Marcello Waani";
    d1.umur = 18;
    d1.nim = "2311110003";

    // Print
    cout << d1.nama << endl;
    cout << d1.umur << endl;
    cout << d1.nim << endl;
    return 0;
}