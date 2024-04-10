# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">2311110003 / Jeremy Marcello Waani / Sains Data</p>

## Dasar Teori
Pencarian data yang sering juga disebut dengan table lookup atau storage and retrieval information, adalah suatu proses untuk mengumpulkan sejumlah informasi didalam pengingat computer dan kemudian mencari kembali informasi yang diperlukan secepat mungkin[1].

### 1. Sequential Search
Sequential Search (pencarian berurutan) dikenal juga sebagai pencarian linier. Sequential Search merupakan algoritma pencarian paling dasar dan paling sederhana yang bekerja menggunakan pendekatan brute force, mencoba segala kemungkinan yang ada hingga target yang diinginkan ditemukan[2].

### 2. Selection Sort
Algoritma Binary Search bekerja dengan menggunakan pendekatan devide and conquer pada data array yang sudah terurut (sorted), artinya algoritma Binary Search diawali dengan mengurutkan (sorting) array terlebih dahulu sebelum melakukan proses pencarian[2].

## Guided 

### 1. [Sequential Search]

```C++
#include <iostream>
using namespace std;

int main ()
{
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    // algoritma Sequential search
    for (i = 0; i < n; i++) 
    {
        if(data[i] == cari) 
        {
            ketemu = true;
            break;
        }
    }


    cout << "\t Program Sequential Search Sedeerhana\n" << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

    if (ketemu)
    {
        cout << "\n angka "<< cari << " ditemukan pada indeks ke- " << i << endl;
    }
    else
    {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}
```

#### Output
![Screenshot 2024-04-09 183040](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/3854879e-cf96-43e2-bbfe-de8dd28802f7)

Output diatas adalah pencarian nilai 10 dalam data yang sudah ditentukan dengan menggunakan sequential search,dengan menggunakan perulangan sebanyak data lalu menggunakan fungsi if untuk cek apakah nilai pada index sekarang sama dengan nilai yang dicari.



### 2. [Binary Search]

```C++
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int cari;

void selection_sort(int data[], int length) {
    int temp, min, i, j; 
    for(i = 0; i < length; i++) {
        min = i;
        for (j = i + 1; j < length; j++) {
            if(data[j] < data[min]) {
                min = j;
            }
        }
        temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
}

void binarysearch(int data[], int length) {
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = length - 1;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if(data[tengah] == cari) {
            b_flag = 1;
            break;
        } else if(data[tengah] < cari)
            awal = tengah + 1;
        else
            akhir = tengah - 1;
    }
    if(b_flag == 1)
        cout << "\n Data ditemukan pada index ke- " << tengah << endl;
    else
        cout << "\n Data tidak ditemukan\n";
}

int main() {
    int data[7] = {1, 8, 2, 5, 4, 9, 7};
    int length = sizeof(data) / sizeof(data[0]);

    cout << "\t BINARY SEARCH " << endl;
    cout << "\n Data : ";
    // Tampilkan data awal
    for(int x = 0; x < length; x++)
        cout << setw(3) << data[x];
    cout << endl;

    cout << "\n Masukkan data yang ingin anda cari : ";
    cin >> cari;

    cout << "\n Data diurutkan : ";
    // Urutkan data dengan selection sort
    selection_sort(data, length);

    // Tampilkan data setelah diurutkan 
    for(int x = 0; x < length; x++)
        cout << setw(3) << data[x];
    cout << endl;

    binarysearch(data, length);
    _getche();
    return EXIT_SUCCESS;
}
```

#### Output
![Screenshot 2024-04-09 183339](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/04926d99-dcf1-43c3-87d5-c8a9d10f15a2)

Output diatas adalah pencarian nilai yang kita inginkan didalam data yang sudah ditentukan menggunakan sequential search. Proses awal adalah menentukan nilai awal, akhir, dan tengah jika sudah makan kita dapat membandingkan nilai yang dicari dengan nilai tengah, jika benar maka nilai ditemukan dan jika salah akan mencari lagi kekanan ataupun kekiri.

## Unguided 

### 1. [Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!]

```C++
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
        else // jika salah dan lebih besar maka akan mencari ke bagian kanan dari nilai tengah
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
```
#### Output:
![Screenshot 2024-04-10 165403](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/609f21d8-0510-4cb7-959a-11cbae5b7392)

Output diatas adalah pencarian huruf yang dinginkan user dari kalimat yang diinput oleh user juga dengan menggunakan sequential search. Kemudian setelah user memasukkan kalimat, kita akan membuat semuanya menjadi huruf kecil agar dapat dengan mudah dibandingkan. Setelah itu membandingkan huruf dengan huruf pada kalimat satu per satu.

### 2. [Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!]

```C++
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
```
#### Output:
![Screenshot 2024-04-10 062016](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/35d2eb1d-56e0-461d-ac70-00675f82604c)

Output diatas adalah pencarian jumlah huruf vokal yang user inginkan dari kalimat yang diinput user dengan menggunakan sequential search. Pertama kita ubah kalimat menjadi huruf kecil semua lalu dibandingkan satu persatu dengan kelima huruf vokal, jika sama maka jumlah + 1 untuk menghitung berapa jumlahnya.

### 3. [Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!]

```C++
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
```
#### Output:
![Screenshot 2024-04-10 143028](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/42bfc9bf-8f2b-44c9-9670-a379c3d63cea)

Output diatas adalah pencarian jumlah angka yang ada dalam data array yang diinput oleh user dengan menggunakan sequential search. Pertama user memasukkan data array lalu memasukkan angka yang ingin dihitung jumlahnya, kemudian akan dilakukan sequential search yang jika benar variable jumlah akan ditambah 1 untuk menghitung jumlah angka yang ada.

## Kesimpulan
Searching adalah proses untuk mencari nilai dalam data dengan kriteria tertentu. Dua jenis algoritma searching diatas merupakan salah dua dari banyaknya algoritma yang ada. Sequential search sangat cocok untuk data yang tidak terurut dan tidak besar, sedangkan binary search sangat cocok untuk data besar dan terurut.

## Referensi
[1] Wanra Tarigan. Algoritma Pemrograman dan Struktur Data. Jawa Tengah: Aeureka Media Aksara. 2022

[2] Meidyan Permata Putri, et al., *Algoritma dan Struktur Data, Bandung* : Widina Bhakti Persada Bandung, 2022.
