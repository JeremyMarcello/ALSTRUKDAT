#include <iostream>
using namespace std;
// Main program
int main(){
    char op;
    float num1, num2;

    // User dapat memasukkan Operator +, -, *, /
    cin >> op;

    // User dapat memasukkan num1 dan num2
    cin >> num1 >> num2;

    // switch statement
    switch  (op)
    
    {
    // Jika user memasukkan +
    case '+':
        cout << num1 + num2;
        break;
    // Jika user memasukkan -
    case '-':
        cout << num1 - num2;
        break;
    // Jika user memasukkan *
    case '*':
        cout << num1 * num2;
        break;
    // Jika user memasukkan /
    case '/':
        cout << num1 / num2;
        break;
        
    // Jika memasukkan operator selain yang diatas maka print error
    default:
        cout << "Error! Operator salah";
    }
    return 0;
}
