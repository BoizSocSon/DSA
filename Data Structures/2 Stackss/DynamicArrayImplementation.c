#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct DynArrayStack
{
    int top;
    int capacity;
    int *array;
};

typedef struct DynArrayStack DynArrayStack;

DynArrayStack *CreateyStack(){
    DynArrayStack *S = (DynArrayStack*)malloc(sizeof(DynArrayStack));
    S->top = -1;
    S->capacity = 1;
    S->array = (int*)malloc(sizeof(int) * S->capacity);
    if(!S->array)
        return NULL;
    return S;
}

int IsFull(DynArrayStack *S){
    return S->top == S->capacity - 1;
}

void DoubleStack(DynArrayStack *S){
    S->capacity *= 2;
    S->array = (int*)realloc(S->array, sizeof(int) * S->capacity);
}

void Push(DynArrayStack *S, int x){
    if(IsFull(S))
        DoubleStack(S);
    S->array[++S->top] = x;
}

int IsEmptyStack(DynArrayStack *S){ 
    return S->top == -1;
}

int Top(DynArrayStack *S){
    if(IsEmptyStack(S))
        return INT_MIN;
    return S->array[S->top];
}

int Pop(DynArrayStack *S){
    if(IsEmptyStack(S))
        return INT_MIN;
    return S->array[S->top--];
}

void DeleteStack(DynArrayStack *S){
    if(S){
        if(S->array){
            free(S->array);
        }
        free(S);
    }
}

int main(void){
    DynArrayStack *stack = CreateyStack();
    Push(stack, 10);
    Push(stack, 20);
    Push(stack, 30);
    if (IsEmptyStack(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }
    printf("Top element: %d\n", Top(stack));
    while (!IsEmptyStack(stack)) {
        printf("Popped element: %d\n", Pop(stack));
    }
    DeleteStack(stack);

    return 0;
}