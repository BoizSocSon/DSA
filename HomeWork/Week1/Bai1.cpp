#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    int arr[n];
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    cout << "Sum of the array elements: " << sum << endl;

    return 0;
}