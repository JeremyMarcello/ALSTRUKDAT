# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">2311110003 / Jeremy Marcello Waani / Sains Data</p>

## Dasar Teori
#### 1. Pengertian Stact
Stack, atau tumpukan, adalah struktur data fundamental dalam ilmu komputer yang beroperasi dengan prinsip Last In, First Out (LIFO). Artinya, elemen terakhir yang dimasukkan ke dalam stack adalah yang pertama kali dikeluarkan. Stack sering dianalogikan dengan tumpukan piring, di mana piring terakhir yang diletakkan adalah yang pertama kali diambil.

#### 2. Operator Stack

Berikut adalah beberapa operator dasar yang umum digunakan dalam stack:

Push: Menambahkan elemen baru ke bagian atas stack. Contoh: `stack.push(x)` (di mana `x` adalah elemen yang ingin ditambahkan)[1].
Pop: Menghapus elemen terakhir dari stack dan mengembalikan nilainya. Contoh: `y = stack.pop()` (di mana `y` adalah variabel yang akan menyimpan nilai elemen yang dikeluarkan)[1].
Top: Mengembalikan nilai elemen teratas pada stack tanpa menghapusnya. Contoh: `z = stack.top()` (di mana `z` adalah variabel yang akan menyimpan nilai elemen teratas)[1].
Empty: Memeriksa apakah stack kosong atau tidak. Contoh: if `stack.empty(): print("Stack kosong")`[1].
Karakteristik Stack

#### 3. Stack Memiliki Beberapa Karakteristik Penting, yaitu:

LIFO: Elemen terakhir yang dimasukkan adalah yang pertama kali dikeluarkan.
Access: Elemen hanya dapat diakses dari atas stack.
Limited Access: Elemen di tengah stack tidak dapat diakses secara langsung.
Nested: Stack dapat ditumpuk satu sama lain untuk membentuk struktur data yang lebih kompleks.

#### 4. Kelebihan dan Kekurangan Stack

Stack memiliki beberapa kelebihan, yaitu:

Sederhana: Struktur dan operasinya mudah dipahami dan diimplementasikan.
Efisien: Operasi push, pop, dan top dapat dilakukan dengan waktu konstan (O(1)).
Serbaguna: Dapat digunakan untuk berbagai aplikasi, seperti manajemen memori, evaluasi ekspresi, dan pemrosesan bahasa.
Kekurangan Stack

Stack juga memiliki beberapa kekurangan, yaitu:

Akses Terbatas: Elemen di tengah stack tidak dapat diakses secara langsung.
Urutan Tetap: Elemen harus dikeluarkan dalam urutan LIFO.
Memori: Stack dapat menghabiskan banyak memori jika tidak dikelola dengan baik.

## Guided 

### 1. [Guided 1]

```C++
#include <iostream>
using namespace std;

const int maksimal = 5;
string arrayBuku[maksimal];
int top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top++] = data;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[--top] = "";
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else if (posisi <= top) {
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[top - posisi] << endl;
    } else {
        cout << "Posisi melebihi data yang ada" << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi <= top) {
        arrayBuku[top - posisi] = data;
    } else {
        cout << "Posisi melebihi data yang ada" << endl;
    }
}

void destroyArraybuku() {
    while (!isEmpty()) {
        popArrayBuku();
    }
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;

    cetakArrayBuku();

    return 0;
}
```

#### Output
![Screenshot 2024-05-06 111853](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/f53b9564-f6a9-4d00-a795-744b80f5ac78)

Kode diatas adalah berfungsi untuk membuat stack, fungsi `isFull()` berfungsi untuk melihat apakah stack penuh, fungsi `isempty()` berfungsi untuk melihat apakah stack kosong, `pushArrayBuku()` berfungsi untuk menambahkan stack dibagian atas, `popArrayBuku()` berfungsi untuk menghapus stack bagian atas, `peekArrayBuku()` berfungsi untuk melihat stack diposisi tertentu, `countstack()` berfungsi untuk menghitung jumlah data dalam stack, `changeArrayBuku()` berfungsi untuk mengganti stack diposisi tertentu, `destroyArrayBuku()` berfungsi untuk menghapus semua data dalam stack, `cetakArrayBuku()` berfungsi untuk mencetak isi stack.



## Unguided 

### 1. [Unguided 1]

```C++
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string kalimat) {
    stack<char> charStack;
    kalimat.erase(remove_if(kalimat.begin(), kalimat.end(), ::isspace), kalimat.end());
    transform(kalimat.begin(), kalimat.end(), kalimat.begin(), ::tolower);
    for (char c : kalimat) {
        charStack.push(c);
    }

    string reverseKalimat;
    while (!charStack.empty()) {
        reverseKalimat += charStack.top();
        charStack.pop();
    }

    return kalimat == reverseKalimat;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    if (isPalindrome(kalimat)) {
        cout << "Kalimat tersebut adalah palindrom" << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom" << endl;
    }

    return 0;
}

```
#### Output:
![Screenshot 2024-05-06 140833](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/6fb5f8e9-14ec-4a4a-870e-75beaa8de339)

Kode di atas berberja dengan cara meminta user untuk input kalimat, kemudian akan diproses oleh fungsi `isPalindrome()` yang didalamnya kita deklarasikan char sebagai tipe data stack tersebut dan diberi nama `charStack`, kemudian kita hilangkan spasi dalam kalimat tersebut dengan menggunakan `.erase` dari library algorithm, kemudian ditransform menjadi lowercase semua agar mudah untuk dibandingkan nanti, kemudian kita deklarasikan `string reverseKalimat` untuk menampung kalimat yang kita balik, kemudian menambahkan top kedalam reverseKalimat kemudian diulang hingga top habis lalu mengembalilkan nilai true jika reverseKalimat = kalimat.

### 2. [Unguided 2]

```C++
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string balikKata(string kalimat) {
    stack<char> charStack;
    for (char c : kalimat) {
        charStack.push(c);
    }

    string reverseKalimat;
    while (!charStack.empty()) {
        reverseKalimat += charStack.top();
        charStack.pop();
    }
    return reverseKalimat;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);
    cout << "Setelah dibalik: " << balikKata(kalimat) <<endl;

    return 0;
}

```
#### Output:
![Screenshot 2024-05-06 141344](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/3d3dfc69-932a-4dcb-86d7-531f970195fd)

Kodenya berisi fungsi `balikKata` yang isinya mendeklarasikan tipe data stack menjadi char dengan nama `charStack` lalu membuat perulangan untuk memasukkan satu per satu huruf pada kalimat kedalam stack, kemudian mendeklarasikan reverseKalimat yang diisi menggunakan perulangan while yang didalamnya menambahkan top dari stack, lalu menghapus top dan diulang sampai kalimat habis, lalu mengembalikan nilai reverseKalimat untuk dicetak.


## Kesimpulan
Stack adalah struktur data yang serbaguna dengan berbagai fungsi penting dalam ilmu komputer. Kemampuannya untuk menyimpan data, mengelola memori, mengevaluasi ekspresi, memproses bahasa, dan menjalankan mesin virtual menjadikannya alat yang tak ternilai dalam berbagai aplikasi.

## Referensi
[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. *Introduction to Algorithms, Fourth Edition. MIT Press*. 2020.
