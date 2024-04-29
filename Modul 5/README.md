# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">2311110003 / Jeremy Marcello Waani / Sains Data</p>

## Dasar Teori
Struktur adalah tipe data komposit yang mengumpulkan berbagai tipe data menjadi satu kesatuan . Struktur digunakan untuk merepresentasikan data yang berkaitan sebagai satu kesatuan [1]. Struktur dapat berisi variabel, fungsi, dan bahkan struktur lain.

### 1. Variabel
Variabel dalam struktur digunakan untuk menyimpan nilai-nilai data anggota struktur. Setiap anggota struktur memiliki tipe data dan nama. Variabel dalam struktur disebut anggota struktur [2].

### 2. Selection Sort
Struktur dapat berisi struktur lain. Misalnya struktur Alamat menjadi bagian dari struktur Peserta. Struktur digunakan untuk merepresentasikan bagian-bagian data yang saling berhubungan [3].

## Guided 

### 1. [Guided 1]

```C++
#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku = "The Alpha Girl's Guide";
    favorit.pengarang = "Henry Manampiring";
    favorit.penerbit = "Gagas Media";
    favorit.tebalHalaman = 253;
    favorit.hargaBuku = 79000;

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    cout << "\tJudul Buku : " << favorit.judulBuku << endl;
    cout << "\tPengarang : " << favorit.pengarang << endl;
    cout << "\tPenerbit : " << favorit.penerbit << endl;
    cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;
 
    return 0;
}
```

#### Output
![Screenshot 2024-04-29 052200](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/298e6510-f28c-46a8-86f0-2f529447d721)

Pada kode diatas, kita mendeklarasikan struct bernama buku yang berisi variabel, yaitu: judulBuku, pengarang, penerbit, tebalHalaman, hargaBuku. Kemudian dalam `int main()` kita deklarasikan struct buku tadi menjadi favorit. Lalu kita masukkan data kedalam variabel yang berada dalam struct dengan menggunakan deklarasi favorite tadi, contohnya `favorit.judulBuku = "The Alpha Girl's Guide";` untuk memasukkan data kedalam variabel judulBuku. Setelah memasukkan data kedalam struct kita gunakan cout untuk menampilkan data yang tadi kita masukkan, contohnya `cout << "\tJudul Buku : " << favorit.judulBuku << endl;` untuk menampilkan data dalam variabel judulBuku.



### 2. [Guided 2]

```C++
#include <iostream>
using namespace std;

struct hewan {
    string namaHewan;
    string jenisKelamin;
    string caraBerkembangbiak;
    string alatPernafasan;
    string tempatHidup;
    bool Karnivora;
};

struct hewanDarat {
    int jumlahKaki;
    bool menyusui;
    string suara;
};

struct hewanLaut {
    string bentukSirip;
    string bentukPertahananDiri;
};

int main() {
    hewanDarat kelinci; // Menggunakan tipe data hewanDarat untuk kelinci
    kelinci.jumlahKaki = 4;
    kelinci.menyusui = true;
    kelinci.suara = "Citcit";

    hewanLaut ikan; // Menggunakan tipe data hewanLaut untuk ikan
    ikan.bentukSirip = "Sirip ekor";
    ikan.bentukPertahananDiri = "Sisik";

    hewan serigala; // Tetap menggunakan tipe data hewan untuk serigala
    serigala.namaHewan = "Serigala";
    serigala.jenisKelamin = "Jantan";
    serigala.caraBerkembangbiak = "Melahirkan";
    serigala.alatPernafasan = "Paru-paru";
    serigala.tempatHidup = "Hutan terbuka";
    serigala.Karnivora = true;

    cout << "\t\tHewan" << endl;
    cout << "\t" << serigala.namaHewan << endl;
    cout << "\tJenis kelamin : " << serigala.jenisKelamin << endl;
    cout << "\tCara berkembangbiak : " << serigala.caraBerkembangbiak << endl;
    cout << "\tAlat pernafasan : " << serigala.alatPernafasan << endl;
    cout << "\tTempat hidup : " << serigala.tempatHidup << endl;
    cout << "\tKarnivora : " << (serigala.Karnivora ? "Yes" : "No") << endl << endl;

    cout << "\t\tHewan Darat" << endl;
    cout << "\tKelinci" << endl;
    cout << "\tJumlah kaki : " << kelinci.jumlahKaki << endl;
    cout << "\tMenyusui : " << (kelinci.menyusui ? "Yes" : "No") << endl;
    cout << "\tSuara : " << kelinci.suara << endl << endl;

    cout << "\t\tHewan Laut" << endl;
    cout << "\tIkan" << endl;
    cout << "\tBentuk sirip : " << ikan.bentukSirip << endl;
    cout << "\tBentuk pertahanan diri: " << ikan.bentukPertahananDiri << endl;

    return 0;
}
```

#### Output
![Screenshot 2024-04-29 052414](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/8813562c-b8d3-4221-898d-5223b4e88a3f)

Pada kode diatas, kita mendeklarasikan 3 struct, yaitu: hewan, hewanLaut, hewanDarat. `Struct hewan` berisi variabel namaHewan, jenisKelamin, caraBerkembangbiak, alatPernafasan, tempatHidup, Karnivora. `Stuct hewanDarat` berisi variabel jumlahKaki, menyusui, suara. `Struct hewanLaut`  berisi variabel bentukSirip, bentukPertahananDiri. Dalam `int main()` kita mendeklarasikan `struct hewanDarat` sebagai kelinci kemudian memasukkan data kedalam variabel yang ada didalam struct dengan cara menggunakan deklarasi kelinci tadi ditambahkan `.` dan diikuti oleh nama variabel yang ada didalam struct tersebut. kita lakukan juga hal yang sama seperti `struct hewanDarat` kepada `struct hewanLaut` dan `struct hewan`. Setelah memasukkan data kedalam struct kita dapat menampilkannya dengan menggunakan `cout` dilanjutkan dengan deklarasi struct yang sudah kita buat dan `.` nama variabel yang ingin ditampilkan, contohnya `cout << "\tKarnivora : " << (Karnivora ? "Yes" : "No") << endl << endl;` yang dimana kode tersebut menampilkan apakah serigala karnivora atau tidak dengan cek nilai data yang ada dalam struct true atau false menggunakan ternary operator.



## Kesimpulan
Struktur merupakan alat yang penting dalam pemrograman untuk merepresentasikan data yang saling terkait dengan cara yang terorganisir dan efisien. Penggunaan struktur dapat meningkatkan keterbacaan kode, memudahkan manipulasi data, dan menghemat memori.



## Referensi
[1] M. Fitriani, M. Syaifullah, and M. B. Triyono, "Penerapan Struktur Data dan Algoritma Dasar pada Sistem Informasi Perpustakaan Berbasis Web," Jurnal Pendidikan Teknologi Dan Kejuruan, vol. 26, no. 2, pp. 156-163, 2020.

[2] Y. Riyanto, R. Novilia, and S. P. Kharisma, "Implementasi Struktur Data Arrays Dan Struct Pada Pembuatan Program Perhitungan Gaji Pegawai," Jurnal Basis, vol. 5, no. 2, pp. 102-111, 2019.

[3] Zulvia, F. Munawaroh, and R. Husna, "Perancangan Sistem Informasi Akuntansi Toko Menggunakan Struktur Data Struct Dalam Bahasa Pemrograman C++," Jurnal Ilmiah Teknologi Dan Informasi, vol. 12, no. 2, pp. 176-186, 2017.