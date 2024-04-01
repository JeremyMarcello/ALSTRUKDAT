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