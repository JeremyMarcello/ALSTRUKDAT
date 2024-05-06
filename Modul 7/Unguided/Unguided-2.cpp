#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string balikKata(string kalimat) {
    stack<char> charStack;
    for (char c : kalimat) {
        charStack.push(c);
    }

    string reverseKalimat;
    while (!charStack.empty()) {
        reverseKalimat += charStack.top();
        charStack.pop();
    }
    return reverseKalimat;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);
    cout << "Setelah dibalik: " << balikKata(kalimat) <<endl;

    return 0;
}
