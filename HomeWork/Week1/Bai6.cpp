#include <iostream>

using namespace std;

void delete_value(int *arr, int k,int n){
    for(int i = k; i < n; i++){
        arr[i] = arr[i+1];
    }
}

void add_value(int *arr, int y, int m, int n){
    for(int i = n; i >= m; i--){
        arr[i+1] = arr[i];
    }
    arr[m] = y;
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int *arr = new int[n+1];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    delete_value(arr, 3, n);
    add_value(arr, 4, 3, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    delete[] arr;
}
    