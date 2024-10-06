#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

TreeNode *CreateNode(int value){
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode *FindNode(int v, TreeNode *root){
    if(root == NULL)
        return NULL;
    if(root->data == v)
        return root;
    

}

void InsertNode(TreeNode *root, int value, int index){
    if(root == NULL){
        root = CreateNode(value);
        return;
    }

}

int main(){

}