# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>


<p align="center">Jeremy Marcello Waani / 2311110003 / S1SD04-A</p>

## Dasar Teori

**Pengertian Fungsi Rekursif**

Fungsi rekursif adalah fungsi yang didefinisikan dengan cara memanggil dirinya sendiri [1]. Hal ini memungkinkan fungsi tersebut untuk diulang secara berulang kali untuk menyelesaikan suatu masalah. Fungsi rekursif memiliki dua komponen utama:

* **Kasus Dasar:** Merupakan kondisi yang menandakan bahwa proses rekursi harus dihentikan [1].
* **Kasus Rekursif:** Merupakan pemanggilan fungsi rekursif itu sendiri dengan parameter yang berbeda [1].
Cara Kerja Fungsi Rekursif

Fungsi rekursif bekerja dengan memecah masalah menjadi sub-masalah yang lebih kecil dan lebih mudah dipecahkan [1]. Sub-masalah ini kemudian dipecahkan dengan cara yang sama dengan masalah utama, yaitu dengan memanggil fungsi rekursif itu sendiri. Proses ini diulang hingga mencapai kasus dasar, di mana fungsi rekursif tidak lagi memanggil dirinya sendiri [1].

## Guided

### 1. Guided 1
```C++
#include <iostream>;
using namespace std;

int faktorial(int angka){
    if (angka <= 1){
        return 1;
    }
    return angka * faktorial(angka-1);
}

int main(){
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;
    cout << "Faktorial dari " << angka << " adalah " << faktorial(angka) << endl;
    return 0;
}
```

**Output:**
![10G1](https://github.com/JeremyMarcello/Assignment-Praktikum-Algoritma-dan-Struktur-Data/assets/156126843/1a5bfba5-80ae-49f7-b380-ef72d13c6f21)

**Kode yang diberikan mengimplementasikan fungsi rekursif untuk menghitung faktorial dari suatu bilangan.**

**Fungsi:**

faktorial(angka):
* Merupakan fungsi rekursif yang menerima parameter angka (integer).
* Jika angka lebih kecil dari atau sama dengan 1, maka fungsi mengembalikan nilai 1.
* Jika tidak, fungsi mengembalikan hasil perkalian angka dengan nilai faktorial dari angka-1.

**Fungsi Utama (main):**

* Meminta pengguna untuk memasukkan bilangan (integer) melalui konsol.
* Menyimpan bilangan yang dimasukkan ke dalam variabel angka.
* Memanggil fungsi faktorial(angka) untuk menghitung faktorial dari bilangan yang dimasukkan.
* Menampilkan hasil perhitungan faktorial ke konsol.

**Penjelasan:**

Fungsi faktorial(angka) menggunakan teknik rekursif untuk menghitung faktorial suatu bilangan. Rekursif adalah teknik pemrograman di mana sebuah fungsi memanggil dirinya sendiri. Dalam kasus ini, fungsi faktorial(angka) memanggil dirinya sendiri dengan parameter angka-1 untuk menghitung faktorial dari bilangan yang lebih kecil. Hasil dari pemanggilan rekursif ini kemudian dikalikan dengan angka dan dikembalikan sebagai hasil faktorial.

**Kesimpulan:**

Kode ini menunjukkan cara menghitung faktorial suatu bilangan menggunakan fungsi rekursif. Fungsi rekursif dapat digunakan untuk menyelesaikan berbagai masalah pemrograman, terutama yang melibatkan struktur data bertingkat seperti pohon atau grafik.

### 2. Guided 2
```C++
#include <iostream>;
using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1); // Panggilan rekursif tidak langsung
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2); // Panggilan rekursif tidak langsung
    }
}

int main() {
    int num = 5;
    cout << "Rekursif Tidak Langsung: ";
    functionA(num);
    return 0;
}
```

**Output:**
![10G2](https://github.com/JeremyMarcello/Assignment-Praktikum-Algoritma-dan-Struktur-Data/assets/156126843/cde91b57-cd1a-4c63-89c7-1b967c06c269)

**Kode yang diberikan menunjukkan contoh rekursif tidak langsung.**

**Fungsi:**

* **functionA(n):**
    * Menerima parameter n (integer).
    * Jika n lebih besar dari 0, maka:
        * Mencetak nilai n ke konsol.
        * Memanggil fungsi functionB dengan parameter n-1.
* functionB(n):
    * Menerima parameter n (integer).
    * Jika n lebih besar dari 0, maka:
        * Mencetak nilai n ke konsol.
        * Memanggil fungsi functionA dengan parameter n/2.

**Fungsi Utama (main):**

* Mendefinisikan variabel num dan menginisialisasinya dengan nilai 5.
* Mencetak "Rekursif Tidak Langsung: " ke konsol.
* Memanggil fungsi functionA(num) dengan parameter num (yaitu 5).

**Penjelasan:**

Dalam kode ini, fungsi functionA dan functionB saling memanggil satu sama lain secara tidak langsung.

* functionA memanggil functionB dengan parameter n-1.
* functionB memanggil functionA dengan parameter n/2.

Dengan kata lain, functionA memanggil functionB untuk mencetak nilai n dan n-1, kemudian functionB memanggil functionA untuk mencetak nilai n/2 dan n/4. Proses ini berlanjut hingga n menjadi 0.

**Kesimpulan:**

Kode ini menunjukkan contoh rekursif tidak langsung, di mana dua fungsi saling memanggil satu sama lain secara tidak langsung. Rekursif tidak langsung dapat digunakan untuk menyelesaikan berbagai masalah pemrograman, terutama yang melibatkan struktur data bertingkat seperti pohon atau grafik.

## Unguided

### 1. Unguided 1

```C++
#include <iostream>;
using namespace std;

int faktorial(int angka){
    if (angka <= 1){
        return 1;
    }
    return angka * faktorial(angka-1);
}

int main(){
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;
    cout << "Faktorial dari " << angka << " adalah " << faktorial(angka) << endl;
    return 0;
}
```

#### Output:
![10U1](https://github.com/JeremyMarcello/Assignment-Praktikum-Algoritma-dan-Struktur-Data/assets/156126843/ca12a74e-238e-462a-8096-77134612a2d4)

**Kode yang diberikan mengimplementasikan fungsi iteratif untuk menghitung faktorial dari suatu bilangan.**

**Fungsi:**

*  faktorial(angka):
    * Menerima parameter angka (integer).
    * Mendefinisikan variabel hasil dan menginisialisasinya dengan nilai 1.
    * Melakukan loop for dari 2 hingga angka.
    * Di dalam loop, hasil dikalikan dengan nilai i.
    * Mengembalikan nilai hasil setelah loop selesai.

**Fungsi Utama (main):**

* Meminta pengguna untuk memasukkan bilangan (integer) melalui konsol.
* Menyimpan bilangan yang dimasukkan ke dalam variabel angka.
* Memanggil fungsi faktorial(angka) untuk menghitung faktorial dari bilangan yang dimasukkan.
* Menampilkan hasil perhitungan faktorial ke konsol.

**Penjelasan:**

Fungsi faktorial(angka) menggunakan teknik iteratif untuk menghitung faktorial suatu bilangan. Iteratif adalah teknik pemrograman di mana sebuah fungsi menyelesaikan perhitungan dengan melakukan langkah-langkah berulang. Dalam kasus ini, fungsi faktorial(angka) melakukan loop dari 2 hingga angka dan mengalikan nilai hasil dengan nilai i di setiap iterasi.

**Kesimpulan:**

Kode ini menunjukkan cara menghitung faktorial suatu bilangan menggunakan fungsi iteratif. Fungsi iteratif dapat menjadi alternatif yang lebih efisien untuk menghitung faktorial bilangan besar dibandingkan dengan fungsi rekursif.

### 2. Unguided 2

```C++
#include <iostream>;
using namespace std;

int faktorialA(int angka);
int faktorialB(int angka);

int faktorialA(int angka){
    if (angka <= 1){
        return 1;
    }
    return angka * faktorialB(angka-1);
}

int faktorialB(int angka){
    if (angka <= 1){
        return 1;
    }
    return angka * faktorialA(angka-1);
}

int main(){
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;
    cout << "Faktorial dari " << angka << " adalah " << faktorialA(angka) << endl;
    return 0;
}
```

#### Output:
![10U2](https://github.com/JeremyMarcello/Assignment-Praktikum-Algoritma-dan-Struktur-Data/assets/156126843/42f3e864-8578-4beb-ae62-4ad6a3f7dca7)

**Kode yang diberikan mengimplementasikan fungsi rekursif timbal balik untuk menghitung faktorial dari suatu bilangan.**

**Fungsi:**

* faktorialA(angka) dan faktorialB(angka):
    * Kedua fungsi ini memiliki definisi yang sama.
    * Menerima parameter angka (integer).
    * Jika angka lebih kecil dari atau sama dengan 1, maka:
        * Mengembalikan nilai 1.
    * Jika tidak, maka:
        * Mengembalikan hasil perkalian angka dengan nilai faktorial dari angka-1.
        * Perbedaannya terletak pada fungsi mana yang dipanggil untuk menghitung nilai faktorial angka-1.
    * faktorialA(angka) memanggil faktorialB(angka-1).
    * faktorialB(angka) memanggil faktorialA(angka-1).

**Fungsi Utama (main):**

* Meminta pengguna untuk memasukkan bilangan (integer) melalui konsol.
* Menyimpan bilangan yang dimasukkan ke dalam variabel angka.
* Memanggil fungsi faktorial(angka) untuk menghitung faktorial dari bilangan yang dimasukkan.
* Menampilkan hasil perhitungan faktorial ke konsol.


**Penjelasan:**

Kode ini menggunakan dua fungsi rekursif timbal balik untuk menghitung faktorial. Rekursif timbal balik adalah jenis rekursif di mana dua fungsi saling memanggil satu sama lain untuk menyelesaikan suatu masalah. Dalam kasus ini, faktorialA(angka) dan faktorialB(angka) saling memanggil satu sama lain untuk menghitung faktorial dari angka-1.

**Kesimpulan:**

Kode ini menunjukkan cara menghitung faktorial suatu bilangan menggunakan fungsi rekursif timbal balik. Rekursif timbal balik dapat digunakan untuk menyelesaikan berbagai masalah pemrograman yang melibatkan struktur data bertingkat seperti pohon atau grafik.

## Kesimpulan
Fungsi rekursif adalah teknik pemrograman di mana sebuah fungsi memanggil dirinya sendiri untuk menyelesaikan suatu masalah. Fungsi rekursif dapat digunakan untuk menyelesaikan berbagai masalah, termasuk menghitung faktorial, deret Fibonacci, dan traversal pohon. Rekursif tidak langsung dan rekursif timbal balik merupakan dua jenis rekursif yang sering digunakan. 

## Referensi
[1] Akhmad Arief (2020)."Pemrograman Python: Dari Pemula Menjadi Mahir".