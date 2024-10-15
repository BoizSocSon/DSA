// Binary search tree is a data structure that key of every nodes is larger than the left one and the right one is smaller

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node Node;

Node *CreateNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *Insert(Node *root, int data){
    if(root == NULL){
        root = CreateNode(data);
        return root;
    }
    else if((root)->data > data){
        (root)->left = Insert((root)->left, data);
    } else if ((root)->data <= data) {
        (root)->right = Insert((root)->right, data);
    }
    return root;
}

Node *Search(Node *root, int data){
    if(root == NULL || root->data == data)
        return root;
    else if(root->data > data){
        return Search(root->left, data);
    } else if(root->data < data){
        return Search(root->right, data);
    }
    return NULL;
}

Node *FindMin(Node *root){
    if(root == NULL)
        return NULL;
    Node *lmin = FindMin(root->left);
    if(lmin != NULL) lmin;
    return root;
}   

Node *Delete(Node *root, int data){
    if(root == NULL)
        return root;
    else if(data < root->data)
        root->left = Delete(root->left, data);
    else if(data > root->data)
        root->right = Delete(root->right, data);
    else{
        if(root->left != NULL && root->right != NULL){
            Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        } else {
            Node *temp = root;
            if(root->left == NULL)
                root = root->right;
            else if(root->right == NULL)
                root = root->left;
            free(temp);
        }
    }
}

int main(){

}