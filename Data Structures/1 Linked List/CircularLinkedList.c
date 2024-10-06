#include <stdio.h>
#include <stdlib.h>

struct CCLNode {
    int data;
    struct CCLNode *next;
};

typedef struct CCLNode CCLNode;
CCLNode *CreateNode(int data);
void InsertAtBeginning(CCLNode **head, int data);
void ShowList(CCLNode *head);
int main(void){
    CCLNode *head = NULL;
    InsertAtBeginning(&head, 1);
    InsertAtBeginning(&head, 2);
    InsertAtBeginning(&head, 3);
    InsertAtBeginning(&head, 4);
    InsertAtBeginning(&head, 5);
    ShowList(head);
    return 0;
}

CCLNode *CreateNode(int data){
    CCLNode *newNode = (CCLNode*)malloc(sizeof(CCLNode));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

void InsertAtBeginning(CCLNode **head, int data){
    CCLNode *newNode = CreateNode(data);
    if(!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    
    if(*head == NULL){
        *head = newNode;
        return;
    }
    else{
        CCLNode *current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        newNode->next = *head;
        current->next = newNode;
        *head = newNode;
        return;
    }
    
}

void ShowList(CCLNode *head){
    CCLNode *current = head;
    if(head == NULL){
        return;
    }
    do{
        printf("%d ", current->data);
        current = current->next;
    } while(current != head);
}
