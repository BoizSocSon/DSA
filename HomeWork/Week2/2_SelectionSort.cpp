#include <iostream>
#include <algorithm>

using namespace std;

void selection_sort(int arr[], int m){
    for(int i = 0; i < m - 1; i++){
        int min_index = i;

        for(int j = i + 1; j < m; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]); // Hàm swap nằm trong thư viện algorithm
    }
}

void printArray(int arr[], int m) {
    for (int i = 0; i < m; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {29, 10, 14, 37, 14};
    int m = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, m);

    selection_sort(arr, m);

    cout << "Sorted array: ";
    printArray(arr, m);

    return 0;
}