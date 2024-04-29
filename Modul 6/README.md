# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">2311110003 / Jeremy Marcello Waani / Sains Data</p>

## Dasar Teori
### SINGLE LINKED LIST
Single linked list adalah daftar yang hanya memiliki pranala (link) menuju elemen berikutnya [1]. Setiap node berisi data dan pranala ke node berikutnya. Pencarian diawali dari node header dengan kompleksitas O(n) [2].

### DOUBLE LINKED LIST
Double linked list memiliki dua pranala di setiap node, yakni ke node sebelumnya dan berikutnya [3]. Pencarian dapat dimulai dari node manapun dengan kompleksitas O(n) [2].

### LINKED LIST NON CIRCULAR
Linked list non circular memiliki node header dan tail tanpa hubungan antara dua ujung. Proses penambahan/penghapusan dimulai dari salah satu ujung [1].

### LINKED LIST CIRCULAR
Perbedaan dengan non circular adalah tail dalam circular terhubung kembali ke header sehingga terbentuk lingkaran tak berujung [3]. Penambahan/penghapusan dapat dimulai dari node manapun [2].

## Guided 

### 1. [Guided 1]

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
    int data;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan
bool isEmpty() {
    return (head == NULL);
}

// Tambah Data Depan
void insertDepan(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Data Belakang
void insertBelakang(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah Node
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Data Tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi Di Luar Jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi Bukan Posisi Tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->data = data;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node Depan
void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List Kosong!" << endl;
    }
}

// Hapus Node Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List Kosong!" << endl;
    }
}

// Hapus Node Tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi Di Luar Jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi Bukan Posisi Tengah" << endl;
    } else {
        Node *hapus;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

// Ubah Data Depan
void ubahDepan(int data) {
    if (!isEmpty()) {
        head->data = data;
    } else {
        cout << "List Masih Kosong!" << endl;
    }
}

// Ubah Data Tengah
void ubahTengah(int data, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi Di Luar Jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi Bukan Posisi Tengah" << endl;
        } else {
            Node *bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
                bantu = bantu->next;
            }
            bantu->data = data;
        }
    } else {
        cout << "List Masih Kosong!" << endl;
    }
}

// Ubah Data Belakang
void ubahBelakang(int data) {
    if (!isEmpty()) {
        tail->data = data;
    } else {
        cout << "List Masih Kosong!" << endl;
    }
}

// Hapus Semua Node
void clearList() {
    Node *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = NULL;
    cout << "List Berhasil Terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu = head;
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List Masih Kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan(3); 
    tampil();
    insertBelakang(5); 
    tampil();
    insertDepan(2); 
    tampil();
    insertDepan(1); 
    tampil();
    hapusDepan(); 
    tampil();
    hapusBelakang(); 
    tampil();
    insertTengah(7, 2); 
    tampil();
    hapusTengah(2); 
    tampil();
    ubahDepan(1); 
    tampil();
    ubahBelakang(8); 
    tampil();
    ubahTengah(11, 2); 
    tampil();
    clearList();
    return 0;
}
```

#### Output
![Screenshot 2024-04-29 052943](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/43370a81-a845-4d41-b4a3-7ca2f59c5fbf)

Kode diatas adalah, implementasi dari single linked list non-circular dalam bahasa C++. Program ini memiliki struktur dasar dari linked list yang terdiri dari beberapa fungsi utama seperti `insertDepan`, `insertBelakang`, `insertTengah`, `hapusDepan`, `hapusBelakang`, `hapusTengah`, `ubahDepan`, `ubahBelakang`, `ubahTengah`, `clearList`, dan `tampil` untuk berbagai operasi yang dapat dilakukan pada linked list, seperti penambahan, penghapusan, pengubahan, serta penampilan elemen. Pada fungsi `clearList`, program menghapus semua node dalam linked list dengan mengosongkan memori dan menyetel pointer `head` ke NULL untuk menandai bahwa linked list kosong. Setelah menginisialisasi linked list menggunakan `init()`, program melakukan serangkaian operasi seperti menambahkan, menghapus, mengubah, dan menampilkan elemen-elemen dalam linked list untuk menguji fungsionalitasnya.



### 2. [Guided 2]

```C++
#include <iostream>
using namespace std;

/// PROGRAM DOUBLE LINKED LIST
class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = NULL;
        tail = NULL;
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Perbarui Data" << endl;
        cout << "4. Hapus Semua Data" << endl;
        cout << "5. Tampilkan Data" << endl;
        cout << "6. Keluar" << endl;
        int choice;
        cout << "Masukkan Pilihan Anda : ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Masukkan Data Yang Akan Ditambahkan : ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Masukkan Data Lama : ";
                cin >> oldData;
                cout << "Masukkan Data Baru : ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data Tidak Ditemukan" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Pilihan Tidak Valid" << endl;
                break;
            }
        }
    }
}
```

#### Output
![Screenshot 2024-04-29 053845](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/51b5683b-0d68-4edf-b5fd-633ede4c07c3)
![Screenshot 2024-04-29 053913](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/677f1b45-678b-4093-b8e0-2f73792f6c56)

Kode di atas adalah implementasi dari double linked list dalam bahasa C++. Program ini terdiri dari dua kelas, yaitu `Node` yang merepresentasikan simpul dalam linked list dan `DoublyLinkedList` yang merupakan representasi dari linked list itu sendiri. Setiap simpul (`Node`) memiliki tiga atribut, yaitu `data` yang menyimpan nilai data, `prev` yang merupakan pointer ke simpul sebelumnya, dan `next` yang merupakan pointer ke simpul berikutnya. Kelas `DoublyLinkedList` memiliki atribut `head` dan `tail` yang menunjukkan kepala dan ekor dari linked list. Metode-metode dalam kelas `DoublyLinkedList` meliputi `push` untuk menambahkan data di depan linked list, `pop` untuk menghapus data dari depan linked list, `update` untuk memperbarui nilai data tertentu dalam linked list, `deleteAll` untuk menghapus semua data dalam linked list, dan `display` untuk menampilkan semua data dalam linked list. Pada fungsi `main`, program memberikan pilihan kepada pengguna untuk menambah, menghapus, memperbarui, menampilkan, menghapus semua data, atau keluar dari program, dan sesuai dengan pilihan yang dibuat, program akan memanggil metode yang sesuai dari kelas `DoublyLinkedList`.


### 3. [Guided 3]

```C++
#include <iostream> 
using namespace std; 

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR 

// Deklarasi Struct Node 
struct Node 
{ 
    int data; 
    Node *next; 
}; 

Node *head; 
Node *tail; 

// Inisialisasi Node 
void init() 
{ 
    head = NULL; 
    tail = NULL; 
} 

// Pengecekan 
bool isEmpty() 
{ 
    return head == NULL; 
} 

// Tambah Depan 
void insertDepan(int nilai) 
{ 
    Node *baru = new Node; 
    baru->data = nilai; 
    baru->next = NULL; 
    if (isEmpty()) 
    { 
        head = tail = baru; 
    } 
    else 
    { 
        baru->next = head; 
        head = baru; 
    } 
} 

// Tambah Belakang 
void insertBelakang(int nilai) 
{ 
    Node *baru = new Node; 
    baru->data = nilai; 
    baru->next = NULL; 
    if (isEmpty()) 
    { 
        head = tail = baru; 
    } 
    else 
    { 
        tail->next = baru; 
        tail = baru; 
    } 
} 

// Hitung Jumlah List 
int hitungList() 
{ 
    Node *hitung = head; 
    int jumlah = 0; 
    while (hitung != NULL) 
    { 
        jumlah++; 
        hitung = hitung->next; 
    } 
    return jumlah; 
} 

// Tambah Tengah 
void insertTengah(int data, int posisi) 
{ 
    if (posisi < 1 || posisi > hitungList()) 
    { 
        cout << "Posisi Di Luar Jangkauan" << endl; 
    } 
    else if (posisi == 1) 
    { 
        cout << "Posisi Bukan Posisi Tengah" << endl; 
    } 
    else 
    { 
        Node *baru = new Node(); 
        baru->data = data; 
        Node *bantu = head; 
        for (int nomor = 1; nomor < posisi - 1; nomor++) 
        { 
            bantu = bantu->next; 
        } 
        baru->next = bantu->next; 
        bantu->next = baru; 
    } 
} 

// Hapus Depan 
void hapusDepan() 
{ 
    if (!isEmpty()) 
    { 
        Node *hapus = head; 
        if (head->next != NULL) 
        { 
            head = head->next;
        } 
        else 
        { 
            head = tail = NULL; 
        } 
        delete hapus; 
    } 
    else 
    { 
        cout << "List Kosong!" << endl; 
    } 
} 

// Hapus Belakang 
void hapusBelakang() 
{ 
    if (!isEmpty()) 
    { 
        Node *hapus = tail; 
        if (head != tail) 
        { 
            Node *bantu = head; 
            while (bantu->next != tail) 
            { 
                bantu = bantu->next; 
            } 
            tail = bantu; 
            tail->next = NULL; 
        } 
        else 
        { 
            head = tail = NULL; 
        } 
        delete hapus; 
    } 
    else 
    { 
        cout << "List Kosong!" << endl; 
    } 
} 

// Hapus Tengah 
void hapusTengah(int posisi) 
{ 
    if (!isEmpty()) 
    { 
        Node *bantu = head, *hapus = NULL, *sebelum = NULL; 
        if (posisi < 1 || posisi > hitungList()) 
        { 
            cout << "Posisi Di Luar Jangkauan" << endl; 
        } 
        else if (posisi == 1) 
        { 
            cout << "Posisi Bukan Posisi Tengah" << endl; 
        } 
        else 
        { 
            int nomor = 1; 
            while (nomor <= posisi) 
            { 
                if (nomor == posisi - 1) 
                { 
                    sebelum = bantu; 
                } 
                if (nomor == posisi) 
                { 
                    hapus = bantu; 
                } 
                bantu = bantu->next; 
                nomor++; 
            } 
            sebelum->next = bantu; 
            delete hapus; 
        } 
    } 
    else 
    { 
        cout << "List Masih Kosong!" << endl; 
    } 
}
// Ubah Depan 
void ubahDepan(int data) 
{ 
    if (!isEmpty()) 
    { 
        head->data = data; 
    } 
    else 
    { 
        cout << "List Masih Kosong!" << endl; 
    } 
} 

// Ubah Tengah 
void ubahTengah(int data, int posisi) 
{ 
    if (!isEmpty()) 
    { 
        if (posisi < 1 || posisi > hitungList()) 
        { 
            cout << "Posisi Di Luar Jangkauan" << endl; 
        } 
        else if (posisi == 1) 
        { 
            cout << "Posisi Bukan Posisi Tengah" << endl; 
        } 
        else 
        { 
            Node *bantu = head; 
            for (int nomor = 1; nomor < posisi; nomor++) 
            { 
                bantu = bantu->next; 
            } 
            bantu->data = data; 
        } 
    } 
    else 
    { 
        cout << "List Masih Kosong!" << endl; 
    } 
} 

// Ubah Belakang 
void ubahBelakang(int data) 
{ 
    if (!isEmpty()) 
    { 
        tail->data = data; 
    } 
    else 
    { 
        cout << "List Masih Kosong!" << endl; 
    } 
} 

// Hapus List 
void clearList() 
{ 
    Node *bantu = head, *hapus; 
    while (bantu != NULL) 
    { 
        hapus = bantu; 
        bantu = bantu->next; 
        delete hapus; 
    } 
    head = tail = NULL; 
    cout << "List Berhasil Terhapus!" << endl; 
} 

// Tampilkan List 
void tampil() 
{ 
    if (!isEmpty()) 
    { 
        Node *bantu = head; 
        while (bantu != NULL) 
        { 
            cout << bantu->data << " "; 
            bantu = bantu->next; 
        } 
        cout << endl; 
    } 
    else 
    { 
        cout << "List Masih Kosong!" << endl; 
    } 
} 

int main() 
{ 
    init(); 
    insertDepan(3); 
    tampil(); 
    insertBelakang(5); 
    tampil(); 
    insertDepan(2); 
    tampil(); 
    insertDepan(1); 
    tampil(); 
    hapusDepan(); 
    tampil(); 
    hapusBelakang(); 
    tampil(); 
    insertTengah(7, 2); 
    tampil(); 
    hapusTengah(2); 
    tampil(); 
    ubahDepan(1); 
    tampil(); 
    ubahBelakang(8); 
    tampil(); 
    ubahTengah(11, 2); 
    tampil(); 
    clearList(); 
    return 0; 
}
```

#### Output
![Screenshot 2024-04-29 054746](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/ac1a44ac-22f7-4347-821a-24e80b6ace3b)

Kode diatas adalah, implementasi dari single linked list non-circular dalam bahasa C++. Program ini memiliki struktur dasar dari linked list yang terdiri dari beberapa fungsi utama seperti `insertDepan`, `insertBelakang`, `insertTengah`, `hapusDepan`, `hapusBelakang`, `hapusTengah`, `ubahDepan`, `ubahBelakang`, `ubahTengah`, `clearList`, dan `tampil` untuk berbagai operasi yang dapat dilakukan pada linked list, seperti penambahan, penghapusan, pengubahan, serta penampilan elemen. Pada fungsi `clearList`, program menghapus semua node dalam linked list dengan mengosongkan memori dan menyetel pointer `head` ke NULL untuk menandai bahwa linked list kosong. Setelah menginisialisasi linked list menggunakan `init()`, program melakukan serangkaian operasi seperti menambahkan, menghapus, mengubah, dan menampilkan elemen-elemen dalam linked list untuk menguji fungsionalitasnya.



### 4. [Guided 4]

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST CIRCULAR

// Deklarasi Struct Node
struct Node
{
    string data;
    Node *next;
};
Node *head, *tail, *baru, *bantu, *hapus;

void init()
{
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty()
{
    return head == NULL ? 1 : 0;
}

// Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;
    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Tambah Depan
void insertDepan(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        tail->next = baru;
        baru->next = head;
        head = baru;
    }
}

// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        // Transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail->next = head->next;
        head = head->next;
        delete hapus;
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = tail;
        bantu = head;
        while (bantu->next != tail)
        {
            bantu = bantu->next;
        }
        tail = bantu;
        tail->next = head;
        delete hapus;
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}

// Hapus List
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;
        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List Berhasil Terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    if (isEmpty() == 0)
    {
        Node *temp = head;
        do
        {
            cout << temp->data << ends;
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}

int main()
{
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```

#### Output
![Screenshot 2024-04-29 054942](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/37147edf-6d0e-4a28-bea6-8710cad34de5)

Kode di atas merupakan implementasi dari single linked list circular dalam bahasa C++. Program ini memiliki struktur dasar dari linked list circular yang terdiri dari beberapa fungsi utama seperti `insertDepan`, `insertBelakang`, `insertTengah`, `hapusDepan`, `hapusBelakang`, `hapusTengah`, `clearList`, dan `tampil` untuk berbagai operasi yang dapat dilakukan pada linked list, seperti penambahan, penghapusan, dan penampilan elemen. Setiap elemen dalam linked list direpresentasikan oleh struktur data `Node` yang memiliki dua atribut, yaitu `data` yang menyimpan nilai data dan `next` yang merupakan pointer ke simpul berikutnya dalam linked list. Pada fungsi `main`, program melakukan serangkaian operasi seperti menambahkan, menghapus, dan menampilkan elemen-elemen dalam linked list untuk menguji fungsionalitasnya. Linked list yang diimplementasikan dalam program ini bersifat circular, yang berarti bahwa elemen terakhir dari linked list menunjuk kembali ke elemen pertama, dan setelah elemen terakhir terdapat elemen pertama lagi, membentuk suatu lingkaran.



## Unguided 

### 1. [Unguided 1]

```C++
#include <iostream>
#include <string> // untuk membuat variabel string
#include <iomanip> // untuk jarak tabel
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
    string data1, data2;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan
bool isEmpty() {
    return (head == NULL);
}

// Hitung Jumlah Node
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Data Depan
void tambahDepan(string nama, string nim) {
    Node *baru = new Node;
    baru->data1 = nama;
    baru->data2 = nim;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Data Belakang
void tambahBelakang(string nama, string nim) {
    Node *baru = new Node;
    baru->data1 = nama;
    baru->data2 = nim;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Tambah Data Tengah
void tambahTengah(string nama, string nim, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi Di Luar Jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi Bukan Posisi Tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->data1 = nama;
        baru->data2 = nim;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node Depan
void hapusDepan() {
    string namaSebelum;
    if (!isEmpty()) {
        Node *hapus = head;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        cout << "===================================" << endl;
        cout << "|           Hapus Depan           |" << endl;
        cout << "===================================" << endl;
        cout << "===================================" << endl;
        cout << " Data "<< hapus->data1 <<" telah dihapus" << endl;
        cout << "===================================" << endl;
        delete hapus;
    } else {
        cout << "List Kosong!" << endl;
    }
}

// Hapus Node Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        cout << "===================================" << endl;
        cout << "|         Hapus Belakang          |" << endl;
        cout << "===================================" << endl;
        cout << "===================================" << endl;
        cout << " Data "<< hapus->data1 <<" telah dihapus" << endl;
        cout << "===================================" << endl;
        delete hapus;
    } else {
        cout << "List Kosong!" << endl;
    }
}

// Hapus Node Tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi Di Luar Jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi Bukan Posisi Tengah" << endl;
    } else {
        Node *hapus;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        cout << "===================================" << endl;
        cout << " Data "<< hapus->data1 <<" telah dihapus" << endl;
        cout << "===================================" << endl;        
        delete hapus;
    }
}

// Ubah Data Depan
void ubahDepan(string nama, string nim) {
    if (!isEmpty()) {
        cout << "===================================" << endl;
        cout << " Data Lama : " << head->data1 << endl;
        cout << " Data Baru : " << nama << endl;
        cout << "===================================" << endl;
        head->data1 = nama;
        head->data2 = nim;
    } else {
        cout << "List Masih Kosong!" << endl;
    }
}

// Ubah Data Belakang
void ubahBelakang(string nama, string nim) {
    if (!isEmpty()) {
        cout << "===================================" << endl;
        cout << " Data Lama : " << tail->data1 << endl;
        cout << " Data Baru : " << nama << endl;
        cout << "===================================" << endl;
        tail->data1 = nama;
        tail->data2 = nim;
    } else {
        cout << "List Masih Kosong!" << endl;
    }
}

// Ubah Data Tengah
void ubahTengah(string nama, string nim, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi Di Luar Jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi Bukan Posisi Tengah" << endl;
        } else {
            Node *bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
                bantu = bantu->next;
            }
            cout << "===================================" << endl;
            cout << " Data Lama : " << bantu->data1 << endl;
            cout << " Data Baru : " << nama << endl;
            cout << "===================================" << endl;
            bantu->data1 = nama;
            bantu->data2 = nim;
        }
    } else {
        cout << "List Masih Kosong!" << endl;
    }
}

// Hapus Semua Node
void hapusList() {
    Node *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = NULL;
    cout << "===================================" << endl;
    cout << "|           Hapus List            |" << endl;
    cout << "===================================" << endl;
    cout << "===================================" << endl;
    cout << "      List Berhasil Dihapus      " << endl;
    cout << "===================================" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu = head;
    if (!isEmpty()) {
    cout << "===================================" << endl;
    cout << "|      Nama       |      NIM      |" << endl;
    cout << "===================================" << endl;
        while (bantu != NULL) {
        cout << "| "<< setw(16) << left << bantu->data1<< "| " << setw(14) << left << bantu->data2 <<"|"<< endl;
        bantu = bantu->next;
    }
    cout << "===================================" << endl;
    } else {
        cout << "List Masih Kosong!" << endl;
    }
}

void tampilanMenu() {
    std::cout << "===================================" << std::endl;
    std::cout << "|       OPERASI LINKED LIST       |" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "| 1.  Tambah Depan                |" << std::endl;
    std::cout << "| 2.  Tambah Belakang             |" << std::endl;
    std::cout << "| 3.  Tambah Tengah               |" << std::endl;
    std::cout << "| 4.  Ubah Depan                  |" << std::endl;
    std::cout << "| 5.  Ubah Belakang               |" << std::endl;
    std::cout << "| 6.  Ubah Tengah                 |" << std::endl;
    std::cout << "| 7.  Hapus Depan                 |" << std::endl;
    std::cout << "| 8.  Hapus Belakang              |" << std::endl;
    std::cout << "| 9.  Hapus Tengah                |" << std::endl;
    std::cout << "| 10. Hapus List                  |" << std::endl;
    std::cout << "| 11. Tampilkan                   |" << std::endl;
    std::cout << "| 0.  Keluar                      |" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << " Pilih Operasi : ";
}

void menu() {
    int pilihan, posisi;
    string nama, nim, hapus;
    do {
        tampilanMenu();
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            cout << "===================================" << endl;
            cout << "|          Tambah Depan           |" << endl;
            cout << "===================================" << endl;
            cout << " Masukkan Nama : ";
            cin >> nama;
            cout << " Masukkan NIM  : ";
            cin >> nim;
            tambahDepan(nama, nim);
            cout << "===================================" << endl;
            cout << "|      Data Telah Ditambahkan     |" << endl;
            cout << "===================================" << endl;
            break;

        case 2:
            cout << "===================================" << endl;
            cout << "|         Tambah Belakang         |" << endl;
            cout << "===================================" << endl;
            cout << " Masukkan Nama : ";
            cin >> nama;
            cout << " Masukkan NIM  : ";
            cin >> nim;
            tambahBelakang(nama, nim);
            cout << "===================================" << endl;
            cout << "|      Data Telah Ditambahkan     |" << endl;
            cout << "===================================" << endl;
            break;

        case 3:
            cout << "===================================" << endl;
            cout << "|          Tambah tengah          |" << endl;
            cout << "===================================" << endl;
            cout << " Masukkan Nama : ";
            cin >> nama;
            cout << " Masukkan NIM  : ";
            cin >> nim;
            cout << " Masukkan Posisi : ";
            cin >> posisi;
            tambahTengah(nama, nim, posisi);
            cout << "===================================" << endl;
            cout << "|      Data Telah Ditambahkan     |" << endl;
            cout << "===================================" << endl;
            break;

        case 4:
            cout << "===================================" << endl;
            cout << "|            Ubah Depan           |" << endl;
            cout << "===================================" << endl;
            cout << " Masukkan Nama : ";
            cin >> nama;
            cout << " Masukkan NIM  : ";
            cin >> nim;
            ubahDepan(nama, nim);
            break;

        case 5:
            cout << "===================================" << endl;
            cout << "|           Ubah Belakang         |" << endl;
            cout << "===================================" << endl;
            cout << " Masukkan Nama : ";
            cin >> nama;
            cout << " Masukkan NIM  : ";
            cin >> nim;
            ubahBelakang(nama, nim);
            break;

        case 6:
            cout << "===================================" << endl;
            cout << "|            Ubah Tengah          |" << endl;
            cout << "===================================" << endl;
            cout << " Masukkan Nama : ";
            cin >> nama;
            cout << " Masukkan NIM  : ";
            cin >> nim;
            cout << " Masukkan Posisi : ";
            cin >> posisi;
            ubahTengah(nama, nim, posisi);
            break;

        case 7:
            hapusDepan();
            break;

        case 8:
            hapusBelakang();
            break;

        case 9:
            cout << "===================================" << endl;
            cout << "|          Hapus Tengah           |" << endl;
            cout << "===================================" << endl;
            cout << " Masukkan Posisi : ";
            cin >> posisi;
            break;

        case 10:
            hapusList();
            break;

        case 11:
            tampil();
            break;

        case 0:
            cout << "===================================" << endl;
            cout << "|              Keluar             |" << endl;
            cout << "===================================" << endl;
            break;

        default:
            cout << "===================================" << endl;
            cout << "|       Pilihan Tidak Valid       |" << endl;
            cout << "===================================" << endl;
            }

        } while (pilihan != 0);    
}

int main() {
    init();
    menu();
    return 0;
}
```
#### Output:
![Screenshot 2024-04-29 120454](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/864864b4-290b-40ad-a539-3fd56cfc9359)

Kode di atas merupakan implementasi dari sebuah program C++ yang menggunakan single linked list non-circular untuk melakukan berbagai operasi seperti penambahan, penghapusan, dan pembaruan data dalam linked list. Program ini terdiri dari definisi struktur data `Node` yang memiliki dua atribut data bertipe string dan satu pointer next, serta fungsi-fungsi untuk menginisialisasi, mengecek apakah linked list kosong, menambahkan data di depan, di belakang, dan di tengah, menghapus data di depan, di belakang, dan di tengah, serta menampilkan seluruh data dalam linked list. Terdapat juga fungsi menu yang memberikan pilihan operasi kepada pengguna untuk melakukan manipulasi data dalam linked list. Program ini menggunakan manipulasi tampilan dengan menggunakan tabel agar informasi yang ditampilkan lebih terstruktur.

### 2. [Unguided 2]

```C++
#include <iostream>
#include <string> // untuk membuat variabel string
#include <iomanip> // untuk jarak tabel
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
    string data1, data2;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan
bool isEmpty() {
    return (head == NULL);
}

// Hitung Jumlah Node
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Data Depan
void tambahDepan(string nama, string nim) {
    Node *baru = new Node;
    baru->data1 = nama;
    baru->data2 = nim;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Data Belakang
void tambahBelakang(string nama, string nim) {
    Node *baru = new Node;
    baru->data1 = nama;
    baru->data2 = nim;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Tambah Data Tengah
void tambahTengah(string nama, string nim, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi Di Luar Jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi Bukan Posisi Tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->data1 = nama;
        baru->data2 = nim;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node Depan
void hapusDepan() {
    string namaSebelum;
    if (!isEmpty()) {
        Node *hapus = head;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        cout << "===================================" << endl;
        cout << "|           Hapus Depan           |" << endl;
        cout << "===================================" << endl;
        cout << "===================================" << endl;
        cout << " Data "<< hapus->data1 <<" telah dihapus" << endl;
        cout << "===================================" << endl;
        delete hapus;
    } else {
        cout << "List Kosong!" << endl;
    }
}

// Hapus Node Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        cout << "===================================" << endl;
        cout << "|         Hapus Belakang          |" << endl;
        cout << "===================================" << endl;
        cout << "===================================" << endl;
        cout << " Data "<< hapus->data1 <<" telah dihapus" << endl;
        cout << "===================================" << endl;
        delete hapus;
    } else {
        cout << "List Kosong!" << endl;
    }
}

// Hapus Node Tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi Di Luar Jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi Bukan Posisi Tengah" << endl;
    } else {
        Node *hapus;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        cout << "===================================" << endl;
        cout << " Data "<< hapus->data1 <<" telah dihapus" << endl;
        cout << "===================================" << endl;        
        delete hapus;
    }
}

// Ubah Data Depan
void ubahDepan(string nama, string nim) {
    if (!isEmpty()) {
        cout << "===================================" << endl;
        cout << " Data Lama : " << head->data1 << endl;
        cout << " Data Baru : " << nama << endl;
        cout << "===================================" << endl;
        head->data1 = nama;
        head->data2 = nim;
    } else {
        cout << "List Masih Kosong!" << endl;
    }
}

// Ubah Data Belakang
void ubahBelakang(string nama, string nim) {
    if (!isEmpty()) {
        cout << "===================================" << endl;
        cout << " Data Lama : " << tail->data1 << endl;
        cout << " Data Baru : " << nama << endl;
        cout << "===================================" << endl;
        tail->data1 = nama;
        tail->data2 = nim;
    } else {
        cout << "List Masih Kosong!" << endl;
    }
}

// Ubah Data Tengah
void ubahTengah(string nama, string nim, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi Di Luar Jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi Bukan Posisi Tengah" << endl;
        } else {
            Node *bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
                bantu = bantu->next;
            }
            cout << "===================================" << endl;
            cout << " Data Lama : " << bantu->data1 << endl;
            cout << " Data Baru : " << nama << endl;
            cout << "===================================" << endl;
            bantu->data1 = nama;
            bantu->data2 = nim;
        }
    } else {
        cout << "List Masih Kosong!" << endl;
    }
}

// Hapus Semua Node
void hapusList() {
    Node *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = NULL;
    cout << "===================================" << endl;
    cout << "|           Hapus List            |" << endl;
    cout << "===================================" << endl;
    cout << "===================================" << endl;
    cout << "      List Berhasil Dihapus      " << endl;
    cout << "===================================" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu = head;
    if (!isEmpty()) {
    cout << "===================================" << endl;
    cout << "|      Nama       |      NIM      |" << endl;
    cout << "===================================" << endl;
        while (bantu != NULL) {
        cout << "| "<< setw(16) << left << bantu->data1<< "| " << setw(14) << left << bantu->data2 <<"|"<< endl;
        bantu = bantu->next;
    }
    cout << "===================================" << endl;
    } else {
        cout << "List Masih Kosong!" << endl;
    }
}

void tampilanMenu() {
    std::cout << "===================================" << std::endl;
    std::cout << "|       OPERASI LINKED LIST       |" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "| 1.  Tambah Depan                |" << std::endl;
    std::cout << "| 2.  Tambah Belakang             |" << std::endl;
    std::cout << "| 3.  Tambah Tengah               |" << std::endl;
    std::cout << "| 4.  Ubah Depan                  |" << std::endl;
    std::cout << "| 5.  Ubah Belakang               |" << std::endl;
    std::cout << "| 6.  Ubah Tengah                 |" << std::endl;
    std::cout << "| 7.  Hapus Depan                 |" << std::endl;
    std::cout << "| 8.  Hapus Belakang              |" << std::endl;
    std::cout << "| 9.  Hapus Tengah                |" << std::endl;
    std::cout << "| 10. Hapus List                  |" << std::endl;
    std::cout << "| 11. Tampilkan                   |" << std::endl;
    std::cout << "| 0.  Keluar                      |" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << " Pilih Operasi : ";
}

void menu() {
    int pilihan, posisi;
    string nama, nim, hapus;
    do {
        tampilanMenu();
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            cout << "===================================" << endl;
            cout << "|          Tambah Depan           |" << endl;
            cout << "===================================" << endl;
            cout << " Masukkan Nama : ";
            cin >> nama;
            cout << " Masukkan NIM  : ";
            cin >> nim;
            tambahDepan(nama, nim);
            cout << "===================================" << endl;
            cout << "|      Data Telah Ditambahkan     |" << endl;
            cout << "===================================" << endl;
            break;

        case 2:
            cout << "===================================" << endl;
            cout << "|         Tambah Belakang         |" << endl;
            cout << "===================================" << endl;
            cout << " Masukkan Nama : ";
            cin >> nama;
            cout << " Masukkan NIM  : ";
            cin >> nim;
            tambahBelakang(nama, nim);
            cout << "===================================" << endl;
            cout << "|      Data Telah Ditambahkan     |" << endl;
            cout << "===================================" << endl;
            break;

        case 3:
            cout << "===================================" << endl;
            cout << "|          Tambah tengah          |" << endl;
            cout << "===================================" << endl;
            cout << " Masukkan Nama : ";
            cin >> nama;
            cout << " Masukkan NIM  : ";
            cin >> nim;
            cout << " Masukkan Posisi : ";
            cin >> posisi;
            tambahTengah(nama, nim, posisi);
            cout << "===================================" << endl;
            cout << "|      Data Telah Ditambahkan     |" << endl;
            cout << "===================================" << endl;
            break;

        case 4:
            cout << "===================================" << endl;
            cout << "|            Ubah Depan           |" << endl;
            cout << "===================================" << endl;
            cout << " Masukkan Nama : ";
            cin >> nama;
            cout << " Masukkan NIM  : ";
            cin >> nim;
            ubahDepan(nama, nim);
            break;

        case 5:
            cout << "===================================" << endl;
            cout << "|           Ubah Belakang         |" << endl;
            cout << "===================================" << endl;
            cout << " Masukkan Nama : ";
            cin >> nama;
            cout << " Masukkan NIM  : ";
            cin >> nim;
            ubahBelakang(nama, nim);
            break;

        case 6:
            cout << "===================================" << endl;
            cout << "|            Ubah Tengah          |" << endl;
            cout << "===================================" << endl;
            cout << " Masukkan Nama : ";
            cin >> nama;
            cout << " Masukkan NIM  : ";
            cin >> nim;
            cout << " Masukkan Posisi : ";
            cin >> posisi;
            ubahTengah(nama, nim, posisi);
            break;

        case 7:
            hapusDepan();
            break;

        case 8:
            hapusBelakang();
            break;

        case 9:
            cout << "===================================" << endl;
            cout << "|          Hapus Tengah           |" << endl;
            cout << "===================================" << endl;
            cout << " Masukkan Posisi : ";
            cin >> posisi;
            break;

        case 10:
            hapusList();
            break;

        case 11:
            tampil();
            break;

        case 0:
            cout << "===================================" << endl;
            cout << "|              Keluar             |" << endl;
            cout << "===================================" << endl;
            break;

        default:
            cout << "===================================" << endl;
            cout << "|       Pilihan Tidak Valid       |" << endl;
            cout << "===================================" << endl;
            }

        } while (pilihan != 0);    
}

int main() {
    init();
    menu();
    return 0;
}
```
#### Output:
![Screenshot 2024-04-29 125232](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/3d7d13b4-9199-4482-8a77-73f0f99b5d48)

Kodenya sama seperti unguided 1, berbeda hanya pada output karena kita menginputkan beberapa data yang sudah disediakan.



### 3. [Unguided 3]

```C++
#include <iostream>
#include <string> // untuk membuat variabel string
#include <iomanip> // untuk jarak tabel
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
    string data1, data2;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan
bool isEmpty() {
    return (head == NULL);
}

// Hitung Jumlah Node
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Data Depan
void tambahDepan(string nama, string nim) {
    Node *baru = new Node;
    baru->data1 = nama;
    baru->data2 = nim;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Data Belakang
void tambahBelakang(string nama, string nim) {
    Node *baru = new Node;
    baru->data1 = nama;
    baru->data2 = nim;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Tambah Data Tengah
void tambahTengah(string nama, string nim, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi Di Luar Jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi Bukan Posisi Tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->data1 = nama;
        baru->data2 = nim;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node Depan
void hapusDepan() {
    string namaSebelum;
    if (!isEmpty()) {
        Node *hapus = head;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        cout << "===================================" << endl;
        cout << "|           Hapus Depan           |" << endl;
        cout << "===================================" << endl;
        cout << "===================================" << endl;
        cout << " Data "<< hapus->data1 <<" telah dihapus" << endl;
        cout << "===================================" << endl;
        delete hapus;
    } else {
        cout << "List Kosong!" << endl;
    }
}

// Hapus Node Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        cout << "===================================" << endl;
        cout << "|         Hapus Belakang          |" << endl;
        cout << "===================================" << endl;
        cout << "===================================" << endl;
        cout << " Data "<< hapus->data1 <<" telah dihapus" << endl;
        cout << "===================================" << endl;
        delete hapus;
    } else {
        cout << "List Kosong!" << endl;
    }
}

// Hapus Node Tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi Di Luar Jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi Bukan Posisi Tengah" << endl;
    } else {
        Node *hapus;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        cout << "===================================" << endl;
        cout << " Data "<< hapus->data1 <<" telah dihapus" << endl;
        cout << "===================================" << endl;        
        delete hapus;
    }
}

// Ubah Data Depan
void ubahDepan(string nama, string nim) {
    if (!isEmpty()) {
        cout << "===================================" << endl;
        cout << " Data Lama : " << head->data1 << endl;
        cout << " Data Baru : " << nama << endl;
        cout << "===================================" << endl;
        head->data1 = nama;
        head->data2 = nim;
    } else {
        cout << "List Masih Kosong!" << endl;
    }
}

// Ubah Data Belakang
void ubahBelakang(string nama, string nim) {
    if (!isEmpty()) {
        cout << "===================================" << endl;
        cout << " Data Lama : " << tail->data1 << endl;
        cout << " Data Baru : " << nama << endl;
        cout << "===================================" << endl;
        tail->data1 = nama;
        tail->data2 = nim;
    } else {
        cout << "List Masih Kosong!" << endl;
    }
}

// Ubah Data Tengah
void ubahTengah(string nama, string nim, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi Di Luar Jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi Bukan Posisi Tengah" << endl;
        } else {
            Node *bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
                bantu = bantu->next;
            }
            cout << "===================================" << endl;
            cout << " Data Lama : " << bantu->data1 << endl;
            cout << " Data Baru : " << nama << endl;
            cout << "===================================" << endl;
            bantu->data1 = nama;
            bantu->data2 = nim;
        }
    } else {
        cout << "List Masih Kosong!" << endl;
    }
}

// Hapus Semua Node
void hapusList() {
    Node *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = NULL;
    cout << "===================================" << endl;
    cout << "|           Hapus List            |" << endl;
    cout << "===================================" << endl;
    cout << "===================================" << endl;
    cout << "      List Berhasil Dihapus      " << endl;
    cout << "===================================" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu = head;
    if (!isEmpty()) {
    cout << "===================================" << endl;
    cout << "|      Nama       |      NIM      |" << endl;
    cout << "===================================" << endl;
        while (bantu != NULL) {
        cout << "| "<< setw(16) << left << bantu->data1<< "| " << setw(14) << left << bantu->data2 <<"|"<< endl;
        bantu = bantu->next;
    }
    cout << "===================================" << endl;
    } else {
        cout << "List Masih Kosong!" << endl;
    }
}

void tampilanMenu() {
    std::cout << "===================================" << std::endl;
    std::cout << "|       OPERASI LINKED LIST       |" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "| 1.  Tambah Depan                |" << std::endl;
    std::cout << "| 2.  Tambah Belakang             |" << std::endl;
    std::cout << "| 3.  Tambah Tengah               |" << std::endl;
    std::cout << "| 4.  Ubah Depan                  |" << std::endl;
    std::cout << "| 5.  Ubah Belakang               |" << std::endl;
    std::cout << "| 6.  Ubah Tengah                 |" << std::endl;
    std::cout << "| 7.  Hapus Depan                 |" << std::endl;
    std::cout << "| 8.  Hapus Belakang              |" << std::endl;
    std::cout << "| 9.  Hapus Tengah                |" << std::endl;
    std::cout << "| 10. Hapus List                  |" << std::endl;
    std::cout << "| 11. Tampilkan                   |" << std::endl;
    std::cout << "| 0.  Keluar                      |" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << " Pilih Operasi : ";
}

void menu() {
    int pilihan, posisi;
    string nama, nim, hapus;
    do {
        tampilanMenu();
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            cout << "===================================" << endl;
            cout << "|          Tambah Depan           |" << endl;
            cout << "===================================" << endl;
            cout << " Masukkan Nama : ";
            cin >> nama;
            cout << " Masukkan NIM  : ";
            cin >> nim;
            tambahDepan(nama, nim);
            cout << "===================================" << endl;
            cout << "|      Data Telah Ditambahkan     |" << endl;
            cout << "===================================" << endl;
            break;

        case 2:
            cout << "===================================" << endl;
            cout << "|         Tambah Belakang         |" << endl;
            cout << "===================================" << endl;
            cout << " Masukkan Nama : ";
            cin >> nama;
            cout << " Masukkan NIM  : ";
            cin >> nim;
            tambahBelakang(nama, nim);
            cout << "===================================" << endl;
            cout << "|      Data Telah Ditambahkan     |" << endl;
            cout << "===================================" << endl;
            break;

        case 3:
            cout << "===================================" << endl;
            cout << "|          Tambah tengah          |" << endl;
            cout << "===================================" << endl;
            cout << " Masukkan Nama : ";
            cin >> nama;
            cout << " Masukkan NIM  : ";
            cin >> nim;
            cout << " Masukkan Posisi : ";
            cin >> posisi;
            tambahTengah(nama, nim, posisi);
            cout << "===================================" << endl;
            cout << "|      Data Telah Ditambahkan     |" << endl;
            cout << "===================================" << endl;
            break;

        case 4:
            cout << "===================================" << endl;
            cout << "|            Ubah Depan           |" << endl;
            cout << "===================================" << endl;
            cout << " Masukkan Nama : ";
            cin >> nama;
            cout << " Masukkan NIM  : ";
            cin >> nim;
            ubahDepan(nama, nim);
            break;

        case 5:
            cout << "===================================" << endl;
            cout << "|           Ubah Belakang         |" << endl;
            cout << "===================================" << endl;
            cout << " Masukkan Nama : ";
            cin >> nama;
            cout << " Masukkan NIM  : ";
            cin >> nim;
            ubahBelakang(nama, nim);
            break;

        case 6:
            cout << "===================================" << endl;
            cout << "|            Ubah Tengah          |" << endl;
            cout << "===================================" << endl;
            cout << " Masukkan Nama : ";
            cin >> nama;
            cout << " Masukkan NIM  : ";
            cin >> nim;
            cout << " Masukkan Posisi : ";
            cin >> posisi;
            ubahTengah(nama, nim, posisi);
            break;

        case 7:
            hapusDepan();
            break;

        case 8:
            hapusBelakang();
            break;

        case 9:
            cout << "===================================" << endl;
            cout << "|          Hapus Tengah           |" << endl;
            cout << "===================================" << endl;
            cout << " Masukkan Posisi : ";
            cin >> posisi;
            break;

        case 10:
            hapusList();
            break;

        case 11:
            tampil();
            break;

        case 0:
            cout << "===================================" << endl;
            cout << "|              Keluar             |" << endl;
            cout << "===================================" << endl;
            break;

        default:
            cout << "===================================" << endl;
            cout << "|       Pilihan Tidak Valid       |" << endl;
            cout << "===================================" << endl;
            }

        } while (pilihan != 0);    
}

int main() {
    init();
    menu();
    return 0;
}
```
#### Output:
![Screenshot 2024-04-29 130121](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/f1644f99-dda0-4b10-805f-cc7c6dba75f7)

Kodenya sama seperti unguided 1 dan 2, bedanya hanya kita mengedit data yang sudah dimasukkan diunguided 2.



## Kesimpulan
Linked list merupakan struktur data yang fleksibel dan efisien untuk menyimpan data yang sering diakses secara berurutan. Keuntungan utama linked list adalah kemampuannya untuk menambah/menghapus elemen secara dinamis tanpa perlu menggeser elemen lain. Namun, linked list kurang efisien untuk akses data acak dan membutuhkan memori tambahan untuk menyimpan tautan antar node.

Pemilihan struktur data yang tepat (linked list atau array) tergantung pada kebutuhan dan karakteristik data yang akan disimpan dan diolah.

## Referensi
[1] Alamsyah et al., “Implementasi Single Linked List dan Double Linked List dengan Bahasa Pemrograman C++”, Jurnal Basis, 2019.

[2] Herdiana et al., “Implementasi Algoritma Search pada Linked List dengan C++”, JTII, 2020.

[3] Wahyudi et al., “Perancangan Database Mahasiswa Berbasis Linked List Circular Menggunakan C++”, JTI, 2017.