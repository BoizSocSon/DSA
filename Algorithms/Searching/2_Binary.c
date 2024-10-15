#include <stdio.h>

// Function to perform binary search (recursive search)
int binary_search(int arr[], int left, int right, int value){
    // Base case for when element is not found
    if (left > right) {
        return -1;  
    }

    int mid = left + (right - left) / 2; // Prevent overflow
    if(arr[mid] == value) return mid;
    if(arr[mid] < value)
        return binary_search(arr, mid+1, right, value);
    return binary_search(arr, left, mid-1, value);
}

// Function to perform binary search (iterative search)
int binary_search_iterative(int arr[], int left, int right, int value){
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] == value)
            return mid; 
        if(arr[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void problem1(int arr[], int *n1, int *n2, int sum, int size){
    for(int i = 0; i < size; i++){
        *n1 = arr[i];
        *n2 = sum-arr[i];
        if(binary_search(arr, i+1, size-1, *n2)!= -1){
            printf("Two elements with sum %d are %d and %d\n", sum, *n1, *n2);
            return;
        }
    }
    printf("No two elements with sum %d found in array\n", sum);
}

int main(){
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int value = 16;
    int result = binary_search(arr, 0, n-1, value);
    if(result != -1)
        printf("Element found at index %d", result);
    else
        printf("Element not found in array");
    printf("\n");
    int n1, n2;
    problem1(arr, &n1, &n2, value, n);
    return 0;
}