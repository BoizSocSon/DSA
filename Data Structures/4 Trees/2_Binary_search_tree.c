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

Node *SearchDepth(Node *root, int data, int *depth){
    if(root == NULL || root->data == data)
        return root;
    else if(root->data > data){
        *depth += 1;
        return SearchDepth(root->left, data, depth);
    } else if(root->data < data){
        *depth += 1;
        return SearchDepth(root->right, data, depth);
    }
    return NULL;
}

int HeightNode(Node *root){
    if(root == NULL)
    return 0;
    int leftHeight = HeightNode(root->left);
    int rightHeight = HeightNode(root->right);
    return (leftHeight > rightHeight)? leftHeight+1 : rightHeight+1;
}

int Height(Node* root, int key){
    Node *node = Search(root, key);
    return HeightNode(node);
}

int DepthNode(Node* root, int key){
    Node *node = Search(root, key);
    if(node == NULL)
        return -1;
    int leftDepth = DepthNode(root->left, key);
    int rightDepth = DepthNode(root->right, key);
    return (leftDepth > rightDepth)? leftDepth+1 : rightDepth+1;
}

Node *FindMin(Node *root){
    if(root == NULL)
        return NULL;
    if(root->left == NULL)
        return root;
    return FindMin(root->left);
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
    return root;
}

int main(){
    Node *root = NULL;
    root = Insert(root, 50);
    root = Insert(root, 30);
    root = Insert(root, 20);
    root = Insert(root, 40);
    root = Insert(root, 70);
    root = Insert(root, 60);
    root = Insert(root, 80);
    root = Insert(root, 25);

    printf("Height of the tree is %d\n", Height(root,30));
    printf("Depth of the tree is %d\n", DepthNode(root, 50));
    int depht = 0;
    SearchDepth(root, 80, &depht);
    printf("Depth of the tree is %d\n", depht);
    // printf("Search 20: %d\n", Search(root, 20)? 1 : 0);
    // printf("Search 90: %d\n", Search(root, 90)? 1 : 0);
    // root = Delete(root, 20);
    // printf("Search 20 after deletion: %d\n", Search(root, 20)? 1 : 0);
    return 0;
}