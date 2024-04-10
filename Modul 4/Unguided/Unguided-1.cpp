#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int binarysearch(const string& str, char huruf) { // algoritma binary search untuk mencari huruf
    int awal, akhir, tengah;
    awal = 0;
    akhir = str.length() - 1; // fungsi .length untuk mencari panjang dari str
    while (awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if(str[tengah] == huruf) { // jika benar maka akan langsung return nilai tengah
            return tengah;
        } else if(str[tengah] < huruf) // jika salah dan lebih kecil maka akan mencari ke bagian kiri dari nilai tengah
            awal = tengah + 1;
        else // jika salah dan lebih besar maka akan mencari ke bagian kanan dari nilai
            akhir = tengah - 1;
    }
    return -1;
}

void printHasil(string str, int hasil, char huruf){ // fungsi untuk print kalimat serta hasilnya
    cout << "Kalimat anda : " << str << endl;
    if (hasil != -1) {
        cout << "Huruf '" << huruf << "' ditemukan pada indeks ke-" << hasil + 1 << "." << endl;
    } else {
        cout << huruf << " tidak ditemukan pada kalimat." << endl;
    }
}

int main() {
    // deklarasi lokal variable
    string str;
    char huruf;
    int hasil;

    // inputan kalimat dari user
    while(true){
        cout << "Masukkan kalimat: ";
        getline(cin, str);
        transform(str.begin(), str.end(), str.begin(), ::tolower); // menggunakan fungsi transform untuk mengecilkan huruf

        if (str.empty()) { // menggunakan fungsi str.emtpy untuk cek apakah variable str ada isi atau tidak
            cout << "Kalimat kosong.";
        } else {
            cout << "Masukkan huruf yang dicari: ";
            cin >> huruf;
            hasil = binarysearch(str, huruf); // menggunakan fungsi binarysearch() untuk mencari huruf
            break;
        }
    }
    printHasil(str, hasil, huruf); // fungsi untuk print hasil
    return 0;
}