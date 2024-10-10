#include <stdio.h>
#include <stdlib.h>

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

// Hàm insert sẽ thêm phần tử bé hơn gốc vào trái và ngược lại
void InsertNode(NodeTree **root, int data) {
    if (*root == NULL) {
        *root = CreateNodeTree(data);
        return;
    }

    if (data < (*root)->data) {
        InsertNode(&((*root)->left), data);
    } else {
        InsertNode(&((*root)->right), data);
    }
}

// Hàm duyệt cây theo thứ tự trong (Trái -> Gốc -> Phải)
void InOrderTraversal(NodeTree *root) {
    if (root != NULL) {
        InOrderTraversal(root->left);
        printf("%d ", root->data);
        InOrderTraversal(root->right);
    }
}

int main() {
    NodeTree *root = NULL;

    // Insert nodes into the binary tree
    InsertNode(&root, 10);
    InsertNode(&root, 5);
    InsertNode(&root, 15);
    InsertNode(&root, 3);
    InsertNode(&root, 7);
    InsertNode(&root, 12);
    InsertNode(&root, 18);

    // Display the tree using in-order traversal
    printf("In-order traversal of the binary tree: ");
    InOrderTraversal(root);
    printf("\n");

    return 0;
}