#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    float arr[n];
    float sum = 0;


    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    float average = sum / n;
    cout << "Average: " << average << endl;
    cout << "Values larger than the average:" << endl;
    for (int i = 0; i < n; i++) {
        if (arr[i] > average) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

}