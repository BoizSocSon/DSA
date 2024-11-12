#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUCKET_COUNT 101

struct StudentInformation {
    int ID;
    char Name[101];
    char Class[31];
};

struct AVLNode{
    struct StudentInformation infor;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
};

typedef struct AVLNode AVLNode;
typedef struct StudentInformation StudentInformation;

AVLNode *HashTable[BUCKET_COUNT] = {NULL};

int HashFunction(int id);
int Height(AVLNode *node);
int Max(int a, int b);
AVLNode* RightRotate(AVLNode *root);
AVLNode* LeftRotate(AVLNode *root);
int GetBalance(AVLNode *root);
AVLNode* CreateAVLNode();
AVLNode* InsertAVLNode(AVLNode *root, int id, const char *name, const char *class);
AVLNode *MinValue(AVLNode *root);
AVLNode *DeleteAVLNode(AVLNode *root, int id);
AVLNode *Search(AVLNode *root, int id);
void Insert(int id, const char *name, const char *class);
void Delete(int id);
void Infor(int id);

int main(){
    char command[10];
    int ID;
    char name[101];
    char studentClass[31];

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "Insert") == 0) {
            scanf("%d %s %s", &ID, name, studentClass);
            Insert(ID, name, studentClass);
        } else if (strcmp(command, "Infor") == 0) {
            scanf("%d", &ID);
            Infor(ID);
        } else if (strcmp(command, "Delete") == 0) {
            scanf("%d", &ID);
            Delete(ID);
        } else {
            printf("Lệnh không hợp lệ\n");
            break;
        }
    }

    return 0;
}

int HashFunction(int id){
    int primeMultiplier = 31;
    int hashvalue = (id* primeMultiplier)%BUCKET_COUNT;
    return hashvalue < 0 ? -hashvalue : hashvalue;
}

int Height(AVLNode *node){
    if(node == NULL)
        return 0;
    return node->height;
}

// 
int Max(int a, int b){
    return (a > b)? a : b;
}

// 
AVLNode* RightRotate(AVLNode *root){
    AVLNode *newRoot = root->left;
    AVLNode *temp = newRoot->right;

    newRoot->right = root;
    root->left = temp;

    root->height = Max(Height(root->left), Height(root->right)) + 1;
    newRoot->height = Max(Height(newRoot->left), Height(newRoot->right)) + 1;

    return newRoot;
}

//
AVLNode* LeftRotate(AVLNode *root){
    AVLNode *newRoot = root->right;
    AVLNode *temp = newRoot->left;

    newRoot->left = root;
    root->right = temp;

    root->height = Max(Height(root->left), Height(root->right)) + 1;
    newRoot->height = Max(Height(newRoot->left), Height(newRoot->right)) + 1;

    return newRoot;
}

int GetBalance(AVLNode *root){
    if(root == NULL) 
        return 0;
    return Height(root->left) - Height(root->right);
}

// 
AVLNode* CreateAVLNode(){
    AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
    if(!newNode){
        printf("Memory error\n");
        return NULL;
    }
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; 
    return newNode;
}

// 
AVLNode* InsertAVLNode(AVLNode *root, int id, const char *name, const char *class){
    if(root == NULL){
        root = CreateAVLNode();
        root->infor.ID = id;
        strcpy(root->infor.Name, name);
        strcpy(root->infor.Class, class);

        return root;
    }
    if(root->infor.ID < id) {
        root->right = InsertAVLNode(root->right, id, name, class);
    } else if (root->infor.ID > id) {
        root->left = InsertAVLNode(root->left, id, name, class);
    } else {
        // Update the information of the exsiting student
        printf("ID already exists\n");
        root->infor.ID = id;
        strcpy(root->infor.Name, name);
        strcpy(root->infor.Class, class);
        return root;
    }

    root->height = Max(Height(root->right), Height(root->left)) + 1;

    int balance = GetBalance(root);

    // Left Left Case
    if(balance > 1 && id < root->left->infor.ID) {
        return RightRotate(root);
    }

    // Left Right Case
    if(balance > 1 && id > root->left->infor.ID) {
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }

    // Right Right Case
    if(balance < -1 && id > root->right->infor.ID) {
        return LeftRotate(root);
    }
    
    // Right Left Case
    if(balance < -1 && id < root->right->infor.ID) {
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }

    return root;
}


//
AVLNode *MinValue(AVLNode *root) {
    AVLNode *current = root;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}

//
AVLNode *DeleteAVLNode(AVLNode *root, int id) {
    if (root == NULL)
        return root;
    
    if(id < root->infor.ID) {
        root->left = DeleteAVLNode(root->left, id);
    } else if (id > root->infor.ID) {
        root->right = DeleteAVLNode(root->right, id);
    } else {
        if(root->left != NULL && root->right != NULL){
            AVLNode *temp = MinValue(root->right);
            root->infor.ID = temp->infor.ID;
            strcpy(root->infor.Name, temp->infor.Name);
            strcpy(root->infor.Class, temp->infor.Class);
            root->right = DeleteAVLNode(root->right, temp->infor.ID);
        } else {
            AVLNode *temp = root;
            if(root->left == NULL)
                root = root->right;
            else if(root->right == NULL)
                root = root->left;
            free(temp);
        }
    }
    
    if (root == NULL)
        return root;

    root->height = Max(Height(root->left), Height(root->right)) + 1;
    
    int balance = GetBalance(root);
    
    // Left Left Case
    if(balance > 1 && GetBalance(root->left) >= 0) {
        return RightRotate(root);
    }
    
    // Left Right Case
    if(balance > 1 && GetBalance(root->left) < 0) {
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }
    
    // Right Right Case
    if(balance < -1 && GetBalance(root->right) <= 0) {
        return LeftRotate(root);
    }
    
    // Right Left Case
    if(balance < -1 && GetBalance(root->right) > 0) {
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }
    
    return root;
}

AVLNode *Search(AVLNode *root, int id){
    if(root == NULL || root->infor.ID == id){
        return root;
    } else if (id < root->infor.ID){
        return Search(root->left, id);
    } else if (id > root->infor.ID){
        return Search(root->right, id);
    }
    return NULL;
}

void Insert(int id, const char *name, const char *class){
    int index = HashFunction(id);
    HashTable[index] = InsertAVLNode(HashTable[index], id, name, class);
}

void Delete(int id){
    int index = HashFunction(id);
    HashTable[index] = DeleteAVLNode(HashTable[index], id);
}

void Infor(int id){
    int index = HashFunction(id);
    AVLNode *student = Search(HashTable[index], id);
    if(student!= NULL){
        printf("ID: %d\nName: %s\nClass: %s\n", student->infor.ID, student->infor.Name, student->infor.Class);
    } else {
        printf("NA,NA\n");
    }
}