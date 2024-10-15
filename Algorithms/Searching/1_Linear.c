#include <stdio.h>

int linear_search(int arr[], int value, int n){
    for(int i = 0; i < n; i++){
        if(arr[i] == value) return i;
    }
    return -1; // Not found
}

int main(){
    int arr[] = {10, 20, 80, 30, 60, 50, 110, 100, 130, 170};
    int n = sizeof(arr)/sizeof(arr[0]);
    int value;
    printf("Enter the value to search: ");
    scanf("%d", &value);
    int index = linear_search(arr, value, n);
    if(index != -1) printf("Value found at index: %d\n", index);
    else printf("Value not found in array.\n");
    return 0;
}