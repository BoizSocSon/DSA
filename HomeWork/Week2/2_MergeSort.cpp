#include <iostream>

using namespace std;

void merge(int arr[], int start, int mid, int end){
    int i = 0;
    int j = 0;
    int k = start;
    int n1 = mid - start + 1;
    int n2 = end - mid;
    
    int L[100], R[100];

    for(int i = 0; i < n1; i++){
        L[i] = arr[start + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[mid + j + 1];
    }

    i = 0;
    j = 0;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        
    }
    while(i < n1){
        arr[k++] = L[i++];
    }
    while(j < n2){
        arr[k++] = R[j++];
    }
}

void merge_sort(int arr[], int start, int end){
    if(start < end){
        int mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    merge_sort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}