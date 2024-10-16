#include <stdio.h>

void merge(int arr[], int l, int m, int r){
    int i = 0;
    int j = 0;
    int k = l;
    int n1 = m - l + 1;
    int n2 = r - m;
     
    int L[100], R[100]; 


    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;

    while(i < n1 && j < n2){
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

void merge_sort(int arr[], int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    int n; 
    scanf("%d", &n);
    int arr[200];
    for(int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
    merge_sort(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
    printf("%d ", arr[i]);
    return 0;
}

