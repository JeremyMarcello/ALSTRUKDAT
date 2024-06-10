#include <iostream>
using namespace std;

int sequentialSearch(int angka[], int x, int n){
    for(int i=0; i < n;i++){
        if(angka[i]==x){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[]={1,2,3,4,5,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 5;
    int x = sequentialSearch(arr, target, n);
    if(x == -1){
        cout<<"Data tidak ditemukan";
    }else{
        cout << "Angka ditemukan di index ke- "<< x;
    }
    return 0;
}