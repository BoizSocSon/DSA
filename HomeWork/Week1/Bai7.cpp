#include <iostream>

using namespace std;

int sum_of_arrays(int **arr, int N, int M){
    int sum = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            sum += arr[i][j];
        }
    }
    return sum;
}

void delete_arrays(int **arr, int N, int M, int y){
    for(int i = y; i < N-1; i++){
        for(int j = 0; j < M; j++){
            arr[i][j] = arr[i+1][j];
        }
    }
}

int main() {
    int N, M;
    cout << "Enter the number of rows and columns: ";
    cin >> N >> M;
    int **arr = new int*[N];
    for (int i = 0; i < N; i++) {
        arr[i] = new int[M];
    }
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int result = sum_of_arrays(arr, N, M);

    cout << "Sum of the array elements: " << result << endl;

    delete_arrays(arr, N, M, 1);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}