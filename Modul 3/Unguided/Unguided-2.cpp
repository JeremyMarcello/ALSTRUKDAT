#include <iostream>
using namespace std;

void bubble_sort(string nama[], int panjang){
  for (int i = 0; i < panjang - 1; i++) {
    for (int j = 0; j < panjang - i - 1; j++) {
      if (nama[j] > nama[j + 1]) {
        string tmp = nama[j];
        nama[j] = nama[j + 1];
        nama[j + 1] = tmp;
      }
    }
  }
}

void print_array(string nama[], int panjang) {

    for(int i=0; i<panjang; i++) {
        cout << nama[i] << "\t";
    }
    cout << endl;
}

int main() {
  string nama[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};
  int n = sizeof(nama) / sizeof(nama[0]);

    cout << "Urutan Nama sebelum sorting: " << endl;
    print_array(nama, n);

    bubble_sort(nama, n);

    cout << "\nUrutan Nama setelah sorting: " << endl;
    print_array(nama, n);

  return 0;
}