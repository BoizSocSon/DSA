#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
};

struct DynArrayStack
{
    int top;
    int capacity;
    int *array;
};

typedef struct BinaryTreeNode BinaryTreeNode;
typedef struct DynArrayStack DynArrayStack;

DynArrayStack *CreateStack();
int IsFull(DynArrayStack *S);
void DoubleStack(DynArrayStack *S);
void Push(DynArrayStack *S, int x);
int IsEmptyStack(DynArrayStack *S);
int Top(DynArrayStack *S);
int Pop(DynArrayStack *S);
void DeleteStack(DynArrayStack *S);

void PreOrder(BinaryTreeNode *root);
void PreOrderNonRecursive(BinaryTreeNode *root);

int main(){
    DynArrayStack *stack = CreateStack();
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

DynArrayStack *CreateStack(){
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

void PreOrder(BinaryTreeNode *root){
    if(root!= NULL){
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PreOrderNonRecursive(BinaryTreeNode *root){
    DynArrayStack *stack = CreateStack();
    while(1){
        while(root){
            printf("%d ", root->data);
            Push(stack, root->data);
            root = root->left;
        }
        if(IsEmptyStack(stack))
            break;
        root = Pop(stack);
        root = root->right;
    }
    DeleteStack(stack);
}