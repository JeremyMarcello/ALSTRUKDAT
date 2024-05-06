#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string kalimat) {
    stack<char> charStack;
    kalimat.erase(remove_if(kalimat.begin(), kalimat.end(), ::isspace), kalimat.end());
    transform(kalimat.begin(), kalimat.end(), kalimat.begin(), ::tolower);
    for (char c : kalimat) {
        charStack.push(c);
    }

    string reverseKalimat;
    while (!charStack.empty()) {
        reverseKalimat += charStack.top();
        charStack.pop();
    }

    return kalimat == reverseKalimat;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    if (isPalindrome(kalimat)) {
        cout << "Kalimat tersebut adalah palindrom" << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom" << endl;
    }

    return 0;
}
