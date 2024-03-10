#include <iostream>
using namespace std;

int main(){
    // deklarasi 
    double hasil, uang;

    // Masukkan Uang yang ingin dikonversi
    cout << "Masukkan jumlah uang : ";
    cin >> uang;

    // Konversi
    hasil = uang/15000;

    // Hasil konversi
    cout << "Uang Dollar anda adalah : " << hasil << endl;
    
    return 0;
}