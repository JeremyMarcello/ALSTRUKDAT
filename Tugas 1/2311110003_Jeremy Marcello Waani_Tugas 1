#include <iostream>
using namespace std;

bool CekDuplikasi(int arr[], int x);

int main() {
    int arrA[] = {2, 1, 3, 1};
    cout << CekDuplikasi(arrA, 0);
    return 0;
}

bool CekDuplikasi(int arr[], int x){
    int panjangArray = 4;
    if (x == panjangArray - 1)
        return false;
    for (int i = x + 1; i < panjangArray; i++) {
        if (arr[x] == arr[i])
            return true;
    }
    return CekDuplikasi(arr, x + 1);
}
