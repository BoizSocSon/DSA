#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node{
    int id;
    struct Node *leftMostChild;
    struct Node *rightSibling;
};

typedef struct Node Node;

Node *root;

Node *makeNode(int v){
    Node *p = (Node *)malloc(sizeof(Node));
    p->id = v;
    p->leftMostChild = NULL;
    p->rightSibling = NULL; 
    return p;
}

Node *find(int v, Node *r){
    if(r == NULL)
        return NULL;
    if(r->id == v)
        return r;
    Node *p = r->leftMostChild;
    while (p != NULL) { 
        Node *q = find(v, p);
        if(q != NULL)
            return q;
        p = p->rightSibling;
    }
    return NULL;
}

void insert(int u, int v){
    Node *r = find(v, root);
    Node *p = find(u, root);
    if(p != NULL) 
        return;
    p = makeNode(u);
    if(r->leftMostChild == NULL){
        r->leftMostChild = p;
    } else {
        Node *q = r->leftMostChild;
        while(q->rightSibling!=NULL)
            q = q->rightSibling;
        q->rightSibling = p;
    }
}   
 
void printTree(Node *r){
    if(r == NULL)
        return;
    printf("%d ", r->id);

    for(Node *p = r->leftMostChild; p != NULL; p = p->rightSibling){
        printf("%d ", p->id);
    }
    printf("\n");
    for(Node *p = r->leftMostChild; p != NULL; p = p->rightSibling){
        printTree(p);
    }
}

void inOrder(Node *r){
    if(r == NULL)
        return;
    Node *p = r->leftMostChild;
    inOrder(p) ;
    printf("%d ", r->id);
    if(p == NULL) 
        return;
    p = p->rightSibling;
    while(p != NULL){
        inOrder(p);
        p = p->rightSibling; 
    }
}

void preOrder(Node *r){
    if(r == NULL)
        return;
    printf("%d ", r->id);
    Node *p = r->leftMostChild;
    while(p != NULL){
        preOrder(p);
        p = p->rightSibling; 
    }
}

void postOrder(Node *r){
    if(r == NULL)
        return;
    Node *p = r->leftMostChild;
    while(p != NULL){
        postOrder(p);
        p = p->rightSibling; 
    }
    printf("%d ", r->id);
}

int count(Node *r){
    if(r == NULL) return 0;
    int ans = 1;
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        ans += count(p);
        p = p->rightSibling;
    }
    return ans;
}

int countLeaves(Node *r){
    if(r == NULL) return 0;
    if(r->leftMostChild == NULL) return 1;
    int ans = 0;
    for(Node *p = r->leftMostChild; p != NULL; p = p->rightSibling){
        ans += countLeaves(p);
    }
    return ans;
}

int heightNode(Node *r){
    if(r == NULL) return 0;
    int maxH = 0;
    for(Node *p = r->leftMostChild; p != NULL; p = p->rightSibling){
        int h = heightNode(p);
        if(h > maxH) maxH = h;
    }
    return maxH + 1;    
}

int height(int v){
    Node *r = find(v, root);
    return heightNode(r);
}

int depthNode(int v, Node *r, int d){
    if(r == NULL) return -1;
    if(r->id == v) return d;
    for(Node *p = r->leftMostChild; p != NULL; p = p->rightSibling){
        if(p->id == v) return d+1;
        int rs = depthNode(v, p, d+1);
        if(rs > -1) return rs;

    }
    return -1;
}

int depth(int v){
    return depthNode(v, root, 1);
}

int main(int argc, char **argv){
    freopen("tree.txt", "r", stdin);
    char cmd[50];
    while(1){
        scanf("%s", cmd);
        if(strcmp(cmd, "$MakeRoot") == 0){
            int v;
            scanf("%d", &v);
            root = makeNode(v);
        } else if (strcmp(cmd, "$Insert") == 0){
            int u, v;
            scanf("%d", &u);
            scanf("%d", &v);
            insert(u, v); 
        } else if (strcmp(cmd, "$InOrder") == 0) {
            inOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "$PreOrder") == 0) {
            preOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "$PostOrder") == 0) {
            postOrder (root);
            printf("\n");
        } else if (strcmp(cmd, "*") == 0) {
            break;
        }
    }
    // printTree(root);
    printf("\n");
    printf("Number of nodes: %d\n", count(root));
    printf("Number of leaves: %d\n", countLeaves(root));
    printf("Height: %d\n", height(10));
    printf("Depth: %d\n", depth(4));
    printf("\n");
    return 0; 
}