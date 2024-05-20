#include <iostream>
#include <algorithm>
using namespace std;

int H[50];
int heapSize = -1;

int parent(int i) {
    return(i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = 1;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove (int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

void printHeap() {
    cout << "Heap: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";
}

int main() {
    int choice, value, index;
    
    insert(67);
    insert(26);
    insert(54);
    insert(38);
    insert(19);
    insert(27);
    insert(35);
    insert(41);
    insert(17);
    insert(32);

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert element\n";
        cout << "2. Extract max\n";
        cout << "3. Change priority\n";
        cout << "4. Remove element\n";
        cout << "5. Print heap\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insert(value);
                break;
            case 2:
                if (heapSize >= 0) {
                    cout << "Max value extracted: " << extractMax() << "\n";
                } else {
                    cout << "Heap is empty!\n";
                }
                break;
            case 3:
                cout << "Masukkan index: ";
                cin >> index;
                cout << "Masukkan nilai: ";
                cin >> value;
                if (index >= 0 && index <= heapSize) {
                    changePriority(index, value);
                } else {
                    cout << "Invalid index!\n";
                }
                break;
            case 4:
                cout << "Enter index to remove: ";
                cin >> index;
                if (index >= 0 && index <= heapSize) {
                    remove(index);
                } else {
                    cout << "Invalid index!\n";
                }
                break;
            case 5:
                printHeap();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    }
    return 0;
}
