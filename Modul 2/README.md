# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">2311110003 / Jeremy Marcello Waani / Sains Data</p>

## Dasar Teori
Array adalah sekumpulan nilai-nilai data yang sama, yang terurut dan dikelompokkan berdasarkan nama yang sama. Elemen-elemen array disebut dengan subscript atau indeks. Pendeklarasian array akan membuat kompiler mengalokasikan memori yang cukup untuk menampung semua elemen sesuai dengan yang dideklarasikan. Array dibedakan menjadi tiga macam: array satu dimensi, array dua dimensi, dan array berdimensi banyak[1].


### Array 1 Dimensi
Array satu dimensi adalah kumpulan elemen-elemen identik yang tersusun dalam satu baris, tetapi isi dari elemen tersebut boleh berbeda.Array satu dimensi adalah struktur data yang terdiri dari sejumlah elemen yang disusun dalam satu baris atau satu dimensi. Setiap elemen dalam array memiliki indeks yang unik, yang digunakan untuk mengakses atau memanipulasi nilai tersebut. Array satu dimensi juga dikenal sebagai vektor[2].

### Array 2 Dimensi

Array dua dimensi yang sering digambarkan sebagai sebuah matriks merupakan perluasan dari sebuah array satu dimensi. Jika array satu dimensi hanya terdiri dari sebuah baris dengan beberapa kolom elemen maka array dua dimensi terdiri dari beberapa baris dan beberapa kolom elemen yang bertipe sama[3].

### Array Multidimensi
Array multidimensi merupakan array yang mempunyai ukuran lebih dari dua. Bentuk pendeklarasian array multidimensi sama saja dengan deklarasi array dimensi satu maupun dimensi dua[4].

## Guided 

### 1. [Array Tiga Dimensi]

```C++
#include <iostream>
using namespace std;

int main(){
    // Deklarasi array
    int arr[2][3][3];

    // input elemen
    for (int x = 0; x < 2; x++){
        for ( int y = 0; y < 3; y++){
            for ( int z = 0; z < 3; z++){
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;    
    }
    // Output Array
    for (int x = 0; x < 2; x++){
        for (int y = 0; y < 3; y++){
            for (int z = 0; z < 3; z++){
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    // Tampilan array 
    for (int x = 0; x < 2; x++){
        for (int y = 0; y < 3; y++){
            for (int z = 0; z < 3; z++){
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
Kode diatas dapat digunakan untuk membuat array 3 dimensi dengan ukuran 3x3 yang berjumlah 2 buah, kemudian nilai dari arraynya diinput oleh user.

### 2. [Mencari Nilai Maksimal pada Array]

```C++
#include <iostream>
using namespace std;

int main(){
    int maks, a, i = 1, lokasi;
    cout << "Masukkan panjang array : ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i ++){
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i ++){
        if (array[i] > maks){
            lokasi = i;
            maks = array[i];
        }
    }
    cout << "Nilai maksimal adalah " << maks << " berada di Array ke " << lokasi << endl;
}
```
Kode diatas digunakan untuk mengetahui letak nilai tebesar dalam suatu array yang diinputkan oleh user.


## Unguided 

### 1. [Buatlah program untuk menampilkan output seperti berikut dengan data yang telah diinput oleh user!]

```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers;
    int num;
    char choice;

    do {
        cout << "Masukkan sebuah bilangan: ";
        cin >> num;
        numbers.push_back(num);

        cout << "Tambah bilangan lagi? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    vector<int> even_numbers;
    vector<int> odd_numbers;

    for (int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] % 2 == 0) {
            even_numbers.push_back(numbers[i]);
        } else {
            odd_numbers.push_back(numbers[i]);
        }
    }

    cout << "Bilangan genap: ";
    for (int i = 0; i < even_numbers.size(); ++i) {
        cout << even_numbers[i] << " ";
    }
    cout << endl;

    cout << "Bilangan ganjil: ";
    for (int i = 0; i < odd_numbers.size(); ++i) {
        cout << odd_numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
```
#### Output:
![Screenshot 2024-03-25 130714](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/d6fbfb64-2659-4851-a829-909f1d3a1e74)

Kode diatas adalah program sederhana yang meminta pengguna untuk memasukkan beberapa angka. Kemudian, program akan memisahkan angka-angka tersebut menjadi dua kelompok, yaitu angka genap dan angka ganjil, dan kemudian menampilkan masing-masing kelompok secara terpisah.


### 2. [Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!]

```C++
#include <iostream>
using namespace std;

int main(){
    int a, b, c;

    cout << "Masukkan ukuran array tiga dimensi:" << endl;
    cout << "Ukuran dimensi 1: ";
    cin >> a;
    cout << "Ukuran dimensi 2: ";
    cin >> b;
    cout << "Ukuran dimensi 3: ";
    cin >> c;

    // Deklarasi array dengan ukuran yang diinputkan
    int arr[a][b][c];

    // input elemen
    for (int x = 0; x < a; x++){
        for ( int y = 0; y < b; y++){
            for ( int z = 0; z < c; z++){
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;    
    }
    // Output Array
    for (int x = 0; x < a; x++){
        for (int y = 0; y < b; y++){
            for (int z = 0; z < c; z++){
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    // Tampilan array 
    for (int x = 0; x < a; x++){
        for (int y = 0; y < b; y++){
            for (int z = 0; z < c; z++){
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }

}
```
#### Output:
![Screenshot 2024-03-25 130600](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/456c4c47-10d6-4a7e-a0fe-4d056300f1cf)

Kode diatas meminta pengguna untuk memasukkan ukuran dari sebuah array tiga dimensi, yang akan membuat array tiga dimensi dengan ukuran yang dimasukkan. Setelah ukuran dimasukkan, program meminta pengguna untuk memasukkan nilai untuk setiap elemen array, dan setelah semua nilai dimasukkan, program akan menampilkan nilai dari setiap elemen array secara berurutan sesuai dengan induksi.


### 3. [Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!]

```C++
#include <iostream>
using namespace std;

int main(){
    int a, b, c;

    cout << "Masukkan ukuran array tiga dimensi:" << endl;
    cout << "Ukuran dimensi 1: ";
    cin >> a;
    cout << "Ukuran dimensi 2: ";
    cin >> b;
    cout << "Ukuran dimensi 3: ";
    cin >> c;

    // Deklarasi array dengan ukuran yang diinputkan
    int arr[a][b][c];

    // input elemen
    for (int x = 0; x < a; x++){
        for ( int y = 0; y < b; y++){
            for ( int z = 0; z < c; z++){
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;    
    }
    // Output Array
    for (int x = 0; x < a; x++){
        for (int y = 0; y < b; y++){
            for (int z = 0; z < c; z++){
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    // Tampilan array 
    for (int x = 0; x < a; x++){
        for (int y = 0; y < b; y++){
            for (int z = 0; z < c; z++){
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }

    int minimum = INT_MAX;
    int maximum = INT_MIN;
    int sum = 0;
    int total_elements = a * b * c;

    for (int x = 0; x < a; x++) {
        for (int y = 0; y < b; y++) {
            for (int z = 0; z < c; z++) {
                int current = arr[x][y][z];
                if (current < minimum) {
                    minimum = current;
                }
                if (current > maximum) {
                    maximum = current;
                }
                sum += current;
            }
        }
    }

    double average = static_cast<double>(sum) / total_elements;

    cout << "Nilai Minimum: " << minimum << endl;
    cout << "Nilai Maksimum: " << maximum << endl;
    cout << "Rata-rata: " << average << endl;

    return 0;
}
```
#### Output:
![Screenshot 2024-03-25 131314](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/d4a3e9fd-bf4f-44e5-be72-a32e04c06cdf)

kode diatas memungkinkan Anda membuat array tiga dimensi dengan ukuran yang diinginkan. Setelah Anda memasukkan ukuran array, program akan meminta Anda untuk memasukkan nilai untuk setiap elemen array. Setelah itu, program akan menampilkan nilai dari setiap elemen array, serta nilai minimum, maksimum, dan rata-rata dari seluruh array. Ini membantu Anda memahami cara mengelola dan mengantri array.

## Kesimpulan
Array adalah struktur data dalam pemrograman yang memungkinkan kumpulan nilai data yang sama disimpan dan diakses melalui indeks. Array satu dimensi, dua dimensi, dan multidimensi adalah tiga kategori yang tersedia. Array memiliki beberapa keuntungan, seperti kemudahan akses acak dan kemampuan penyimpanan nilai independen yang efisien. Namun, kekurangan termasuk kebutuhan untuk bertipe homogen dan kesulitan mengubah ukuran array statis selama proses eksekusi. Karena kemampuan untuk menyimpan dan mengakses data secara terstruktur, array tetap menjadi salah satu struktur data yang paling efektif dalam banyak kasus pemrograman.

## Referensi
[1] Syaiful Anam, Indah Yanti, Zuraidah Fitriah, Ummu Habibah. *Cara Mudah Belajar Bahasa Pemrograman C++*. Malang: Universitas Brawijaya Press. 2021.

[2] Thompson Susabda Ngoen, *Pengantar Algoritma dengan Bahasa C*. Jakarta: Salemba Teknika, 2020.

[3] Meidyan Permata Putri, et al., *Allgoritma dan Struktur Data*. Bandung: Widina Bhakti Persada Bandung, 2022.

[4] Rina Firliana, Patmi Kasih. *Algoritma & Pemrograman C++*. Nganjuk: Adjie Media Nusantara. 2018.