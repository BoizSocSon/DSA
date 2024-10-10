


#include <stdio.h>
#include <stdlib.h>

// Khởi tạo stacks

struct NodeStack {
    int data;
    struct NodeStack* next;
};

typedef struct NodeStack NodeStack;

NodeStack* CreateNodeStack(int data) {
    NodeStack *newNode = (NodeStack*)malloc(sizeof(NodeStack));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int IsEmpty(NodeStack *head){
    return head == NULL;
}

void Push(NodeStack **head, int data) {
    NodeStack *newNode = CreateNodeStack(data);
    if (!newNode) {
        printf("Memory error\n");
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

int Pop(NodeStack **head) {
    if(IsEmpty(*head)){
        printf("Stack is empty\n");
        return -1;
    }
    int popped = (*head)->data;
    NodeStack *temp = *head;
    *head = (*head)->next;
    free(temp);
    return popped;
}




// Khởi tạo cây

struct NodeTree{
    int data;
    struct NodeTree *left;
    struct NodeTree *right;
};

typedef struct NodeTree NodeTree;

NodeTree *CreateNodeTree(int data){
    NodeTree *newNode = (NodeTree*)malloc(sizeof(NodeTree));
    if(!newNode){
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

NodeTree *find(int v, NodeTree *root){
    if(root == NULL)
        return NULL;
    if(root->data == v)
        return root;
    NodeTree *p = root->left;
    while(p != NULL){
        NodeTree *q = find(v, p);
        if(q!= NULL)
            return q;
        p = p->right;
    }
    return NULL;
}

void InsertNode(NodeTree *root, int data){
    if(root == NULL){
        root = CreateNodeTree(data);
    }
}