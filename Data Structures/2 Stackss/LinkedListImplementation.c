#include <stdio.h>
#include <stdlib.h>

ListNode {
    int data;
    struct ListNode *next;
};

typedef struct ListNode ListNode;
typedef struct Stack Stack;
Stack *CreateStack() {
    return NULL;
}

void Push(Stack **top, int data){
    Stack *temp;
    temp = (Stack *)malloc(sizeof(Stack));
    if(!temp) 
        return NULL; 
    temp->data = data;
    temp->next = *top;
    *top = temp;
}

