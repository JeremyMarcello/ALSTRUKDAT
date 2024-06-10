#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void simpul_kota(int n, vector<string> &simpul, vector<vector<int>> &bobot)
{
    cout << "\n    ";

    for (int i = 0; i < n; i++)
    {
        cout << setw(9) << simpul[i];
    }
    cout << endl;

    for (int baris = 0; baris < n; baris++)
    {
        cout << "  " << simpul[baris] << " ";
        for (int kolom = 0; kolom < n; kolom++)
        {
            cout << setw(6) << bobot[baris][kolom];
        }
        cout << endl;
    }
}

int main()
{
    int JeremyMarcelloWaani_2311110003;
    string angka;

    cout << "\nMasukkan jumlah simpul : ";
    cin >> JeremyMarcelloWaani_2311110003;

    vector<string> simpul(JeremyMarcelloWaani_2311110003);

    cout << "Masukkan nama simpul" << endl;
    for (int i = 0; i < JeremyMarcelloWaani_2311110003; i++)
    {
        cout << "Simpul " << i + 1 << " : ";
        cin >> simpul[i];
    }

    vector<vector<int>> bobot(JeremyMarcelloWaani_2311110003, vector<int>(JeremyMarcelloWaani_2311110003));

    cout << "Masukkan bobot antar simpul" << endl;
    for (int i = 0; i < JeremyMarcelloWaani_2311110003; i++)
    {
        for (int j = 0; j < JeremyMarcelloWaani_2311110003; j++)
        {
            cout << simpul[i] << "--> " << simpul[j] << " = ";
            cin >> bobot[i][j];
        }
    }

    simpul_kota(JeremyMarcelloWaani_2311110003, simpul, bobot);

    return 0;
}