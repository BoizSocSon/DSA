#include <stdio.h>
#include <stdlib.h>

struct StackNode
{
    int data;
    struct StackNode *next;
};

typedef struct StackNode StackNode;

StackNode *CreateNode(int data);
int IsEmpty(StackNode *top);
void Push(StackNode **top, int data);
int Pop(StackNode **top);
void ShowStack(StackNode *top);

int main(void){
    StackNode *top = NULL;
    Push(&top, 1); 
    Push(&top, 2);
    Push(&top, 3);
    ShowStack(top);
    printf("\nThe value was pop from stack: %d\n", Pop(&top));
    ShowStack(top);
    return 0;
}

StackNode *CreateNode(int data){
    StackNode *newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int IsEmpty(StackNode *top){
    return top == NULL;
}

void Push(StackNode **top, int data){
    StackNode *newNode = CreateNode(data);
    if(*top == NULL){
        *top = newNode;
        return; 
    }
    newNode->next = *top;
    *top = newNode;
}

int Pop(StackNode **top){
    int data;
    StackNode *temp = *top;
    if (IsEmpty(*top)) {
        printf("Stack is empty\n");
        return 0;
    }
    data = (*top)->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

void ShowStack(StackNode *top){
    while(top != NULL){
        printf("%d ", top->data);
        top = top->next;
    }
}
