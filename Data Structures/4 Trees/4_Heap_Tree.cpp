#include <iostream>
using namespace std;

#define MAX_SIZE 100  // Define maximum size of the heap

int heap[MAX_SIZE];
int heapSize = 0;

// Function to swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to insert an element into the heap
void insert(int value) {
    if (heapSize >= MAX_SIZE) {
        cout << "Heap is full!" << endl;
        return;
    }
    
    heap[heapSize] = value;  // Insert at the end
    int current = heapSize;
    heapSize++;
    
    // Adjust the position of the new element to maintain max heap property
    while (current > 0 && heap[(current - 1) / 2] < heap[current]) {
        swap(heap[(current - 1) / 2], heap[current]);
        current = (current - 1) / 2;
    }
}

// Function to heapify a subtree with root at given index
void heapify(int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    // Find the largest among root, left child, and right child
    if (leftChild < heapSize && heap[leftChild] > heap[largest])
        largest = leftChild;
    if (rightChild < heapSize && heap[rightChild] > heap[largest])
        largest = rightChild;

    // Swap and continue heapifying if root is not largest
    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapify(largest);
    }
}

// Function to delete the root (max element) from the heap
void deleteRoot() {
    if (heapSize <= 0) {
        cout << "Heap is empty!" << endl;
        return;
    }

    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapify(0);
}

// Function to print the heap
void printHeap() {
    cout << "Heap elements: ";
    for (int i = 0; i < heapSize; i++)
        cout << heap[i] << " ";
    cout << endl;
}

int main() {
    // Insert elements into the heap
    insert(10);
    insert(20);
    insert(15);
    insert(30);
    insert(40);

    cout << "Initial max heap: " << endl;
    printHeap();

    // Delete root element
    deleteRoot();
    cout << "Max heap after deleting root: " << endl;
    printHeap();

    return 0;
}
