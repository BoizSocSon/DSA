#include "iostream"

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node *CreateNewNode(int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void InsertAtTheEnd(Node **head, int data){
    Node *newNode = CreateNewNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node *current = *head;
    while(current->next!= NULL){
        current = current->next;
    }
    current->next = newNode;
}

int NodeTraversal(Node **head, int value){
    Node *current = *head;
    int count = 0;
    while(current != NULL && current->data != value){
        count++;
        current = current->next;
    }
    if(count == 0)
        return -1;
    return count;
}

int GetNodeValue(Node **head, int position){
    Node *current = *head;
    int count = 0;
    while(current!= NULL && count!= position){
        count++;
        current = current->next;
    }
    if(count == position)
        return current->data;
    return -1;
}

int main(){

}