#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers;
    int num;
    char choice;

    do {
        cout << "Masukkan sebuah bilangan: ";
        cin >> num;
        numbers.push_back(num);

        cout << "Tambah bilangan lagi? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    vector<int> even_numbers;
    vector<int> odd_numbers;

    for (int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] % 2 == 0) {
            even_numbers.push_back(numbers[i]);
        } else {
            odd_numbers.push_back(numbers[i]);
        }
    }

    cout << "Bilangan genap: ";
    for (int i = 0; i < even_numbers.size(); ++i) {
        cout << even_numbers[i] << " ";
    }
    cout << endl;

    cout << "Bilangan ganjil: ";
    for (int i = 0; i < odd_numbers.size(); ++i) {
        cout << odd_numbers[i] << " ";
    }
    cout << endl;

    return 0;
}