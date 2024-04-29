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