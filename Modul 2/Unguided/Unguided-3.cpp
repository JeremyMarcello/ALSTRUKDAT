#include <iostream>
using namespace std;

int main(){
    int a, b, c;

    cout << "Masukkan ukuran array tiga dimensi:" << endl;
    cout << "Ukuran dimensi 1: ";
    cin >> a;
    cout << "Ukuran dimensi 2: ";
    cin >> b;
    cout << "Ukuran dimensi 3: ";
    cin >> c;

    // Deklarasi array dengan ukuran yang diinputkan
    int arr[a][b][c];

    // input elemen
    for (int x = 0; x < a; x++){
        for ( int y = 0; y < b; y++){
            for ( int z = 0; z < c; z++){
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;    
    }
    // Output Array
    for (int x = 0; x < a; x++){
        for (int y = 0; y < b; y++){
            for (int z = 0; z < c; z++){
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    // Tampilan array 
    for (int x = 0; x < a; x++){
        for (int y = 0; y < b; y++){
            for (int z = 0; z < c; z++){
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }

    int minimum = INT_MAX;
    int maximum = INT_MIN;
    int sum = 0;
    int total_elements = a * b * c;

    for (int x = 0; x < a; x++) {
        for (int y = 0; y < b; y++) {
            for (int z = 0; z < c; z++) {
                int current = arr[x][y][z];
                if (current < minimum) {
                    minimum = current;
                }
                if (current > maximum) {
                    maximum = current;
                }
                sum += current;
            }
        }
    }

    double average = static_cast<double>(sum) / total_elements;

    cout << "Nilai Minimum: " << minimum << endl;
    cout << "Nilai Maksimum: " << maximum << endl;
    cout << "Rata-rata: " << average << endl;

    return 0;
}