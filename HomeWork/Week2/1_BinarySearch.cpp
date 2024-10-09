#include "iostream"

using namespace std;

// Search cho dãy tăng dần
int binary_search(int arr[], int start, int end, int key){
    if(start > end) return -1;
    int mid = (start + end) / 2;
    if(arr[mid] == key) return mid;
    if(arr[mid] < key) return binary_search(arr, mid + 1, end, key);
    if(arr[mid] > key) return binary_search(arr, start, mid - 1, key);
    return -1;  
}

int main(){
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15}; // Mảng đã sắp xếp
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter the value to be found: ";
    cin >> key;

    int result = binary_search(arr, 0, n - 1, key);

    if (result != -1) {
        cout << "The value " << key << " was found at position: " << result << endl;
    } else {
        cout << "The value can not be found in list " << key << endl;
    }

    return 0;
}