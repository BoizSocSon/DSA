#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

typedef struct Node Node;

int *create_node(int val){
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return -1;
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void add_node(Node **head, int val);
void delete_node(Node **head, int val);
void print_list(Node *head);

int main(){
    Node *head = NULL;
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);

    printf("List before deletion:\n");
    print_list(head);

    // // Delete node with value 2
    // Node *current = head;
    // Node *prev = NULL;
    // while(current!=NULL && current->val!=2){
    //     prev = current;
    //     current = current->next;
    // }

    // if(current!=NULL){
    //     if(prev!=NULL)
    //         prev->next = current->next;
    //     else
    //         head = current->next;
    //     free(current);
    // } else {
    //     printf("Node with value 2 not found\n");
    // }

    // printf("List after deletion:\n");
    // print_list(head);

    return 0;
}

// add node at the end of the list
void add_node(Node **head, int val){
    Node *newNode = create_node(val);
    Node *current = *head;

    if(!newNode)
        printf("Memory error\n");

    if(*head == NULL)
        *head = newNode;
    else {
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
        newNode->next = NULL;
    }
}

Node* removeElements(Node *head, int val) {
    Node* dummy = (Node*)malloc(sizeof(Node));
    dummy->val = 0;  
    dummy->next = head;
    Node* prev = dummy;
    Node* current = head;

    while(current!=NULL){
        if(current->val!=val){
            prev = current;
            current = current->next;
        } else {
            Node* temp = current;
            current = current->next;
            prev->next = current;
            free(temp);
        }
    }
    Node* result = dummy->next;
    free(dummy);
    return result;
}

void print_list(Node *head){
    Node *current = head;
    while(current!=NULL){
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}