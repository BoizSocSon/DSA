#include <stdio.h>

void select_sort(int arr[], int);
void SelectionSort(int A[], int N);

int main(){
    int n;
    scanf("%d", &n);
    int arr[100];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    select_sort(arr, n);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

void select_sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min]){
                min = j;
            } 
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void SelectionSort(int A[], int N){
    for(int k = 0; k < N; k++){
        int min_index = k;
        for(int j = k+1; j < N; j++){
            if(A[j] < A[min_index])
                min_index = j;
        }
        int temp = A[k];
        A[k] = A[min_index];
        A[min_index] = temp;

    }
}