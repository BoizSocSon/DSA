#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp nổi bọt (bubble sort)
void bubble_sort(int arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[i]){ 
                swap(&arr[i], &arr[j]); 
            }
        }
    }
}

// Hàm sắp xếp nổi bọt(tối ưu)
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        // Last i elements are already sorted
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
    // int arr[] = {90, 64, 34, 25, 22, 12, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "initial array: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // bubble_sort(arr, size);
    bubbleSort(arr, size);  // Tối ưu hơn bubble_sort()

    cout << "Array after sorted: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
