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