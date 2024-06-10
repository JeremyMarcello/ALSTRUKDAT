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
