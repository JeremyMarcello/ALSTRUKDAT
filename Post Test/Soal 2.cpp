#include <iostream>
using namespace std;

int faktorial(int i){
    return i * faktorial(i-1);
}

int main(){
    int n = faktorial(5);
    cout << "Faktorial dari " << 5 << "adalah " << n << endl;

}