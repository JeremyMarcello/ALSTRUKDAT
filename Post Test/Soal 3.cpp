#include <iostream>
using namespace std;

void bubbleSort(int angka[], int n){
    int temp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(angka[i] < angka[j]){
            temp = angka[i];
            angka[i] = angka[j];
            angka[j] = temp;
            }
        }
    }
}

void printArray(int angka[], int n){
    for(int i = 0; i < n; i++){
        cout << angka[i] << " ";
    }
}

int main(){
    int arr[]= {5,1,4,2,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << n << endl;
    printArray(arr,n);
    bubbleSort(arr,n);
    cout << endl;
    printArray(arr,n);
    return 0;
}