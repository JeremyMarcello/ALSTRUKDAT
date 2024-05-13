#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* front = NULL;
Node* back = NULL;

bool isFull() { // Pengecekan Antrian Sudah Penuh Atau Tidak
    // Tidak ada batas maksimal
    return false;
}

bool isEmpty() { // Pengecekan Antrian Sudah Kosong Atau Tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Fungsi Menambahkan Antrian
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty()) {
            front = back = newNode;
    } else {
            back->next = newNode;
            back = newNode;
    }
}

void dequeueAntrian() { // Fungsi Mengurangi Antrian
    if (isEmpty()) {
        cout << "Antrian Kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == NULL) {
            back = NULL;
        }
    }
}

int countQueue() { // Fungsi Menghitung Banyak Antrian
    int count = 0;
    Node* cur = front;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}

void clearQueue() { // Fungsi Menghapus Antrian
    if (isEmpty()) {
        cout << "Antrian Kosong" << endl;
    } else {
        while (front != NULL) {
            dequeueAntrian();
        }
    }
}

void viewQueue() {
  if (isEmpty()) {
    cout << "Antrian Kosong" << endl;
    return;
  }

  cout << "Data Antrian Teller :" << endl;
  Node* cur = front;
  int n = 1;
  while (cur != NULL) {
    cout << n << ". " << cur->data << endl;
    cur = cur->next;
    n++;
  }
  cout << endl;
}


int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    
    viewQueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;
    
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;
    
    clearQueue();
    viewQueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;
    
    return 0;
}