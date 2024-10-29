// #include <iostream>

// using namespace std;

// void SelectionSort(int arr[], int size){
//     for(int i = 0; i < size-1; i++){
//         int min_index = i;
//         for(int j = i + 1; j < size; j++){
//             if(arr[j] < arr[min_index]){
//                 min_index = j;
//             }
//         }
//         swap(arr[i], arr[min_index]);
//     }
// }

// void InsertionSort(int arr[], int size){
//     for(int i = 1; i < size; i++){
//         int key = arr[i];
//         int j = i - 1;
//         while(j >= 0 && arr[j] > key){
//             arr[j+1] = arr[j];
//             j--;
//         }
//         arr[j+1] = key;
//     }
// }

// void BubbleSort(int arr[], int size){
//     for(int i = 0; i < size; i++){
//         for(int j = 0; j < size - i - 1; j++){
//             if(arr[j] > arr[j+1]){
//                 swap(arr[j], arr[j+1]);
//             }
//         }
//     }
// }


// //
// void Merge(int arr[], int left, int mid, int right){
//     int i = 0;
//     int j = 0;
//     int k = left;

//     int n1 = mid - left + 1;
//     int n2 = right - mid; 

//     int *L = new int[n1];
//     int *R = new int[n2];

//     for(int i = 0; i < n1; i++){
//         L[i] = arr[left+i];
//     }

//     for(int j = 0; j < n2; j++){
//         R[j] = arr[mid+1+j];
//     }

//     i = 0;
//     j = 0;

//     while(i < n1 && j < n2){
//         if(L[i] < R[j]){
//             arr[k++] = L[i++];
//         } else {
//             arr[k++] = R[j++];
//         }
//     }

//     while(i < n1){
//         arr[k++] = L[i++];
//     }
//     while(j < n2){
//         arr[k++] = R[j++];
//     }


// }

// void MergeSort(int arr[], int left, int right){
//     if(left < right){
//         int mid = left + (right-left)/2;
//         MergeSort(arr, left, mid);
//         MergeSort(arr, mid+1, right);
//         Merge(arr, left, mid, right);
//     }
// }

// int BinarySearch(int arr[], int left, int right, int key){
//     if(left < right){
//         int mid = left + (right-left)/2;
//         if(key == arr[mid]){
//             return mid;
//         } 
//         if(key < arr[mid]){
//             return BinarySearch(arr, left, mid-1, key);
//         } else {
//             return BinarySearch(arr, mid+1, right, key);
//         }
//     } else {
//         return -1;
//     }
// }

// int main(){
//     int arr[] = {64, 25, 12, 22, 11};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     cout << "Original array: ";
//     for(int i = 0; i < size; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     // SelectionSort(arr, size);
//     // InsertionSort(arr, size);
//     // BubbleSort(arr, size);
//     MergeSort(arr, 0, size-1);  // Merge sort is stable sort
//     cout << "Sorted array: ";
//     for(int i = 0; i < size; i++){
//         cout << arr[i] << " ";
//     }
//     int key = 25;
//     int result = BinarySearch(arr, 0, size-1, key);
//     if(result == -1){
//         cout << "Element not found in array";
//     } else {
//         cout << endl << "Element found at index " << result;
//     }
//     return 0;
// }


#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *CreateNode(int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void InsertAtBeginning(Node **head, int data){
    Node *newNode = CreateNode(data);
    if(head == nullptr){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

void InsertAtEnd(Node *head, int data){
    Node *newNode = CreateNode(data);
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node *current = head;
    while(current->next!= nullptr){
        current = current->next;
    }
    current->next = newNode;
}

void InsertAtPosition(Node **head, int data, int pos){
    if(pos == 0){
        InsertAtBeginning(head, data); //?????????????
        return;
    }
    Node *newNode = CreateNode(data);
    Node *current = *head;
    for(int i = 0; i < pos - 1 && current->next != nullptr; i++){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

int main(){
    Node *head = nullptr;
    InsertAtBeginning(&head, 3);
    InsertAtBeginning(&head, 2);
    InsertAtBeginning(&head, 1);
    InsertAtEnd(head, 4);
    InsertAtEnd(head, 5);
    InsertAtPosition(&head, 6, 2);

    Node *current = head;
    while(current!= nullptr){
        cout << current->data << " ";
        current = current->next;
    }
    return 0;
}