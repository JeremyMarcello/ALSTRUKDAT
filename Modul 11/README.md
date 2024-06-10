# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>


<p align="center">Jeremy Marcello Waani / 2311110003 / S1SD04-A</p>

## Dasar Teori

**Pengertian Fungsi Rekursif**

### 1. Pengertian Hash Table

Hash table atau tabel hash adalah struktur data yang digunakan untuk menyimpan data secara asosiatif, di mana setiap data dikaitkan dengan kunci uniknya masing-masing. Data disimpan dalam format array, dan setiap kunci dipetakan ke indeks unik dalam array menggunakan fungsi hash. Hal ini memungkinkan akses data yang sangat cepat, terutama jika indeks data tersebut diketahui.

Menurut [1],[ meskipun terbit diluar jangka waktu yang diminta, namun konsep dasarnya tetap relevan], hash table adalah struktur data yang efektif untuk penyimpanan dan pengambilan data dengan cepat. Hash table bekerja dengan memetakan kunci data ke indeks dalam array, dan indeks ini digunakan untuk menyimpan data dalam array. Pencarian data dalam hash table sangat efisien karena nilai hash dari kunci data dapat dihitung dengan cepat dan digunakan untuk menentukan indeks array tempat data disimpan.

### 2. Fungsi Hash Table

**Hash table menawarkan beberapa fungsi penting, di antaranya:**

Penyimpanan Data Asosiatif: Hash table memungkinkan penyimpanan data dengan kunci unik dan pengambilan data dengan cepat berdasarkan kunci tersebut.
Pencarian Data yang Cepat: Hash table menawarkan waktu pencarian yang sangat cepat, rata-rata O(1), dibandingkan dengan struktur data lain seperti pohon pencarian biner yang memiliki waktu pencarian rata-rata O(log n).
Penghematan Memori: Hash table dapat menghemat memori dengan menyimpan data secara kompak, terutama jika kunci data pendek.
Implementasi yang Mudah: Hash table relatif mudah diimplementasikan dan dipahami.

### 3. Sistem Hash Table

**Hash table terdiri dari beberapa komponen utama:**

Array: Array adalah struktur data dasar yang digunakan untuk menyimpan data.
Fungsi Hash: Fungsi hash adalah fungsi yang mengubah kunci data menjadi indeks dalam array. Fungsi hash harus mendistribusikan kunci secara merata untuk menghindari tabrakan.
Metode Penanganan Tabrakan: Tabrakan terjadi ketika dua kunci yang berbeda dipetakan ke indeks yang sama dalam array. Metode penanganan tabrakan digunakan untuk menyelesaikan masalah ini.

### 4. Operasi Dasar Hash Table

**Operasi dasar pada hash table meliputi:**

Memasukkan Data: Memasukkan data baru ke dalam hash table.
Mencari Data: Mencari data dalam hash table berdasarkan kunci.
Menghapus Data: Menghapus data dari hash table.
Mengubah Ukuran: Mengubah ukuran hash table saat diperlukan.

### 5. Kelebihan dan Kekurangan Hash Table

**Kelebihan:**

Cepat: Hash table menawarkan waktu akses dan pencarian data yang sangat cepat.
Efisien: Hash table dapat menghemat ruang memori dan waktu pemrosesan.
Serbaguna: Hash table dapat digunakan untuk berbagai aplikasi, seperti database, cache, dan kompilator.

**Kekurangan:**

Tabrakan: Tabrakan dapat terjadi dan memperlambat kinerja hash table.
Ketergantungan pada Fungsi Hash: Kinerja hash table bergantung pada kualitas fungsi hash.
Keamanan: Jika tidak diterapkan dengan benar, hash table dapat rentan terhadap serangan.

### 6. Jenis-Jenis Hash Table

**Ada beberapa jenis hash table, di antaranya:**

Hash Table Statis: Ukuran array pada hash table statis tidak dapat diubah setelah dibuat.
Hash Table Dinamis: Ukuran array pada hash table dinamis dapat berubah secara otomatis saat data ditambahkan atau dihapus.
Hash Table Berantai: Hash table berantai digunakan untuk menangani tabrakan dengan menyimpan entri yang bertabrakan dalam daftar tertaut.
Pohon Hash: Pohon hash adalah struktur data gabungan yang menggabungkan hash table dengan pohon pencarian biner.

### 7. Implementasi Hash Table dalam C++

Hash table dapat diimplementasikan dalam C++ menggunakan berbagai cara. Salah satu cara yang umum adalah dengan menggunakan STL (Standard Template Library) yang menyediakan kelas std::unordered_map. Kelas std::unordered_map menyediakan semua operasi dasar untuk hash table, seperti memasukkan, mencari, menghapus, dan mengubah ukuran.

## Guided

### 1. Guided 1
```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
   
    // Deletion
    ht.remove(4);
   
    // Traversal
    ht.traverse();
   
    return 0;
}
```

**Output:**
![Screenshot 2024-06-11 013902](https://github.com/dkumui/Struktur-Data-Assignment/assets/156126843/3dd66d15-ce7f-4e73-9c69-44cacd006e00)

**Kode yang diberikan mengimplementasikan Hash Table dengan Linked List untuk menangani key yang berpotensi bertabrakan (collision).**

**Konsep Utama:**

* Hash Table: Struktur data yang menyimpan pasangan key-value.
* Hash Function: Fungsi untuk memetakan key ke index tertentu dalam array (bucket).
* Linked List: Struktur data linear untuk menyimpan pasangan key-value tambahan jika terjadi collision.

**Kode rincian:**

* hash_func(key): Fungsi hash sederhana yang menggunakan modulo MAX_SIZE untuk menghitung index dalam array.
* struct Node: Struktur untuk menyimpan key, value, dan pointer ke node selanjutnya dalam Linked List.
* class HashTable: Class untuk mengelola Hash Table.
    * Konstruktor: Menciptakan array of pointer table berukuran MAX_SIZE untuk menyimpan pointer ke node Linked List di setiap bucket.
    * Destructor: Melakukan dealokasi memori untuk setiap node dalam Linked List di setiap bucket.
    * insert(key, value): Memasukkan pasangan key-value ke Hash Table.
        * Hitung index menggunakan fungsi hash.
        * Periksa apakah terdapat node dengan key yang sama (collision).
            * Jika ya, update value dari node tersebut.
            * Jika tidak, buat node baru dan tambahkan ke awal Linked List di bucket tersebut.
    * get(key): Mencari value berdasarkan key.
        * Hitung index menggunakan fungsi hash.
        * Iterasi melalui Linked List di bucket tersebut.
        * Jika key ditemukan, kembalikan value.
        * Jika tidak ditemukan, kembalikan -1 (nilai default).
    * remove(key): Menghapus pasangan key-value dari Hash Table.
        * Hitung index menggunakan fungsi hash.
        * Iterasi melalui Linked List di bucket tersebut.
        * Jika key ditemukan, hapus node tersebut dan update pointer jika perlu.
    * traverse(): Menampilkan seluruh isi Hash Table (iterasi setiap Linked List di setiap bucket).

**Fungsi Utama (main):**

* Menciptakan objek ht dari class HashTable.
* Memasukkan beberapa pasangan key-value (insert).
* Mencari value berdasarkan key (get).
* Mencoba mencari key yang tidak ada (get).
* Mencoba menghapus key yang tidak ada (remove).
* Menampilkan seluruh isi Hash Table (traverse).

**Kesimpulan:**

Kode ini merupakan contoh implementasi Hash Table yang efektif menangani collision dengan menggunakan Linked List. Hal ini memungkinkan penyimpanan data yang lebih fleksibel dibandingkan dengan pendekatan array statis.

### 2. Guided 2
```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;

class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table : " << endl;

    employee_map.print();

    return 0;
}
```

**Output:**
![Screenshot 2024-06-11 013827](https://github.com/dkumui/Struktur-Data-Assignment/assets/156126843/61ff0c85-0b03-4c2f-9bc4-32e777fada61)

**Kode yang diberikan mengimplementasikan program phonebook sederhana menggunakan Hash Table.**

**Struktur Data:**

* HashNode: Struktur untuk menyimpan data kontak (nama dan nomor telepon).
* HashMap: Class untuk mengelola Hash Table.
* vector<HashNode*> table: Array of pointer untuk menyimpan node Hash Table.

**Fungsi Hash:**

* hashFunc(string key): Fungsi hash sederhana yang menjumlahkan nilai ASCII karakter-karakter dalam string key. Hasilnya kemudian dimodulo dengan TABLE_SIZE untuk mendapatkan index dalam array table.

**Operasi Hash Table:**

* insert(string name, string phone_number): Memasukkan data kontak baru ke Hash Table.
    * Hitung index menggunakan fungsi hash.
    * Periksa apakah terdapat node dengan nama yang sama (collision).
        * Jika ya, update nomor telepon pada node tersebut.
        * Jika tidak, buat node baru dan tambahkan ke bucket terkait di array table.
* remove(string name): Menghapus data kontak dari Hash Table.
    * Hitung index menggunakan fungsi hash.
    * Iterasi melalui bucket terkait di array table.
    * Jika nama ditemukan, hapus node tersebut dari bucket.
* searchByName(string name): Mencari nomor telepon berdasarkan nama.
    * Hitung index menggunakan fungsi hash.
    * Iterasi melalui bucket terkait di array table.
    * Jika nama ditemukan, kembalikan nomor telepon.
    * Jika tidak ditemukan, kembalikan string kosong.
* print(): Mencetak isi Hash Table (nama dan nomor telepon di setiap bucket).

**Fungsi Utama (main):**

* Menciptakan objek employee_map dari class HashMap.
* Memasukkan beberapa data kontak (insert).
* Mencari nomor telepon berdasarkan nama (searchByName).
* Menghapus salah satu data kontak (remove).
* Mencari kembali nomor telepon yang dihapus (searchByName).
* Mencetak isi Hash Table saat ini (print).

**Kesimpulan:**

Kode ini menunjukkan penggunaan Hash Table untuk menyimpan dan mengelola data phonebook. Fungsi hash membantu memetakan nama ke index tertentu dalam array, dan penggunaan Linked List (walaupun tidak eksplisit didefinisikan) memungkinkan penanganan collision secara efisien.

## Unguided

### 1. Unguided 1

```C++
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 10;

struct Mahasiswa {
    string nama;
    long long NIM;
    int nilai;
    Mahasiswa *next;

    Mahasiswa(string nama, long long NIM, int nilai) : nama(nama), NIM(NIM), nilai(nilai), next(nullptr) {}
};

class HashTable {
private:
    Mahasiswa **table;
    int hashFunc(long long key) {
        return key % MAX_SIZE;
    }

public:
    HashTable() {
        table = new Mahasiswa*[MAX_SIZE]();
    }

    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; ++i) {
            Mahasiswa *current = table[i];
            while (current != nullptr) {
                Mahasiswa *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    void insert(const string &nama, long long NIM, int nilai) {
        int index = hashFunc(NIM);
        Mahasiswa *newMahasiswa = new Mahasiswa(nama, NIM, nilai);
        newMahasiswa->next = table[index];
        table[index] = newMahasiswa;
        cout << "Data berhasil ditambahkan.\n";
    }

    void remove(long long NIM) {
        int index = hashFunc(NIM);
        Mahasiswa *current = table[index];
        Mahasiswa *prev = nullptr;

        while (current != nullptr) {
            if (current->NIM == NIM) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                cout << "Mahasiswa dengan NIM " << NIM << " telah dihapus.\n";
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan.\n";
    }

    Mahasiswa* searchByNIM(long long NIM) {
        int index = hashFunc(NIM);
        Mahasiswa *current = table[index];
        while (current != nullptr) {
            if (current->NIM == NIM) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void searchByRange(int awal, int akhir) {
        cout << "+---------------------+-----------------+---------------+\n";
        cout << "|       Nama          |       NIM       |     Nilai     |\n";
        cout << "+---------------------+-----------------+---------------+\n";
        for (int i = 0; i < MAX_SIZE; ++i) {
            Mahasiswa *current = table[i];
            while (current != nullptr) {
                if (current->nilai >= awal && current->nilai <= akhir) {
                    cout << "| " << setw(19) << left << current->nama
                         << "| " << setw(15) << current->NIM
                         << "| " << setw(13) << current->nilai << " |\n";
                }
                current = current->next;
            }
        }
        cout << "+---------------------+-----------------+---------------+\n";
    }

    void displayAll() {
        cout << "+---------------------+-----------------+---------------+\n";
        cout << "|       Nama          |       NIM       |     Nilai     |\n";
        cout << "+---------------------+-----------------+---------------+\n";
        for (int i = 0; i < MAX_SIZE; ++i) {
            Mahasiswa *current = table[i];
            while (current != nullptr) {
                cout << "| " << setw(19) << left << current->nama
                     << "| " << setw(15) << current->NIM
                     << "| " << setw(13) << current->nilai << " |\n";
                current = current->next;
            }
        }
        cout << "+---------------------+-----------------+---------------+\n";
    }
};

int main() {
    HashTable ht;

    int choice, nilai, awal, akhir;
    string nama;
    long long NIM;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Hapus Data Mahasiswa\n";
        cout << "3. Cari berdasarkan NIM\n";
        cout << "4. Cari berdasarkan Rentang Nilai\n";
        cout << "5. Tampilkan Semua Data\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nama: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM: ";
                cin >> NIM;
                cout << "Masukkan nilai: ";
                cin >> nilai;
                ht.insert(nama, NIM, nilai);
                break;
            case 2:
                cout << "Masukkan NIM yang ingin dihapus: ";
                cin >> NIM;
                ht.remove(NIM);
                break;
            case 3:
                cout << "Masukkan NIM yang ingin dicari: ";
                cin >> NIM;
                {
                    Mahasiswa *mahasiswaPtr = ht.searchByNIM(NIM);
                    if (mahasiswaPtr) {
                        cout << "Ditemukan mahasiswa dengan NIM " << NIM << " bernama " << mahasiswaPtr->nama << " dan memiliki nilai " << mahasiswaPtr->nilai << ".\n";
                    } else {
                        cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan.\n";
                    }
                }
                break;
            case 4:
                cout << "Masukkan nilai awal: ";
                cin >> awal;
                cout << "Masukkan nilai akhir: ";
                cin >> akhir;
                ht.searchByRange(awal, akhir);
                break;
            case 5:
                ht.displayAll();
                break;
            case 6:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
```

#### Output:
![Screenshot 2024-06-11 013742](https://github.com/dkumui/Struktur-Data-Assignment/assets/156126843/a70470eb-ca0c-45be-b054-32d3ec10857d)

**Kode yang diberikan mengimplementasikan sistem akademik sederhana menggunakan Hash Table untuk menyimpan data mahasiswa.**

**Struktur Data:**

* Mahasiswa: Struktur untuk menyimpan informasi mahasiswa (nama, NIM, dan nilai).
* HashTable: Class untuk mengelola Hash Table.
    * table: Array of pointer untuk menyimpan pointer ke node Mahasiswa.
    * hashFunc(long long key): Fungsi hash untuk menghitung index dalam array berdasarkan NIM.
    * insert(string nama, long long NIM, int nilai): Memasukkan data mahasiswa baru ke Hash Table.
    * remove(long long NIM): Menghapus data mahasiswa berdasarkan NIM.
    * searchByNIM(long long NIM): Mencari data mahasiswa berdasarkan NIM.
    * searchByRange(int awal, int akhir): Mencari data mahasiswa berdasarkan rentang nilai.
    * displayAll(): Menampilkan semua data mahasiswa.

**Fungsi Utama (main):**

* Menciptakan objek ht dari class HashTable.
* Menampilkan menu interaktif untuk memilih operasi yang ingin dilakukan.
* Memproses pilihan pengguna:
    * Menambah Data Mahasiswa: Meminta nama, NIM, dan nilai, kemudian memasukkan data tersebut ke Hash Table.
    * Hapus Data Mahasiswa: Meminta NIM, kemudian mencari dan menghapus data mahasiswa terkait.
    * Cari berdasarkan NIM: Meminta NIM, kemudian mencari dan menampilkan data mahasiswa terkait.
    * Cari berdasarkan Rentang Nilai: Meminta nilai awal dan akhir, kemudian mencari dan menampilkan data mahasiswa dengan nilai dalam rentang tersebut.
    * Tampilkan Semua Data: Menampilkan semua data mahasiswa dalam tabel.
    * Keluar: Menampilkan pesan dan mengakhiri program.

**Kesimpulan:**

Kode ini menunjukkan penggunaan Hash Table untuk mengelola data mahasiswa dalam sistem akademik sederhana. Hash Table memungkinkan penyimpanan data yang efisien dan pencarian data yang cepat berdasarkan NIM atau rentang nilai.

## Kesimpulan
Fungsi rekursif adalah teknik pemrograman di mana sebuah fungsi memanggil dirinya sendiri untuk menyelesaikan suatu masalah. Fungsi rekursif dapat digunakan untuk menyelesaikan berbagai masalah, termasuk menghitung faktorial, deret Fibonacci, dan traversal pohon. Rekursif tidak langsung dan rekursif timbal balik merupakan dua jenis rekursif yang sering digunakan. 

## Referensi
[1] ** Introduction to Algorithms** (Cormen et al., 2022) 