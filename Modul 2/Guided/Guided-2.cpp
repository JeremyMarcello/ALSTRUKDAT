#include <iostream>
using namespace std;

int main(){
    int maks, a, i = 1, lokasi;
    cout << "Masukkan panjang array : ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i ++){
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i ++){
        if (array[i] > maks){
            lokasi = i;
            maks = array[i];
        }
    }
    cout << "Nilai maksimal adalah " << maks << " berada di Array ke " << lokasi << endl;
}