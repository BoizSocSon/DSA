#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node Node;

Node *CreateNode(int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void InsertAtBeginning(Node **head, int data){
    Node *newNode = CreateNode(data);
    if(*head == nullptr){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void InsertAtEnd(Node **head, int data){
    Node *newNode = CreateNode(data);
    if(*head == nullptr){
        *head = newNode;
        return;
    }

    Node *current = *head;
    while(current->next!= nullptr){
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

void InsertAtPosition(Node **head, int data, int position) {
    if (position == 0) {
        InsertAtBeginning(head, data);
        return;
    }

    Node *current = *head;
    for (int i = 0; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (current->next == nullptr) {
        InsertAtEnd(head, data);
        return;
    }

    Node *newNode = CreateNode(data);
    newNode->next = current->next;
    newNode->prev = current;
    
    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

int FindValue(Node *head, int value) {
    Node *current = head;
    int position = 0;
    while (current != nullptr) {
        if (current->data == value) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;  // Return -1 if the value is not found
}

int GetValueAtPosition(Node *head, int position) {
    Node *current = head;
    int pos = 0;
    while (current != nullptr) {
        if (pos == position) {
            return current->data;
        }
        current = current->next;
        pos++;
    }
    return -1;  // Return -1 if the position is out of bounds
}

void DeleteNodeAtPosition(Node **head, int position) {
    if (*head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    Node *current = *head;
    if(position == 0){
        *head = current->next;
        if(*head != nullptr){
            (*head)->next = nullptr;
        }
        delete current;
        return;
    }

    for(int i = 0; i < position && current != nullptr; i++){
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Invalid position!" << endl;
        return;
    }

    if(current->next != nullptr){
        current->next->prev = current->prev;
    }
    if(current->prev!= nullptr){
        current->prev->next = current->next;
    }

    delete current;

}

void PrintList(Node *head) {
    Node *current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void FreeList(Node *head) {
    Node *current = head;
    while (current != nullptr) {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

int main() {
    Node *head = nullptr;

    // Insert nodes at the beginning
    InsertAtBeginning(&head, 3);
    InsertAtBeginning(&head, 2);
    InsertAtBeginning(&head, 1);

    // Insert nodes at the end
    InsertAtEnd(&head, 4);
    InsertAtEnd(&head, 5);

    // Insert nodes at a specific position
    InsertAtPosition(&head, 6, 2);
    InsertAtPosition(&head, 7, 4);
    InsertAtPosition(&head, 8, 0);

    // Print the list
    cout << "Doubly linked list: ";
    PrintList(head);

    FreeList(head);

    return 0;
}