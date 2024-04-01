#include <iostream>
using namespace std;

void descending(char arr[], int panjang) {
    int i, j;
    char n;

    for (i = 1; i < panjang; i++) {
        j = i;

        while (j > 0 && arr[j - 1] < arr[j]) {
            n = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = n;
            j--;
        }
    }
}

void ascending(char arr[], int panjang) {
    int i, j;
    char n;

    for (i = 1; i < panjang; i++) {
        j = i;

        while (j > 0 && arr[j - 1] > arr[j]) {
            n = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = n;
            j--;
        }
    }
}

void print_array(char a[], int panjang) {

    for(int i=0; i<panjang; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main () {
    int panjang;
    char *karakter = new char[panjang];

    cout << "Masukkan banyak karakter : " << endl;
    cin >> panjang;

    for(int i=0; i<panjang; i++) {
        cout << "Masukkan karakter : " << endl;       
        cin >> karakter[i];
    }

    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(karakter, panjang);

    descending(karakter, panjang);

    cout << "\nUrutan karakter setelah sorting descending: " << endl;
    print_array(karakter, panjang);

    ascending(karakter, panjang);

    cout << "\nUrutan karakter setelah sorting ascending: " << endl;
    print_array(karakter, panjang);
}