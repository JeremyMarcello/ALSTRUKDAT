#include <iostream>
using namespace std;

void insertion_sort(float arr[], int panjang) {
    int i, j;
    float n;

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

void print_array(float a[], int panjang) {

    for(int i=0; i<panjang; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main () {
    int panjang = 5;
    float a[panjang] = {3.8, 2.9, 3.3, 4.0, 2.4};

    cout << "Urutan IPS sebelum sorting: " << endl;
    print_array(a, panjang);

    insertion_sort(a, panjang);

    cout << "\nUrutan IPS setelah sorting: " << endl;
    print_array(a, panjang);

 
}