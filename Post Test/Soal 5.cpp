#include <iostream>
using namespace std;

void cari(int arr[], int x, int n){
    for(int i=0; i<n; i){
        for(int j=0; j<i; j){
            if(arr[i]+arr[j]==x){
                cout << i << " " << j;
            }
        }
    }
    cout << "Tidak ada";
}


int main(){
    int arr[] = {2,7,11,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cari(arr,9,n);
    return 0;
}