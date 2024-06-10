# <h1 align="center">Laporan Praktikum Modul Graph dan Tree</h1>


<p align="center">Jeremy Marcello Waani / 2311110003 / S1SD04-A</p>

## Dasar Teori

**Pengertian Fungsi Graph dan Tree**

1. Graph 

Graf adalah kumpulan noktah (simpul) di dalam bidang dua dimensi yang dihubungkan dengan sekumpulan garis (sisi). Graph dapat digunakan untuk merepresentasikan objek-objek diskrit dan hubungan antara objek-objek tersebut. Representasi visual dari graph adalah dengan menyatakan objek sebagai noktah, bulatan atau titik (Vertex), sedangkan hubungan antara objek dinyatakan dengan garis (Edge).[1]

G = (V, E)

Dimana :

- G = Graph
- V = Simpul atau Vertex, atau Node, atau Titik
- E = Busur atau Edge, atau arc [1]

Graf merupakan suatu cabang ilmu yang memiliki banyak terapan. Banyak sekali struktur yang bisa direpresentasikan dengan graf, dan banyak masalah yang bisa diselesaikan dengan bantuan graf. Seringkali graf digunakan untuk merepresentasikan suaru jaringan. Misalkan jaringan jalan raya dimodelkan graf dengan kota sebagai simpul (vertex/node) dan jalan yang menghubungkan setiap kotanya sebagai sisi (edge) yang bobotnya (weight) adalah panjang dari jalan tersebut.[2]

Jenis Graph  

a. Graph Berarah (Directed Graph) : jika sisi-sisi graph hanya 
berlaku satu arah. 
Misalnya : {x,y} yaitu arah x ke y, bukan dari y ke x; x 
disebut origin dan y disebut terminus. Secara notasi sisi 
digraph ditulis sebagai vektor (x, y).[3]

b.  Graph Tak Berarah (undirected graph atau undigraph): 
setiap sisi {x, y} berlaku pada kedua arah: baik x ke y 
maupun y ke x. Secara grafis sisi pada undigraph tidak 
memiliki 
mata panah dan secara notasional 
menggunakan kurung kurawal. [3]

c.    Graph Berbobot (Weighted Graph):
Jika setiap busur mempunyai nilai yang menyatakan hubungan antara 2 buah simpul, maka busur tersebut dinyatakan memiliki bobot. Bobot sebuah busur dapat menyatakan panjang sebuah jalan dari 2 buah titik, jumlah rata-rata kendaraan perhari yang melalui sebuah jalan, dll. [3]

2. Tree

Tree merupakan salah satu bentuk struktur data tidak linear yang menggambarkan hubungan yang bersifat hirarkis (hubungan one to many) antara elemen-elemen. Tree bisa didefinisikan sebagai kumpulan simpul/node dengan satu elemen khusus yang disebut Root dan node lainnya. [2]

Operasi penelusuran node-node dalam binary tree, 
Traversal dibagi 3, yaitu : [3]

a.  PreOrder

b.  InOrder 

c.  PostOrder 

- Tree (atau pohon) sejumlah node yang berhubungan 
secara hirarkis dimana suatu node pada suatu hirarki merupakan cabang dari node dengan hirarki yang lebih tinggi dan juga memiliki cabang ke beberapa node lainnya dengan hirarki yang lebih rendah. [3]
- Root (atau akar) 
Node dengan hirarki tertinggi dinamakan root. 
- Leaf (atau daun) 
Node yang tidak memiliki cabang. 
- Internal node (atau node dalam) 
Node yang bukan merupakan leaf. 
- Edge (atau sisi atau cabang) 
Menyatakan hubungan hirarkis antara kedua node yang 
terhubungkan, biasanya digambarkan berarah (berupa panah) untuk menunjukkan node asal edge lebih tinggi dari node tujuan dari edge. [3]

## Guided

### 1. Guided 1
```C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cinajur", "Purwokerto", "Yogyakarta"
};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << " (" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```

**Output:**
![Screenshot 2024-06-10 114325](https://github.com/JeremyMarcello/Assignment-Praktikum-Algoritma-dan-Struktur-Data/assets/156126843/32dfcde6-ec01-49b8-abf8-46187c8b05ef)

**Kode yang diberikan mengimplementasikan program untuk menampilkan representasi matriks bobot graf.**

**Fungsi:**

* simpul_kota(n, simpul, bobot):
* Menerima parameter n (integer) yang mewakili jumlah simpul, simpul (vector<string>) yang berisi nama-nama simpul, dan bobot       (vector<vector<int>>) yang berisi matriks bobot antar simpul.
    * Mencetak header tabel yang berisi nama-nama simpul.
    * Melakukan iterasi melalui setiap baris dalam matriks bobot:
        * Mencetak nama simpul baris saat ini di awal baris.
        * Melakukan iterasi melalui setiap kolom dalam baris saat ini:
        * Mencetak nilai bobot antar simpul baris dan kolom saat ini.
    * Tidak ada nilai return.

**Fungsi Utama (main):**

* Mendeklarasikan variabel JeremyMarcelloWaani_2311110003 (integer) dan angka (string) yang tidak digunakan dalam program.
* Meminta pengguna untuk memasukkan jumlah simpul (integer) melalui konsol dan menyimpannya dalam variabel JeremyMarcelloWaani_2311110003.
* Mendefinisikan vector simpul dengan ukuran JeremyMarcelloWaani_2311110003 untuk menyimpan nama-nama simpul.
* Meminta pengguna untuk memasukkan nama-nama simpul satu per satu dan menyimpannya dalam vector simpul.
* Mendefinisikan vector dua dimensi bobot dengan ukuran JeremyMarcelloWaani_2311110003 x JeremyMarcelloWaani_2311110003 untuk menyimpan matriks bobot antar simpul.
* Meminta pengguna untuk memasukkan nilai bobot antar simpul satu per satu dan menyimpannya dalam matriks bobot.
* Memanggil fungsi simpul_kota(JeremyMarcelloWaani_2311110003, simpul, bobot) untuk menampilkan representasi matriks bobot graf.
* Mengembalikan nilai 0 dari fungsi main.

**Penjelasan:**

Program ini memungkinkan pengguna untuk memasukkan informasi tentang graf, seperti jumlah simpul, nama-nama simpul, dan nilai bobot antar simpul. Informasi ini kemudian disimpan dalam struktur data yang sesuai (vector untuk nama simpul dan matriks dua dimensi untuk bobot). Terakhir, fungsi simpul_kota digunakan untuk menampilkan representasi matriks bobot graf dengan rapi ke konsol.

### 2. Guided 2
```C++
#include <iostream>
using namespace std;

struct TNode
{
    int data;
    TNode *left;
    TNode *right;

    TNode(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

int main()
{
    TNode *zero = new TNode(0);
    // 0
    // /\
    // NULL NULL

    TNode *one = new TNode(1);
    TNode *five = new TNode(5);
    TNode *seven = new TNode(7);
    TNode *eight = new TNode(8);
    TNode *nine = new TNode(9);

    seven->left = one;
    // 7
    // /\
    // 1 NULL

    seven->right = nine;
    // 7
    // /\
    // 1 9

    one->left = zero;
    // 7
    // /\
    // 1 9
    // /\
    // 0 NULL

    one->right = five;
    // 7
    // /\
    // 1 9
    // /\
    // 0 5

    nine->left = eight;
    // 7
    // /\
    // 1 9
    // /\  /\
    // 0 5 8 NULL

    preOrder(seven);
    cout << endl;

    inOrder(seven);
    cout << endl;

    postOrder(seven);
    cout << endl;
    return 0;
}
```

**Output:**
![Screenshot 2024-06-10 114343](https://github.com/JeremyMarcello/Assignment-Praktikum-Algoritma-dan-Struktur-Data/assets/156126843/248359e5-5d47-4cbf-98a3-713d239e2e6f)


**Kode yang diberikan mengimplementasikan struktur pohon biner dan tiga metode traversal (pre-order, in-order, post-order).**

**Struktur Data:**

* TNode: Merupakan struktur untuk mewakili node dalam pohon biner.
    * data: Men menyimpan nilai integer pada node.
    * left: Pointer ke node anak sebelah kiri.
    * right: Pointer ke node anak sebelah kanan.
    * TNode(int value): Konstruktor untuk membuat node baru dengan nilai value.

**Fungsi Traversal:**

* preOrder(TNode *node): Melakukan traversal pre-order pada pohon biner.
    * Jika node tidak kosong (NULL):
        * Mencetak nilai data dari node.
        * Memanggil fungsi preOrder secara rekursif pada node anak sebelah kiri.
        * Memanggil fungsi preOrder secara rekursif pada node anak sebelah kanan.
* inOrder(TNode *node): Melakukan traversal in-order pada pohon biner.
    * Jika node tidak kosong (NULL):
        * Memanggil fungsi inOrder secara rekursif pada node anak sebelah kiri.
        * Mencetak nilai data dari node.
        * Memanggil fungsi inOrder secara rekursif pada node anak sebelah kanan.
* postOrder(TNode *node): Melakukan traversal post-order pada pohon biner.
    * Jika node tidak kosong (NULL):
        * Memanggil fungsi postOrder secara rekursif pada node anak sebelah kiri.
        * Memanggil fungsi postOrder secara rekursif pada node anak sebelah kanan.
        * Mencetak nilai data dari node.

**Fungsi Utama (main):**

* Mendefinisikan beberapa node TNode dengan nilai berbeda.
* Membangun struktur pohon biner dengan menghubungkan node-node tersebut menggunakan pointer left dan right.
    * Pohon biner yang terbentuk:
        * Node dengan nilai 7 sebagai root.
        * Node dengan nilai 1 sebagai anak kiri dari root.
        * Node dengan nilai 9 sebagai anak kanan dari root.
        * Node dengan nilai 0 sebagai anak kiri dari node 1.
        * Node dengan nilai 5 sebagai anak kanan dari node 1.
        * Node dengan nilai 8 sebagai anak kiri dari node 9.
* Memanggil fungsi preOrder, inOrder, dan postOrder untuk melakukan traversal pada pohon biner. Masing-masing fungsi akan mencetak nilai node sesuai dengan urutan traversal.
Penjelasan:

* Traversal: Cara mengunjungi node-node dalam struktur pohon biner.
* Pre-order: Mengunjungi root terlebih dahulu, kemudian anak kiri secara rekursif, dan terakhir anak kanan secara rekursif.
* In-order: Mengunjungi anak kiri secara rekursif, kemudian root, dan terakhir anak kanan secara rekursif.
* Post-order: Mengunjungi anak kiri secara rekursif, kemudian anak kanan secara rekursif, dan terakhir root.

## Unguided

### 1. Unguided 1

```C++
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
```

#### Output:
![Screenshot 2024-06-10 114648](https://github.com/JeremyMarcello/Assignment-Praktikum-Algoritma-dan-Struktur-Data/assets/156126843/fa2fa626-91cb-4e14-bd48-47eb37a389fb)

**Kode yang diberikan mengimplementasikan program untuk menampilkan representasi matriks bobot graf.**

**Fungsi:**

* simpul_kota(n, simpul, bobot):
    * Menerima parameter n (integer) yang mewakili jumlah simpul, simpul (vector<string>) yang berisi nama-nama simpul, dan bobot (vector<vector<int>>) yang berisi matriks bobot antar simpul.
    * Mencetak header tabel yang berisi nama-nama simpul.
    * Melakukan iterasi melalui setiap baris dalam matriks bobot:
        * Mencetak nama simpul baris saat ini di awal baris.
        * Melakukan iterasi melalui setiap kolom dalam baris saat ini:
            * Mencetak nilai bobot antar simpul baris dan kolom saat ini.
    * Tidak ada nilai return.

**Fungsi Utama (main):**

* Mendeklarasikan variabel JeremyMarcelloWaani_2311110003 (integer) dan angka (string) yang tidak digunakan dalam program.
* Meminta pengguna untuk memasukkan jumlah simpul (integer) melalui konsol dan menyimpannya dalam variabel JeremyMarcelloWaani_2311110003.
* Mendefinisikan vector simpul dengan ukuran JeremyMarcelloWaani_2311110003 untuk menyimpan nama-nama simpul.
* Meminta pengguna untuk memasukkan nama-nama simpul satu per satu dan menyimpannya dalam vector simpul.
* Mendefinisikan vector dua dimensi bobot dengan ukuran JeremyMarcelloWaani_2311110003 x JeremyMarcelloWaani_2311110003 untuk menyimpan matriks bobot antar simpul.
* Meminta pengguna untuk memasukkan nilai bobot antar simpul satu per satu dan menyimpannya dalam matriks bobot.
* Memanggil fungsi simpul_kota(JeremyMarcelloWaani_2311110003, simpul, bobot) untuk menampilkan representasi matriks bobot graf.
* Mengembalikan nilai 0 dari fungsi main.

**Penjelasan:**

Program ini memungkinkan pengguna untuk memasukkan informasi tentang graf, seperti jumlah simpul, nama-nama simpul, dan nilai bobot antar simpul. Informasi ini kemudian disimpan dalam struktur data yang sesuai (vector untuk nama simpul dan matriks dua dimensi untuk bobot). Terakhir, fungsi simpul_kota digunakan untuk menampilkan representasi matriks bobot graf dengan rapi ke konsol.

### 2. Unguided 2

```C++
#include <iostream>
#include <queue>
using namespace std;

struct TNode
{
    int data;
    TNode *left;
    TNode *right;
    string JeremyMarcelloWaani_2311110003;

    TNode(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

TNode *addNode(TNode *root, int value)
{
    if (root == NULL)
    {
        return new TNode(value);
    }
    queue<TNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TNode *temp = q.front();
        q.pop();
        if (temp->left == NULL)
        {
            temp->left = new TNode(value);
            break;
        }
        else
        {
            q.push(temp->left);
        }
        if (temp->right == NULL)
        {
            temp->right = new TNode(value);
            break;
        }
        else
        {
            q.push(temp->right);
        }
    }
    return root;
}

TNode *findNode(TNode *root, int value)
{
    if (root == NULL)
        return NULL;
    if (root->data == value)
        return root;
    TNode *left = findNode(root->left, value);
    if (left != NULL)
        return left;
    return findNode(root->right, value);
}

void displayChild(TNode *node)
{
    if (node == NULL)
    {
        cout << "Node not found" << endl;
        return;
    }
    cout << "Left Child: " << (node->left ? to_string(node->left->data) : "NULL") << endl;
    cout << "Right Child: " << (node->right ? to_string(node->right->data) : "NULL") << endl;
}

void displayDescendants(TNode *node)
{
    if (node == NULL)
    {
        cout << "Node not found" << endl;
        return;
    }
    cout << "Descendants: ";
    queue<TNode *> q;
    q.push(node);
    while (!q.empty())
    {
        TNode *temp = q.front();
        q.pop();
        if (temp != node)
        {
            cout << temp->data << " ";
        }
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
    cout << endl;
}

int main()
{
    TNode *root = NULL;
    int choice, value, nodeValue;

    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Add Node" << endl;
        cout << "2. Pre-Order Traversal" << endl;
        cout << "3. In-Order Traversal" << endl;
        cout << "4. Post-Order Traversal" << endl;
        cout << "5. Display Child Nodes" << endl;
        cout << "6. Display Descendant Nodes" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to add: ";
            cin >> value;
            root = addNode(root, value);
            break;
        case 2:
            preOrder(root);
            cout << endl;
            break;
        case 3:
            inOrder(root);
            cout << endl;
            break;
        case 4:
            postOrder(root);
            cout << endl;
            break;
        case 5:
            cout << "Enter node value to display children: ";
            cin >> nodeValue;
            displayChild(findNode(root, nodeValue));
            break;
        case 6:
            cout << "Enter node value to display descendants: ";
            cin >> nodeValue;
            displayDescendants(findNode(root, nodeValue));
            break;
        case 7:
            cout << "Matur Tengkyu. Code by Azka";
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
```

#### Output:
![Screenshot 2024-06-10 120626](https://github.com/JeremyMarcello/Assignment-Praktikum-Algoritma-dan-Struktur-Data/assets/156126843/55015a81-8c88-4bd6-b8a4-a42cc57d6fd3)

**Kode yang diberikan mengimplementasikan program pohon biner dengan menu interaktif.**

**Struktur Data:**

* TNode: Merupakan struktur untuk mewakili node dalam pohon biner.
    * data: Men menyimpan nilai integer pada node.
    * left: Pointer ke node anak sebelah kiri.
    * right: Pointer ke node anak sebelah kanan.
    * string JeremyMarcelloWaani_2311110003: Variabel yang tampaknya tidak digunakan dan dapat dihapus.
    * TNode(int value): Konstruktor untuk membuat node baru dengan nilai value.

**Fungsi Traversal:**

* preOrder(TNode *node): Melakukan traversal pre-order pada pohon biner (dicetak ke konsol).
* inOrder(TNode *node): Melakukan traversal in-order pada pohon biner (dicetak ke konsol).
* postOrder(TNode *node): Melakukan traversal post-order pada pohon biner (dicetak ke konsol).

**Fungsi Lain:**

* addNode(TNode *root, int value): Menambahkan node baru dengan nilai value ke pohon biner menggunakan level order traversal.
* findNode(TNode *root, int value): Mencari node dengan nilai value dalam pohon biner. Mengembalikan pointer ke node tersebut jika ditemukan, atau NULL jika tidak ditemukan.
* displayChild(TNode *node): Menampilkan node anak (kiri dan kanan) dari suatu node tertentu.
* displayDescendants(TNode *node): Menampilkan semua node turunan (descendant) dari suatu node tertentu menggunakan level order traversal.

**Fungsi Utama (main):**

* Mendefinisikan pointer root ke node root pohon biner (awalnya NULL).
* Menampilkan menu interaktif yang memungkinkan pengguna untuk:
    * Menambahkan node baru.
    * Melakukan traversal pre-order, in-order, dan post-order.
    * Menampilkan node anak dari suatu node tertentu.
    * Menampilkan semua node turunan dari suatu node tertentu.
    * Keluar dari program.
* Berdasarkan pilihan pengguna dari menu, program akan memanggil fungsi-fungsi yang sesuai untuk melakukan operasi yang diinginkan.

**Penjelasan:**

Kode ini menyediakan program interaktif untuk mengelola pohon biner. Pengguna dapat menambah node baru, melihat susunan node melalui traversal, dan mencari informasi tentang node tertentu beserta node turunannya.

## Referensi
[1] Muhammad Taufik Dwi Putra. et.al., Pemprograman Lanjut dengan C++, Bandung : Widina Media Utama, 2023.

[2] Afrizal Zein and Emi Sita Eriana., Algoritma dan Struktur Data, Tangerang Selatan: Unpam Press, 2022.

[3] Anita Sindar., STRUKTUR DATA DAN ALGORITMA DENGAN C++, Banten : CV.AA.RIZKY, 2019.