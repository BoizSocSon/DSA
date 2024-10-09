#include "iostream"

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node *CreateNewNode(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void InsertAtTheEnd(Node **head, int data) {
    Node *newNode = CreateNewNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Thêm vào đầu
void InsertAtTheStart(Node **head, int data) {
    Node *newNode = CreateNewNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Thêm vào vị trí cho trước
void InsertAtPosition(Node **head, int position, int data){
    if(position == 0){
        InsertAtTheStart(head, data);
        return;
    }
    Node *newNode = CreateNewNode(data);
    Node *current = *head;
    for(int i = 0; i < position - 1 && current!= NULL; i++){
        current = current->next;
    }
    if(current == NULL){
        cout << "Position out of bounds" << endl;
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Xóa node tại một vị trí
void DeleteNode(Node **head, int position) {
    if (*head == NULL) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    Node *current = *head;

    if (position == 0) {
        *head = current->next; 
        delete current;  
        return;
    }

    Node *prev = nullptr;
    int tempPosition = 0;

    while (current != NULL && tempPosition < position) {
        prev = current;
        current = current->next;
        tempPosition++;
    }

    if (current == NULL) {
        cout << "Position " << position << " is out of bounds." << endl;
        return;
    }

    prev->next = current->next;

    delete current;
}


int NodeTraversal(Node **head, int value) {
    Node *current = *head;
    int count = 0;
    while (current != NULL && current->data != value) {
        count++;
        current = current->next;
    }
    if (current == NULL)
        return -1;  // If value is not found
    return count;
}

int GetNodeValue(Node **head, int position) {
    Node *current = *head;
    int count = 0;
    while (current != NULL && count != position) {
        count++;
        current = current->next;
    }
    if (current != NULL)
        return current->data;
    return -1;  // If position is out of bounds
}

void PrintList(Node *head){
    while(head != NULL){
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node *head = NULL;

    // Insert nodes into the linked list
    InsertAtTheEnd(&head, 10);
    InsertAtTheEnd(&head, 20);
    InsertAtTheEnd(&head, 30);
    InsertAtTheEnd(&head, 40);
    InsertAtTheStart(&head, 50);
    InsertAtPosition(&head, 2, 25);

    // Print the list
    cout << "Linked list: ";
    Node *current = head;
    PrintList(head);

    // Test NodeTraversal
    int value = 30;
    int position = NodeTraversal(&head, value);
    if (position != -1) {
        cout << "Value " << value << " found at position: " << position << endl;
    } else {
        cout << "Value " << value << " not found in the list." << endl;
    }

    // Test GetNodeValue
    int pos = 2;
    int nodeValue = GetNodeValue(&head, pos);
    if (nodeValue != -1) {
        cout << "Value at position " << pos << " is: " << nodeValue << endl;
    } else {
        cout << "No node found at position " << pos << endl;
    }

    // Test DeleteNode
    DeleteNode(&head, 2);
    cout << "Linked list after deleting node at position 2: ";
    PrintList(head);

    return 0;
}
