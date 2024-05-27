# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>


<p align="center">Jeremy Marcello Waani / 2311110003 / S1SD04-A</p>

## Dasar Teori

### 1. Pengertian Queue

Queue heap, atau prioritas baris, adalah struktur data yang mengintegrasikan fungsi dari kedua baris dan baris [1]. Sebuah barisan standar beroperasi pada basis First In, First Out (FIFO), di mana elemen diproses dalam urutan kedatangan mereka [1]. Sebaliknya, tumpukan terstruktur seperti pohon, diatur oleh prioritas sehingga elemen dengan prioritas tertinggi tinggal di bagian atas pohon [1].


Dengan menggabungkan kedua konsep ini, sekelompok baris memungkinkan elemen untuk ditambahkan dalam urutan FIFO sambil memastikan bahwa elemen prioritas tertinggi secara konsisten tetap berada di bagian depan baris dan dihapus pertama [1]. Karakteristik ini membuatnya sangat cocok untuk skenario yang membutuhkan pemrosesan prioritas dari elemen, seperti algoritma pencarian atau tugas jadwal [1].

**Implementasi Queue Heaps**

Queue heaps dapat diimplementasikan dalam C++ menggunakan berbagai cara, salah satu yang paling umum adalah dengan menggunakan STL (Standard Template Library) [2]. STL menyediakan kelas `priority_queue` yang dapat digunakan untuk membuat queue heaps [2].

Kelas `priority_queue` menggunakan struktur data heap minimum, di mana elemen dengan nilai terkecil berada di puncak [2]. Untuk mengimplementasikan queue heap, kita dapat menggunakan adaptor std::queue pada kelas `priority_queue` [2].

**Fungsi-fungsi dalam Queue Heaps**

Kelas `priority_queue` menyediakan beberapa fungsi untuk mengelola queue heaps:

* **push(value):** Menambahkan elemen baru ke queue heap [2].
* **top():** Mengembalikan elemen di puncak queue heap tanpa menghapusnya [2].
* **pop():** Menghapus elemen di puncak queue heap [2].
* **empty():** Mengembalikan nilai true jika queue heap kosong, dan false jika tidak [2].
* **size():** Mengembalikan jumlah elemen dalam queue heap [2].



## Guided

### 1. Guided 1
```C++
#include <iostream>
#include <algorithm>
using namespace std;

int H[50];
int heapSize = -1;

int parent(int i) {
    return(i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = 1;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changerPriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove (int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(67);
    insert(26);
    insert(54);
    insert(38);
    insert(19);
    insert(27);
    insert(35);
    insert(41);
    insert(17);
    insert(32);

    cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    cout << "Node With Maximum Priority : " << extractMax() << "\n";

    cout << "Priority Queue After Extracting Maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    changerPriority(5, 47);
    cout << "Priority Queue After Priority Change : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    remove(5);
    cout << "Priority Queue After Removing The Element : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    return 0;
}
```

**Output:**
![9G1](https://github.com/JeremyMarcello/Assignment-Praktikum-Algoritma-dan-Struktur-Data/assets/156126843/7f94c0e3-78d0-4f49-8313-f529d2e15f09)

**Struktur Data:**

* `H:` Array integer dengan ukuran maksimal 50 untuk menyimpan elemen dalam heap.
* `heapSize:` Variabel integer untuk mencatat jumlah elemen yang ada di heap (dimulai dari -1).

**Fungsi:**

* `parent(i):` Mengembalikan indeks induk dari elemen dengan indeks i.
* `leftChild(i):` Mengembalikan indeks anak kiri dari elemen dengan indeks i.
* `rightChild(i):` Mengembalikan indeks anak kanan dari elemen dengan indeks i.
* `shiftUp(i):` Menggeser elemen dengan indeks i ke atas dalam heap untuk menjaga struktur heap.
* `shiftDown(i):` Menggeser elemen dengan indeks i ke bawah dalam heap untuk menjaga struktur heap.
* `insert(p):` Memasukkan elemen baru p ke dalam heap.
* `extractMax():` Menghapus dan mengembalikan elemen dengan prioritas tertinggi (nilai terbesar) dari heap.
* `changerPriority(i, p):` Mengubah prioritas elemen dengan indeks i menjadi p dan memperbarui struktur heap.
* `getMax():` Mengembalikan elemen dengan prioritas tertinggi (nilai terbesar) dalam heap tanpa menghapusnya.
* `remove(i):` Menghapus elemen dengan indeks i dari heap.

**Fungsi Utama (main):**

* Memasukkan 10 elemen dengan nilai berbeda ke dalam heap.
* Menampilkan isi heap.
* Menghapus elemen dengan prioritas tertinggi dan menampilkannya.
* Menampilkan isi heap setelah penghapusan.
* Mengubah prioritas elemen di indeks ke-5 menjadi 47 dan menampilkan isi heap.
* Menghapus elemen di indeks ke-5 dan menampilkan isi heap.

**Kesimpulan:**

Kode ini menunjukkan implementasi heap priority queue yang efektif untuk menyimpan dan mengelola elemen berdasarkan prioritasnya. Fungsi-fungsi yang disediakan memungkinkan operasi dasar seperti penambahan, penghapusan, perubahan prioritas, dan pengambilan elemen dengan prioritas tertinggi dengan efisien.

## Unguided

### 1. Unguided 1

```C++
#include <iostream>
#include <algorithm>
using namespace std;

int H[50];
int heapSize = -1;

int parent(int i) {
    return(i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = 1;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove (int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

void printHeap() {
    cout << "Heap: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";
}

int main() {
    int choice, value, index;
    
    insert(67);
    insert(26);
    insert(54);
    insert(38);
    insert(19);
    insert(27);
    insert(35);
    insert(41);
    insert(17);
    insert(32);

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert element\n";
        cout << "2. Extract max\n";
        cout << "3. Change priority\n";
        cout << "4. Remove element\n";
        cout << "5. Print heap\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insert(value);
                break;
            case 2:
                if (heapSize >= 0) {
                    cout << "Max value extracted: " << extractMax() << "\n";
                } else {
                    cout << "Heap is empty!\n";
                }
                break;
            case 3:
                cout << "Masukkan index: ";
                cin >> index;
                cout << "Masukkan nilai: ";
                cin >> value;
                if (index >= 0 && index <= heapSize) {
                    changePriority(index, value);
                } else {
                    cout << "Invalid index!\n";
                }
                break;
            case 4:
                cout << "Enter index to remove: ";
                cin >> index;
                if (index >= 0 && index <= heapSize) {
                    remove(index);
                } else {
                    cout << "Invalid index!\n";
                }
                break;
            case 5:
                printHeap();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    }
    return 0;
}
```

#### Output:
![9U1](https://github.com/JeremyMarcello/Assignment-Praktikum-Algoritma-dan-Struktur-Data/assets/156126843/0b0543d6-5e90-42c7-832e-b71bcb910c6c)

**Struktur Data:**

* `H:` Array integer dengan ukuran maksimal 50 untuk menyimpan elemen dalam heap.
* `heapSize:` Variabel integer untuk mencatat jumlah elemen yang ada di heap (dimulai dari -1).

**Fungsi:**

* `parent(i):` Mengembalikan indeks induk dari elemen dengan indeks i.
* `leftChild(i):` Mengembalikan indeks anak kiri dari elemen dengan indeks i.
* `rightChild(i):` Mengembalikan indeks anak kanan dari elemen dengan indeks i.
* `shiftUp(i):` Menggeser elemen dengan indeks i ke atas dalam heap untuk menjaga struktur heap.
* `shiftDown(i):` Menggeser elemen dengan indeks i ke bawah dalam heap untuk menjaga struktur heap.
* `insert(p):` Memasukkan elemen baru p ke dalam heap.
* `extractMax():` Menghapus dan mengembalikan elemen dengan prioritas tertinggi (nilai terbesar) dari heap.
* `changerPriority(i, p):` Mengubah prioritas elemen dengan indeks i menjadi p dan memperbarui struktur heap.
* `getMax():` Mengembalikan elemen dengan prioritas tertinggi (nilai terbesar) dalam heap tanpa menghapusnya.
* `remove(i):` Menghapus elemen dengan indeks i dari heap.
* `printHeap():` Mencetak isi heap ke konsol.

**Fungsi Utama (main):**

* Memasukkan 10 elemen dengan nilai berbeda ke dalam heap.
* Menampilkan menu interaktif yang memungkinkan pengguna melakukan berbagai operasi pada heap.
* Memasukkan elemen baru.
* Menghapus elemen dengan prioritas tertinggi.
* Mengubah prioritas elemen.
* Menghapus elemen berdasarkan indeks.
* Mencetak isi heap.
* Keluar dari program.
* Berdasarkan pilihan pengguna, program akan menjalankan fungsi yang sesuai.
* Memvalidasi input pengguna untuk indeks dan nilai.

**Kesimpulan:**

Kode ini menyediakan implementasi heap priority queue yang interaktif. Pengguna dapat dengan mudah melakukan berbagai operasi pada heap dan memantau kondisinya melalui menu yang disediakan.

## Kesimpulan
Kelurahan mengintegrasikan fungsionalitas kedua kelurahan dan keluraha, memungkinkan untuk mendapatkan elemen berdasarkan prioritas tertinggi pertama. Struktur data ini terbukti lebih efisien daripada barisan tradisional untuk operasi tertentu dan ideal untuk aplikasi di mana urutan dan prioritas elemen sangat penting. Implementasi penting termasuk 'priority_queue' di Perpustakaan Standar C++ (STL) dan 'heapq' di Python. Kelurahan menemukan aplikasi serbaguna, seperti perencanaan tugas, routing jaringan, algoritma pencarian, simulasi, dan sistem real-time.

## Referensi

[1] Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2021). Data Structures and Algorithms in C++. Upper Saddle River, NJ: Pearson.
