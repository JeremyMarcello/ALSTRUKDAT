#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, string> Mahasiswa;
    Mahasiswa["Jeremy"] = "2311110003";
    Mahasiswa["Arif"] = "2311110017";
    Mahasiswa["Brian"] = "2311110052";

    // Mencetak NIM mahasiswa
    cout << "NIM Jeremy : " << Mahasiswa["Jeremy"] << endl;

    return 0;
}