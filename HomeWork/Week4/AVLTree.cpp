// #include <stdio.h>
// #include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    struct Node *right;
    struct Node *left;
    int height;
};

typedef struct Node Node;

int height(Node *N){
    if(N == NULL) 
        return 0;
    return N->height;
}

int max(int a, int b){
    return (a > b)? a : b;
}


Node *CreateNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

Node *RightRotate(Node *y){
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *LeftRotate(Node *x){
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    
    return y;
}

int GetBalance(Node *N){
    if(N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node *Insert(Node *node, int key){
    if(node == NULL)
        return(CreateNode(key));
    
    if(key < node->data)
        node->left = Insert(node->left, key);
    else if(key > node->data)
        node->right = Insert(node->right, key);
    else 
        return node; 

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = GetBalance(node);

    if(balance > 1 && key < node->left->data)
        return RightRotate(node);

    if(balance < -1 && key > node->right->data)
        return LeftRotate(node);

    if(balance > 1 && key > node->left->data){
        node->left = LeftRotate(node->left);
        return RightRotate(node);
    }

    if(balance < -1 && key < node->right->data){
        node->right = RightRotate(node->right);
        return LeftRotate(node);
    }
    
    return node;
}

struct Node * minValueNode(struct Node* node)
{
    struct Node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

struct Node* DeleteNode(struct Node* root, int key)
{
    if (root == NULL)
        return root;

    if ( key < root->data )
        root->left = DeleteNode(root->left, key);

    else if( key > root->data )
        root->right = DeleteNode(root->right, key);

    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct Node *temp = root->left ? root->left :
                                             root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp; 
            free(temp);
        }
        else
        {
            struct Node* temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = DeleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
      return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = GetBalance(root);

    if (balance > 1 && GetBalance(root->left) >= 0)
        return RightRotate(root);

    if (balance > 1 && GetBalance(root->left) < 0)
    {
        root->left =  LeftRotate(root->left);
        return RightRotate(root);
    }

    if (balance < -1 && GetBalance(root->right) <= 0)
        return LeftRotate(root);

    if (balance < -1 && GetBalance(root->right) > 0)
    {
        root->right = RightRotate(root->right);
        return LeftRotate(root);
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

void PrintOrderLevel(Node *root){
    if(root == nullptr)
        return;
    
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty()){
        Node *current = Q.front();
        cout << current->data << "->";
        if(current->left != nullptr) Q.push(current->left);
        if(current->right != nullptr) Q.push(current->right);
        Q.pop();
    }
}

void PreOrder(Node *root){
    if(root != NULL){
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

int main()
{
  struct Node *root = NULL;

  /* Constructing tree given in the above figure */
    root = Insert(root, 1);
    root = Insert(root, 2);
    root = Insert(root, 3);
    root = Insert(root, 4);
    root = Insert(root, 5);
    root = Insert(root, 6);
    root = Insert(root, 7);
    root = Insert(root, 8);
    root = Insert(root, 9);
    root = Insert(root, 10);

    PrintOrderLevel(root);  

    root = DeleteNode(root, 5);
    root = DeleteNode(root, 8);
    cout << endl;
    
    PrintOrderLevel(root);
    Node *find = Search(root, 10);
    if(find!= NULL)
    cout << "\nFound node: " << find->data << endl;
    else
    cout << "\nNode not found!" << endl;
    return 0;
}   