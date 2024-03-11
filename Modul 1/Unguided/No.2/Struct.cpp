#include <iostream>
using namespace std;

struct Data{
    string nama, nim;
    int umur;
};

int main(){
    // Membuat objek dari struct Data
    Data data;

    // Memasukkan nilai ke struct Data
    data.nama = "Jeremy Marcello Waani";
    data.umur = 18;
    data.nim = "2311110003";

    // Print
    cout << data.nama << endl;
    cout << data.nim << endl;
    cout << data.umur << endl;

    return 0;
}