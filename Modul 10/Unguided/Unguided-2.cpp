#include <iostream>;
using namespace std;

int faktorialA(int angka);
int faktorialB(int angka);

int faktorialA(int angka){
    if (angka <= 1){
        return 1;
    }
    return angka * faktorialB(angka-1);
}

int faktorialB(int angka){
    if (angka <= 1){
        return 1;
    }
    return angka * faktorialA(angka-1);
}

int main(){
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;
    cout << "Faktorial dari " << angka << " adalah " << faktorialA(angka) << endl;
    return 0;
}