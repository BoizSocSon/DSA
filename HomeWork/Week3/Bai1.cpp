#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node *CreatNode(int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void InsertAtBeginning(Node **head, int data){
    Node *newNode = CreatNode(data);
    if(*head == nullptr){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

void InsertAtEnd(Node **head, int data){
    Node *newNode = CreatNode(data);
    if(*head == nullptr){
        *head = newNode;
        return;
    }
    Node *current = *head;
    while(current->next != nullptr){
        current = current->next;
    }
    current->next = newNode;
}

void InsertAtPosition(Node **head, int data, int position){
    Node *newNode = CreatNode(data);
    if(position == 0){
        newNode->next = *head;
        *head = newNode;
    }

    Node *current = *head;
    for(int i = 0; i < position-1 && current != nullptr; i++){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;

}

void DeleteAtPosition(Node **head, int position){
    if(*head == nullptr){
        cout << "List is empty." << endl;
        return;
    }
    
    Node *current = *head;
    Node *prev = nullptr;

    if(position == 0){
        *head = current->next;
        delete current;
        return;
    }

    for(int i = 0; i < position && current != nullptr; i++){
        prev = current;
        current = current->next;
    }

    if(current == nullptr){
        cout << "Position out of bounds." << endl;
        return;
    }

    prev->next = current->next;
    delete current;

}

int NodeTraversal(Node **head, int value) {
    Node *current = *head;
    int count = 0;
    while (current != nullptr && current->data != value) {
        count++;
        current = current->next;
    }
    if (current == nullptr)
        return -1;  // If value is not found
    return count;
}

int GetNodeValue(Node **head, int position) {
    Node *current = *head;
    int count = 0;
    while (current != nullptr && count != position) {
        count++;
        current = current->next;
    }
    if (current != nullptr)
        return current->data;
    return -1;  // If position is out of bounds
}

void PrintList(Node *head){
    while(head != nullptr){
        cout << head->data << "->";
        head = head->next;
    }
}

int main(){
    Node *head = nullptr;
    InsertAtBeginning(&head, 0);
    InsertAtEnd(&head, 2);
    InsertAtEnd(&head, 4);
    InsertAtPosition(&head, 1, 1);  // Insert 1 at position 1
    PrintList(head); // Output: 0->1->2->4->NULL
    cout << endl;
    DeleteAtPosition(&head, 1);
    PrintList(head); // Output: 0->2->4->NULL
    return 0;
}