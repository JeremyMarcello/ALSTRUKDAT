#include <iostream>
using namespace std;

int sequentialsearch(float angka[], int banyakData, int angkaDicari) { // algotitma sequential search yang digunakan untuk mencari
    int jumlah = 0;
    for (int i = 0; i < banyakData; ++i) {
        if (angka[i] == angkaDicari) {
            jumlah++;
        }
    }
    return jumlah;
}

void printArray(float angka[], int banyakData) { // fungsi ini digunakan untuk menampilkan array yang diinput user
    for(int i=0; i<banyakData; i++) {
        cout << angka[i] << " ";
    }
    cout << endl;
}

void printHasil(float angka[], int jumlah, int banyakData){ // fungsi untuk print array inputan dan hasilnya
    cout << "Angka anda : ";
    printArray(angka, banyakData);
    cout << "Jumlah angka yang anda cari adalah : " << jumlah << endl;
}

int main(){
    // deklarasi lokal variable 
    int hasil, banyakData, print, angkaDicari;
    float *angka = new float[banyakData];
    cout << "Masukkan banyak angka : ";
    cin >> banyakData;

    for(int i=0; i<banyakData; i++) { // untuk memasukkan angka sebanyak yang user mau
        cout << "Masukkan angka ke- " << i+1 << " :" << endl;       
        cin >> angka[i];
    }
    cout << "Angka yang ingin dicari : " << endl;
    cin >> angkaDicari;
    hasil = sequentialsearch(angka, banyakData, angkaDicari);
    printHasil(angka, hasil, banyakData);
    return 0;
}
