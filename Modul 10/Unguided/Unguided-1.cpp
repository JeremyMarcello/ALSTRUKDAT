#include <iostream>
using namespace std;

int faktorial(int angka){
    if (angka <= 1){
        return 1;
    }
    return angka * faktorial(angka-1);
}

int main(){
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;
    cout << "Faktorial dari " << angka << " adalah " << faktorial(angka) << endl;
    return 0;
}