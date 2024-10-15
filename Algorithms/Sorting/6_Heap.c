#include <stdio.h>
#include <stdlib.h>

// The defination of the max heap mean that: every root of child heap has the biggest value
// Don't be confuse that max heap mean it is the aranged array like: 8 7 6 5 4 3 2 1 0
// It can be like: 8 6 7 4 5 2 3 1 0 
// When displaying with form of tree, the tree has to be read from left to right

// Function to maintain the heap property
void heapify(int A[], int i, int N) {
    // N is the number of elements in the heap (Size of the heap)
    // i is the index of the root of the heap
    int L = 2 * i + 1; // Left child (adjusted for 0-based indexing)
    int R = 2 * i + 2; // Right child (adjusted for 0-based indexing)
    int max = i;

    if (L < N && A[L] > A[max]) {
        max = L;
    }
    if (R < N && A[R] > A[max]) {
        max = R;
    }
    if (max != i) {
        int temp = A[i];
        A[i] = A[max];
        A[max] = temp;
        heapify(A, max, N);
    }
}

// Function to build the max heap
void buildHeap(int A[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--) {
        heapify(A, i, N);
    }
}

// Function to perform heap sort
void heapSort(int A[], int N) {
    buildHeap(A, N);
    for (int i = N - 1; i > 0; i--) {
        // Move current root (maximum) to end
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        // Call heapify on the reduced heap
        heapify(A, 0, i);
    }
}

int main() {
    // Example array to sort
    int A[] = {12, 11, 13, 5, 6, 7};
    int N = sizeof(A) / sizeof(A[0]);

    printf("Original array:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Sort the array using heap sort
    heapSort(A, N);

    printf("Sorted array:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
