#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int r){
    int i = 0;
    int j = 0;
    int k = l;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1];
    int R[n2];

    for(int i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = arr[m + 1 + i];
    }
    i = 0;
    j = 0;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k++] = L[i++];
    }

    while(j < n2) {
        arr[k++] = R[j++];
    }
}

void merge_sort(int arr[], int l, int r){
    if(l<r){
        int m = (l+r)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    merge_sort(arr, 0, n-1);
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}