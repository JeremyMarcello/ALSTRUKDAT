#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int hurufVokal(const string& str) {
    int jumlah = 0;
    for(char huruf : str) {
        if (huruf == 'a' || huruf == 'e' || huruf == 'i' || huruf == 'o' || huruf == 'u') {
            jumlah++; // Jika huruf adalah vokal, tambahkan ke hitungan
        }
    }
    return jumlah;
}

void printHasil(string str, int jumlah){ // fungsi untuk print kalimat dan hasilnya

    cout << "Kalimat anda : " << str << endl;
    cout << "Jumlah huruf volak adalah : " << jumlah << endl;
}

int main() {
    string str;
    while(true){
            cout << "Masukkan kalimat: ";
            getline(cin, str);
            transform(str.begin(), str.end(), str.begin(), ::tolower); // menggunakan fungsi transform untuk mengecilkan huruf

            if (str.empty()) { // menggunakan fungsi str.emtpy untuk cek apakah variable str ada isi atau tidak
                cout << "Kalimat kosong.";
            } else {
                break;
            }
        }
    printHasil(str, hurufVokal(str)); // menggunakan fungsi printHasil() ntuk print hasil
    return 0;
}
