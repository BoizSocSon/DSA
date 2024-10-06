#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
struct ArrayStack
{
    int top;
    int capacity;
    int *array;
};

typedef struct ArrayStack ArrayStack;

ArrayStack *CreateStack(){
    ArrayStack *S = (ArrayStack *)malloc(sizeof(ArrayStack));
    if(!S)
        return NULL; 
    S->top = -1;
    S->capacity = MAXSIZE;
    S->array = (int *)malloc(sizeof(int)*MAXSIZE);
    if (!S->array)
        return NULL;
    
    return S;
}

int IsEmpty(ArrayStack *S){
    return S->top == -1;
}

int IsFull(ArrayStack *S){
    return S->top == S->capacity - 1;
}

void Push(ArrayStack *S, int data){
    if (IsFull(S)){
        printf("Stack Overflow\n");
        return;
    }
    S->array[++S->top] = data;
}

void Pop(ArrayStack *S){
    if (IsEmpty(S)){
        printf("Stack Underflow\n");
        return;
    }
    S->top--;
}

void DeleteStack(ArrayStack *S){
    if (S){
        if (S->array){
            free(S->array);
        }
        free(S);
    }
}

int main(void){
    ArrayStack *Stacks = CreateStack();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n ; i++)
    {
        int data;
        scanf("%d", &data);
        Push(Stacks, data);
    }
    for(int i = 0; i <= Stacks->top; i++){
        printf("%d\n", Stacks->array[i] );
    }
    DeleteStack(Stacks);
    return 0;
}