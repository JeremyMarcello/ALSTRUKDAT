# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">2311110003 / Jeremy Marcello Waani / Sains Data</p>

## Dasar Teori
Sorting adalah salah satu topik paling penting dalam komputer sains, lebih murah untuk menemukan barang dalam array yang terurut dari pada dalam array yang tidak terurut. Kita dapat menggunakan algoritma sorting untuk mengurutkan array dalam memori untuk dicari nanti dalam program[1].Terdapat 3 algoritma sorting yang biasanya digunakan yaitu :
1. Bubble Sort
2. Selection Sort
3. Insertion Sort

### 1. Bubble Sort
Bubble sort adalah algoritma sorting paling sederana[1]. cara kerjanya dengan menukar elemen yang berdekatan berulang kali jika urutannya salah. algoritma ini tidak cocok untuk data yang besar karena komplesitas waktunya cukup tinggi. Karena bubble sort menggunakan nested loops, karena itu kompleksitas waktunya O(n^2).

Contoh code
```c++
#include <iostream>
using namespace std;
void insertion_sort(int arr[], int length) {
 int i, j ,tmp;
 for (i = 1; i < length; i++) {
 j = i;
 while (j > 0 && arr[j - 1] > arr[j]) {
 tmp = arr[j];
 arr[j] = arr[j - 1];
 arr[j - 1] = tmp;
 j--;
 }//end of while loop
 }//end of for loop
}
void print_array(int a[], int length) {
 for(int i=0; i<length; i++) {
 cout << a[i] << "\t";
 }
 cout << endl;
}
int main() {
 int length = 6;
 int a[length] = {22, 10, 15, 3, 8, 2};
 insertion_sort(a, length);
 print_array(a, length);
}

```

### 2. Selection Sort
Selection sort merupakan sebuah teknik pengurutan dengan cara mencari nilai tertinggi/terendah di dalam array kemudian menempatkan nilai tersebut di tempat semestinya. Algoritma ini lebih baik daripada bubble sort walau kompleksitas waktunya masih O(n^2)[1].

Contoh code
```c++
#include <bits/stdc++.h> 
using namespace std; 
  
// Function for Selection sort 
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of 
    // unsorted subarray 
    for (i = 0; i < n - 1; i++) { 
  
        // Find the minimum element in 
        // unsorted array 
        min_idx = i; 
        for (j = i + 1; j < n; j++) { 
            if (arr[j] < arr[min_idx]) 
                min_idx = j; 
        } 
  
        // Swap the found minimum element 
        // with the first element 
        if (min_idx != i) 
            swap(arr[min_idx], arr[i]); 
    } 
} 
  
// Function to print an array 
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) { 
        cout << arr[i] << " "; 
        cout << endl; 
    } 
} 
  
// Driver program 
int main() 
{ 
    int arr[] = { 64, 25, 12, 22, 11 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // Function Call 
    selectionSort(arr, n); 
    cout << "Sorted array: \n"; 
    printArray(arr, n); 
    return 0; 
}
```

### 3. Insertion Sort
Insertion Sort merupakan sebuah teknik pengurutan dengan cara membandingkan dan mengurutkan dua data pertama pada array, kemudian membandingkan data para array berikutnya apakah sudah berada di tempat semestinya. algoritma ini memiliki kompleksitas waktu O(n^2) sama seperti bubble sort dan insertion sort karena menggunakan nested loop[1].

Contoh code
```c++
#include <bits/stdc++.h>
using namespace std;
 
// Function to sort an array using
// insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1],
        // that are greater than key, 
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
// A utility function to print an array
// of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
// Driver code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    insertionSort(arr, N);
    printArray(arr, N);
 
    return 0;
}
```

## Guided 

### 1. [Mengurutkan secara ascending untuk data numerik bertipe double menggunakan Algoritma Bubble Sort]

```C++
#include <iostream>
using namespace std;

void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j=0; 
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++){
            if (arr[1] > arr[i + 1]){
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }//end of if
        }// end of for loop
    }// end of while loop
}// end of bubble_sort

void print_array(double a[], int length) {

    for(int i = 0; i < length; i++) {
        cout << a [i] << "\t";
    }
    cout << endl;
}

int main(){

    int length = 5;
    double a[] = {22.1, 15.3, 8.2, 33.21, 99,99};

    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);

}
```

#### Output
![Screenshot 2024-04-01 143253](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/8a202885-ffe2-476f-a31b-9b9c8a74c557)

Kode diatas digunakan untuk menyortir nilai dalam array a[] secara ascending dengan menggunakan algoritma bubble sort, `void bubble_sort` berisi perulangan sebanyak `length` yaitu panjang dari arraynya. Kemudian dalam perulangan tersebut akan dibandingkan jika index pertama lebih besar dari index ke-i+1 jika benar maka akan ditukar nilainya. akan diulang hingga semua nilai terurut, lalu `void print_array` digunakan untuk print array yang sudah diurutkan. kompleksitas waktunya adalah O(n^2) karena tedapat nested loop didalamnya yang dimana nested loop akan mengulang sebanyak n x n kali pada worst scenarionya.



### 2. [Mengurutkan karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Insertion Sort]

```C++
#include <iostream>
using namespace std;

void insertion_sort(char arr[], int length) {
    int i, j;
    char tmp;

    for (i = 1; i < length; i++) {
        j = i;

        while (j > 0 && arr[j - 1] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }// end of while loop
    }// end of for loop
}

void print_array(char a[], int length) {

    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main () {
    int length = 6;
    char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};

    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    insertion_sort(a, length);

    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);

 
}
```

#### Output
![Screenshot 2024-04-01 143318](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/bd747595-feec-4b8a-bc9e-aa8b457c355e)

Kode diatas digunakan untuk mengurutkan karakter secara descending dengan algoritma insertion sort. pertama membuat fungsi `void insertion_sort` yang berisi nested loop untuk mengurutkan karakter dengan insertion sort, langkah pertama membuat perulangan sebanyak `i < length` kemudian membuat perulangan while loop yang akan menukar nilai jika `j > 0 && arr[j - 1] < arr[j]` pernyataan berikut benar, lalu `void print_array` digunakan untuk print array yang sudah diurutkan. kompleksitas waktunya sama seperti bubble sort adalah `O(n^2)` karena tedapat nested loop didalamnya yang dimana nested loop akan mengulang sebanyak n x n kali pada worst scenarionya.


## Unguided 

### 1. [Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort! ]

```C++
#include <iostream>
using namespace std;

void selection_sort(float ips[], int panjang){
  for (int i = 0; i < panjang - 1; i++) {
    int min_index = i;
    for (int j = i + 1; j < panjang; j++) {
      if (ips[min_index] < ips[j]) {
        min_index = j;
      }
    }
    float tmp = ips[i];
    ips[i] = ips[min_index];
    ips[min_index] = tmp;
}
}

void print_array(float ips[], int panjang) {

    for(int i=0; i<panjang; i++) {
        cout << ips[i] << "\t";
    }
    cout << endl;
}

int main() {
  float ips_mhs[] = {3.8, 2.9, 3.3, 4.0, 2.4};
  int n = sizeof(ips_mhs) / sizeof(ips_mhs[0]);

    cout << "Urutan IPS sebelum sorting: " << endl;
    print_array(ips_mhs, n);

    selection_sort(ips_mhs, n);

    cout << "\nUrutan IPS setelah sorting: " << endl;
    print_array(ips_mhs, n);

  return 0;
}
```
#### Output:
![Screenshot 2024-04-01 153007](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/97179ec1-9033-44f2-b854-ce4a74a26482)

Kode diatas digunakan untuk mengurutkan IPS mahasiswa S1 IF 2016, dengan menggunakan selection sort. pertama membuat fungsi `void selection_sort` yang berisi nested loop untuk mengurutkan nilai dengan selection sort, perulangan pertama akan diulang sebanyak `panjang` kali kemudian mendeklarasikan `min_index` dan perulangan kedua sebanyak `i` kali untuk membandingkan `ips[min_index]` dan `ips[j]` jika benar maka keduanya akan ditukar, dan berlangsung seterusnya. Kemudian `void print_array` digunakan untuk print array yang sebelum atau sesudah diurutkan . Kompleksitas waktunya `O(n^2)` karena program tersebut akan mengulangi sebanyak n x n kali.


### 2. [Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan namanama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort!]

```C++
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
```
#### Output:
![Screenshot 2024-04-01 143356](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/a91df4b9-d2c4-490c-afb4-2b612077094a)

Kode diatas digunakan untuk mengurutkan nama warga RT, dengan menggunakan insertion sort. pertama membuat fungsi `void insert_sort` yang berisi nested loop untuk mengurutkan string dengan insertion sort, perulangan pertama akan diulang sebanyak `panjang` kali dan perulangan kedua sebanyak `i` kali untuk membandingkan `nama[j]` dan `ips[j+1]` jika benar maka keduanya akan ditukar, dan berlangsung seterusnya. Kemudian `void print_array` digunakan untuk print array yang sebelum atau sesudah diurutkan . Kompleksitas waktunya `O(n^2)` karena program tersebut akan mengulangi sebanyak n x n kali.


### 3. [Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)!]

```C++
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
```
#### Output:
![Screenshot 2024-04-01 143523](https://github.com/JeremyMarcello/ALSTRUKDAT/assets/156126843/a1f52e3e-54cb-47da-86da-a4d5bf6c0598)

Kode diatas digunakan untuk mengurutkan karakter secara descending dengan algoritma insertion sort dengan banyak karakter dan karakternya diinput oleh user. pertama membuat fungsi `void descending` yang berisi nested loop untuk mengurutkan karakter dengan insertion sort, langkah pertama membuat perulangan sebanyak `i < length` kemudian membuat perulangan while loop yang akan menukar nilai jika `j > 0 && arr[j - 1] < arr[j]` pernyataan berikut benar, lalu `void print_array` digunakan untuk print array yang sudah diurutkan.  pertama membuat fungsi `void ascending` yang berisi nested loop untuk mengurutkan karakter dengan insertion sort, langkah pertama membuat perulangan sebanyak `i < length` kemudian membuat perulangan while loop yang akan menukar nilai jika `j > 0 && arr[j - 1] > arr[j]` pernyataan berikut benar, lalu `void print_array` digunakan untuk print array yang sudah diurutkan. .kompleksitas waktunya sama seperti bubble sort adalah `O(n^2)` karena tedapat nested loop didalamnya yang dimana nested loop akan mengulang sebanyak n x n kali pada worst scenarionya.

## Kesimpulan
Sorting adalah algoritma yang dapat membantu kita mengurutkan data secara ascending maupun descending dengan cepat. Dengan mengurutkan suatu data kita dapat lebih mudah untuk mengolah dan mencari nilai didalamnya. Ada banyak algoritma yang dapat kita gunakan untuk mengurutkan data, tapi ada 3 algoritma yang sering digunakan yaitu : Bubble Sort, Selection Sort, dan Insertion Sort, yang dimana ketiganya memiliki kompleksitas waktu pada worst case yang sama yaitu `O(n^2)` sehingga dapat dikatakan ketiga algoritma ini tidak begitu efektif.

## Referensi
[1] Bae Sammie. *Searching and Sorting. JavaScript Data Structures and Algorithms*. Canada: Apress, Berkeley, CA. 2019.