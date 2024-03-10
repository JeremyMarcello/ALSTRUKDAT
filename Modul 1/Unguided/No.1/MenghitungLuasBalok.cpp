#include <iostream>
using namespace std;

int main(){
    // Deklarasi panjang, lebar, dan tinggi
    int p,l,t, hasil;

    // masukkan nilai panjang
    cout << "Masukkan panjang: ";
    cin >> p;

    // masukkan nilai lebar
    cout << "Masukkan lebar: ";
    cin >> l;

    // masukkan nilai tinggi
    cout << "Masukkan tinggi: ";
    cin >> t;

    hasil = p * l * t;

    cout << "Luas Balok adalah : " << hasil << endl;

    return 0;
}