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


// T1, T2, T3 and T4 are subtrees.
//          y                                      x 
//         / \                                   /   \
//        x   T4      Right Rotate (z)          z      y
//       / \          - - - - - - - - ->      /  \    /  \ 
//      z   T2                               T1  T3  T2  T4
//     / \
//   T1   T3
Node *RightRotate(Node *y){
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}


//   x                                y
//  /  \                            /   \ 
// T1   y     Left Rotate(z)       z      x
//     /  \   - - - - - - - ->    / \    / \
//    T2   z                     T1  T2 T3  T4
//        / \
//      T3  T4

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


//     T1, T2, T3 and T4 are subtrees.
//          z                                      y 
//         / \                                   /   \
//        y   T4      Right Rotate (z)          x      z
//       / \          - - - - - - - - ->      /  \    /  \ 
//      x   T3                               T1  T2  T3  T4
//     / \
//   T1   T2
    if(balance > 1 && key < node->left->data)
        return RightRotate(node);


//   z                                y
//  /  \                            /   \ 
// T1   y     Left Rotate(z)       z      x
//     /  \   - - - - - - - ->    / \    / \
//    T2   x                     T1  T2 T3  T4
//        / \
//      T3  T4
    if(balance < -1 && key > node->right->data)
        return LeftRotate(node);


//      z                               z                           x
//     / \                            /   \                        /  \ 
//    y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
//   / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
// T1   x                          y    T3                    T1  T2 T3  T4
//     / \                        / \
//   T2   T3                    T1   T2
    if(balance > 1 && key > node->left->data){
        node->left = LeftRotate(node->left);
        return RightRotate(node);
    }


//    z                            z                            x
//   / \                          / \                          /  \ 
// T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
//     / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
//    x   T4                      T2   y                  T1  T2  T3  T4
//   / \                              /  \
// T2   T3                           T3   T4
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
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == nullptr)
        return root;

    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if ( key < root->data )
        root->left = DeleteNode(root->left, key);

    // If the key to be deleted is greater than the
    // root's key, then it lies in right subtree
    else if( key > root->data )
        root->right = DeleteNode(root->right, key);

    // if key is same as root's key, then This is
    // the node to be deleted
    else
    {
        // node with only one child or no child
        // if( (root->left == NULL) || (root->right == NULL) )
        // {
        //     struct Node *temp = root->left ? root->left : root->right;

        //     // No child case
        //     if (temp == NULL)
        //     {
        //         temp = root;
        //         root = NULL;
        //     }
        //     else // One child case
        //         *root = *temp; // Copy the contents of
        //                     // the non-empty child
        //     free(temp);
        // }
        // else
        // {
        //     // node with two children: Get the inorder
        //     // successor (smallest in the right subtree)
        //     struct Node* temp = minValueNode(root->right);

        //     // Copy the inorder successor's data to this node
        //     root->data = temp->data;

        //     // Delete the inorder successor
        //     root->right = DeleteNode(root->right, temp->data);
        // }

        if(root->left != NULL && root->right != NULL){
            Node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = DeleteNode(root->right, temp->data);
        } else {
            Node *temp = root;
            if(root->left == NULL)
                root = root->right;
            else if(root->right == NULL)
                root = root->left;
            free(temp);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
      return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = GetBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && GetBalance(root->left) >= 0) 
        return RightRotate(root);

    // Left Right Case
    if (balance > 1 && GetBalance(root->left) < 0)
    {
        root->left =  LeftRotate(root->left);
        return RightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && GetBalance(root->right) <= 0)
        return LeftRotate(root);

    // Right Left Case
    if (balance < -1 && GetBalance(root->right) > 0)
    {
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }

    return root;
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
    root = Insert(root, 9);
    root = Insert(root, 5);
    root = Insert(root, 10);
    root = Insert(root, 0);
    root = Insert(root, 6);
    root = Insert(root, 11);
    root = Insert(root, -1);
    root = Insert(root, 1);
    root = Insert(root, 2);

    /* The constructed AVL Tree would be
            9
           /  \
          1    10
        /  \     \
       0    5     11
      /    /  \
     -1   2    6
    */

    printf("Preorder traversal of the constructed AVL "
           "tree is \n");
    PreOrder(root);

    root = DeleteNode(root, 10);

    /* The AVL Tree after deletion of 10
            1
           /  \
          0    9
        /     /  \
       -1    5     11
           /  \
          2    6
    */

    printf("\nPreorder traversal after deletion of 10 \n");
    PreOrder(root);
    printf("\nLevel Order traversal of the constructed AVL "
           "tree is \n");
    PrintOrderLevel(root);
    return 0;
}   