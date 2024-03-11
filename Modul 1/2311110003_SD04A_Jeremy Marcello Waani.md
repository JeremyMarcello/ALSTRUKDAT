# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">2311110003 / Jeremy Marcello Waani / Sains Data</p>

## Dasar Teori
Tipe data adalah adalah sebuah pengklasifikasian data berdasarkan jenis data
tersebut. Tipe data dibutuhkan agar kompiler dapat mengetahui bagaimana sebuah
data akan digunakan. Adapun tipe data yang akan dipelajari, sebagai berikut :
1. Tipe data Primitif
2. Tipe data Abstrak
3. Tipe data Koleksi

### Tipe Data Primitif

Tipe data primitif adalah tipe data dasar yang tersedia dalam suatu bahasa pemrograman. Mereka biasanya direpresentasikan langsung oleh bahasa itu sendiri dan tidak memerlukan pembuatan kelas atau objek khusus. Contoh tipe data primitif termasuk integer, floating point numbers, characters, dan boolean[1].


### Tipe Data Abstrak

Tipe data abstrak, atau yang sering disebut sebagai Abstrak Data Type (ADT), merupakan jenis data yang dibuat oleh programmer sesuai kebutuhan. Dalam tipe data abstrak, kita dapat menggabungkan beberapa jenis data, sehingga nilainya dapat terdiri dari lebih dari satu dan berbagai jenis data. Fitur Class merupakan salah satu fitur dari paradigma pemrograman berorientasi objek (OOP) dalam bahasa C++, yang mirip dengan fitur struktur data Struct dalam bahasa C. Keduanya berfungsi untuk mengelompokkan tipe data bersama-sama sebagai anggota dalam satu entitas.

### Tipe Data Kolesi

Tipe data koleksi, atau Collection Data Type, merupakan jenis data yang digunakan untuk mengelompokkan dan menyimpan beberapa nilai atau objek secara bersamaan. Dengan menggunakan tipe data koleksi, Anda dapat mengatur, mengelola, dan mengakses sejumlah besar data secara terstruktur. Beberapa jenis tipe data koleksi yang umum digunakan dalam pemrograman meliputi:

1. Array: Array adalah struktur data statis yang digunakan untuk menyimpan elemen-elemen dengan tipe data yang sama. Elemen-elemen tersebut dapat diakses menggunakan indeks, dan array memiliki ukuran tetap yang ditentukan saat deklarasi.

2. Vector: Vector adalah bagian dari Standard Template Library (STL) dalam bahasa C/C++, biasanya direpresentasikan dengan vector. Vector mirip dengan array namun memiliki kemampuan alokasi memori otomatis dan fleksibilitas dalam menambah atau mengurangi elemen. Fitur-fitur lainnya termasuk akses elemen, iterator, kapasitas, dan modifikasi.

3. Map: Map merupakan struktur data yang mirip dengan array namun menggunakan indeks yang dapat berupa tipe data selain integer. Indeks pada map disebut "key". Pada map, digunakan struktur pohon yang seimbang secara otomatis seperti Red-Black Tree untuk pengaturan data.

## Guided 

### 1. [Tipe Data Primitif]

```C++
#include <iostream>
using namespace std;

// Main program
int main(){
    char op;
    float num1, num2;

    // User dapat memasukkan Operator +, -, *, /
    cin >> op;

    // User dapat memasukkan num1 dan num2
    cin >> num1 >> num2;

    // switch statement
    switch  (op)
    
    {
    // Jika user memasukkan +
    case '+':
        cout << num1 + num2;
        break;
    // Jika user memasukkan -
    case '-':
        cout << num1 - num2;
        break;
    // Jika user memasukkan *
    case '*':
        cout << num1 * num2;
        break;
    // Jika user memasukkan /
    case '/':
        cout << num1 / num2;
        break;
        
    // Jika memasukkan operator selain yang diatas maka print error
    default:
        cout << "Error! Operator salah";
    }
    return 0;
}
```
Kode diatas digunakan untuk melakukan operasi dua bilangan menggunakan operator +, -, *, /. Kemudian switch case untuk melakukan operasi yang berbeda.

### 2. [Tipe Data Abstrak]

```C++
#include <stdio.h>

// struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};

int main(){
    // struct
    struct Mahasiswa mhs1, mhs2;
    
    // Memasukkan nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;

    // Print nilai struct
    printf("=== Mahasiswa 1 ===\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("=== Mahasiswa 2 ===\n");
    printf("Nama:  %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
}
```
Kode diatas membuat struct "Mahasiswa", kemudian struct "Mahasiswa" dijadikan objek menjadi "mhs1" dan "mhs2" agar kita dapat memasukkan nilai yang kita mau kedalamnya. kemudian printf untuk mencetak data dari masing-masing mahasiswa.

### 3. [Tipe Data Koleksi]

```C++
#include <iostream>
using namespace std;

int main(){
    //Deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    // Print nilai array
    cout << "Isi array pertama : " << nilai[0] << endl;
    cout << "Isi array kedua : " << nilai[1] << endl;
    cout << "Isi array ketiga : " << nilai[2] << endl;
    cout << "Isi array keempat : " << nilai[3] << endl;
    cout << "Isi array kelima : " << nilai[4] << endl;
    return 0;
}
```
Kode diatas membuat array dengan panjang 5, kemudian kita masukkan nilai kesetiap array yang ada. Setelah itu kita cetak setiap nilai dalam array dengan menggunakan cout.


## Unguided 

### 1. [Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!]

```C++
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
```
#### Output:
![Screenshot 2024-03-11 031957](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/85ef7c88-3062-44ef-adae-9e6af0842008)

Kode diatas digunakan untuk konversi rupiah ke dollar, digunakan tipe data double agar nilai dapat berupa bilangan desimal kemudian user input uang kedalam variabel "uang" lalu dioperasikan dengan "hasil = uang/15000", setelah operasi dilakukan kita cetak nilai yang sudah berada dalam variabel "hasil" untuk mengetahui berapa dollar konversi dari rupiah.

```C++
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
```
#### Output:
![Screenshot 2024-03-11 031905](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/686f939e-1609-42a5-b19d-9f8208770c90)

Kode diatas digunakan untuk menghitung luas bangun balok, dengan menggunakan tipe data integer setelah itu user memasukkan nilai tinggi, lebar, dan panjang. setelah user input dilakukan operasi "hasil = p * l * t" setelah didapatkan hasilnya kita print "hasil" dengan cout untuk mengetahui nilai dari luas bangun balok.

### 2. [Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya]

```C++
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
```
#### Output:
![Screenshot 2024-03-11 101004](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/0f48756c-f426-4c2a-8d1a-782967a20b5e)

Kode di atas adalah Sebuah class bernama "Data" didefinisikan dengan tiga atribut: nama, nim, dan umur. Kemudian, sebuah objek "d1" dibuat dari class "Data" dan nilai-nilai dimasukkan ke dalam atribut objek tersebut. Akhirnya, nilai-nilai tersebut dicetak menggunakan fungsi "cout". Class dalam pemrograman berfungsi sebagai blueprint untuk menciptakan objek. Ini menggabungkan variabel dan metode yang terkait ke dalam satu kesatuan, memungkinkan penyembunyian informasi, pewarisan sifat, dan polimorfisme. Class membantu dalam mengorganisir kode, meningkatkan keterbacaan dan pemeliharaan, serta memungkinkan penggunaan kembali dan fleksibilitas dalam pengembangan perangkat lunak.

```C++
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
```
#### Output:
![Screenshot 2024-03-11 103049](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/2040c693-2690-444e-aed8-0a1aa5eef8bf)

Kode diatas digunakan untuk menyimpan data sederhana tentang nama, nim, dan umur. Nilai-nilai tersebut dimasukkan ke dalam objek "data", yang kemudian dicetak ke layar. Dengan menggunakan struct, program dapat dengan mudah mengelola dan merepresentasikan data terkait dalam satu struktur yang ringkas. Struct dalam pemrograman adalah kumpulan data yang dikelompokkan bersama di bawah satu nama. Mirip dengan class, struct juga mendefinisikan tipe data dengan berbagai anggota, tetapi anggota-anggota dalam struct secara default bersifat publik, membuatnya cocok untuk menyimpan data terkait sederhana tanpa perilaku terkait. Ini membuat struct menjadi pilihan yang berguna untuk mengorganisir dan merepresentasikan data dalam program secara efisien.

### 3. [Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.]

```C++
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, string> Mahasiswa;
    Mahasiswa["Jeremy"] = "2311110003";
    Mahasiswa["Arif"] = "2311110017";
    Mahasiswa["Brian"] = "2311110052";

    // Mencetak NIM mahasiswa
    cout << "NIM Jeremy : " << Mahasiswa["Jeremy"] << endl;

    return 0;
}
```
#### Output:
![Screenshot 2024-03-11 121242](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/16314305-a3b7-4bad-b6a6-64429a0e8776)

Kode diatas menggunakan struktur data map untuk memetakan nama mahasiswa ke NIM). Tiga pasangan nama dan NIM dimasukkan ke dalam map, dan kemudian NIM dari mahasiswa dengan nama "Jeremy" dicetak. Ini menunjukkan cara penggunaan map untuk menyimpan data yang terkait satu sama lain, memungkinkan akses cepat ke nilai berdasarkan kunci tertentu, dalam hal ini, nama mahasiswa. Array adalah struktur data ayang menyimpan elemen-elemen dengan tipe data yang sama dalam urutan tertentu, diakses menggunakan indeks numerik, dan memiliki ukuran tetap. Sementara itu, map adalah struktur data asosiatif yang memetakan kunci unik ke nilai tertentu, memungkinkan penyimpanan dan akses data dengan cara yang lebih fleksibel dan dinamis daripada array, yang cocok digunakan ketika kita perlu menghubungkan nilai-nilai tertentu dengan kunci-kunci yang terkait.

## Kesimpulan
Program yang menggunakan tipe data primitif biasanya berkonsentrasi pada operasi sederhana dan langsung pada nilai-nilai tunggal, seperti integer, floating point, dan karakter; program seperti kalkulator sederhana melakukan operasi matematika dasar dengan mudah dan efisien.

Data dikelompokkan bersama dengan fungsi-fungsi yang beroperasi padanya melalui penggunaan struct dan class. Aksesibilitas default atribut dan metode dalam keduanya berbeda. Pada class, atribut dan metode secara default memiliki aksesibilitas private, sedangkan pada struct, atribut dan metode secara default memiliki aksesibilitas publik. Untuk ilustrasi, class Person dan struct Point digunakan untuk menampilkan objek dan koordinat.

Dua struktur data adalah array dan map. Array menyimpan elemen-elemen dengan indeks integer yang berurutan, sedangkan map menyimpan pasangan key-value dengan nilai unik untuk setiap tombol.

## Referensi
[1] Goodrich, Michael T., et al. "Data Structures & Algorithms in Java." John Wiley & Sons, 2014.