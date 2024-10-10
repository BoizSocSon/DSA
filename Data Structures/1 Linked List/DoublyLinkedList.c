#include <stdio.h>
#include <stdlib.h>

struct DDLNode
{
    int data;
    struct DDLNode *next;
    struct DDLNode *prev;
};

typedef struct DDLNode DDLNode;

DDLNode *CreateNode(int data);
void insertAtBeginning(DDLNode **head, int data);
void insertAtEnding(DDLNode **head, int data);
void printList(DDLNode *node);
int main(void){
    DDLNode *head = NULL;
    insertAtEnding(&head, 10);
    insertAtEnding(&head, 20);
    insertAtEnding(&head, 30);
    insertAtEnding(&head, 40);
    insertAtEnding(&head, 50);
    insertAtEnding(&head, 60);
    insertAtEnding(&head, 70);
    insertAtEnding(&head, 80);
    insertAtEnding(&head, 90);
    insertAtEnding(&head, 100);
    insertAtEnding(&head, 110);
    insertAtEnding(&head, 120);
    insertAtEnding(&head, 130);
    insertAtEnding(&head, 140);
    insertAtEnding(&head, 150);
    insertAtEnding(&head, 160);
    printList(head);
    return 0;
}

DDLNode *CreateNode(int data){
    DDLNode *newNode = (DDLNode*) malloc(sizeof(DDLNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
}

void insertAtBeginning(DDLNode **head, int data){
    DDLNode *newNode = CreateNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    newNode->prev = NULL;
    if(*head){
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertAtEnding(DDLNode **head, int data){
    DDLNode *newNode = CreateNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    newNode->next = NULL;
    newNode->prev = *head;
    DDLNode* last = *head;
    while (last->next!= NULL) {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}

void printList(DDLNode *node){
    while(node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}
  