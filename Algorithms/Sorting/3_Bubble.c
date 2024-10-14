#include <stdio.h>

void bubble_sort(int arr[], int n);
void BubbleSort(int arr[], int n);

int main() {
    int n;
    scanf("%d", &n);
    int arr[100];
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // bubble_sort(arr, n);
    BubbleSort(arr, n); 
    
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void bubble_sort(int arr[], int n) {
    int i, j;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void BubbleSort(int arr[], int n){
    int swapped;
    do{
        swapped = 0;
        for(int i = 0; i < n - 1; i++){
            if(arr[i] > arr[i + 1]){
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = 1;
            }
        }
    } while(swapped == 1);
}
