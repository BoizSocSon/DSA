#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType{
    int value;
    struct NodeType* next;
} Node;

Node *first;

Node *makeNode(int v){
    Node *p = (Node *)malloc(sizeof(Node));
    p->value = v;
    p->next = NULL;
    return p;
}

void printList(Node *h){
    Node *p = h;
    while(p != NULL){
        printf("%d ", p->value);
        p = p->next;
    }
}

Node *addLast(int v, Node *h){
    Node *q = makeNode(v);
    if(h == NULL){
        return q;
    }
    Node *p = h;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = q;
    return h;
}

Node *removeNode(int v, Node *h){
    if(h == NULL) return NULL;
    if(h->value == v){
        Node *tmp = h;
        h = h->next;
        free(tmp);
        return h;
    }
    Node *p = h;
    while(p->next != NULL){
        if(p->next->value == v)
            break;
        p = p->next;
    }
    if(p->next != NULL){
        Node *tmp = p->next;
        p->next = tmp->next;
        free(tmp);
    }
    return h;
}

Node *removeNodeRecursive(int v, Node *h){
    if(h == NULL) return NULL;
    if(h->value == v){
        Node *tmp = h;
        h = h->next;
        free(tmp);
        return h;
    }
    h->next = removeNodeRecursive(v, h->next);
    return h;
}

Node *insertFirst(int v, Node *h){
    Node *newNode = makeNode(v);
    newNode->next = h;
    return newNode;
}

Node *insertBefore(int v, int u, Node *h){
    Node *newNode = makeNode(v);
    Node *p = h;
    while(p->next != NULL){
        if(p->next->value == u)
            break;
        p = p->next;
    }
    if(p->next!= NULL){
        newNode->next = p->next;
        p->next = newNode;
    }
    return h;
}

Node *insertAfter(int v, int u, Node *h){
    Node *newNode = makeNode(v);
    Node *p = h;
    while(p!= NULL){
        if(p->value == u)
            break;
        p = p->next;
    }
    if(p!= NULL){
        newNode->next = p->next;
        p->next = newNode;
    }
    return h;
}

Node *reverseList(Node *h){
    Node *prevH = NULL;
    Node *current = h;
    while(current != NULL){
        Node *tmp = current->next;
        current->next = prevH;
        prevH = current;
        current = tmp;
    }
    return prevH;
}

// void freeList(Node *h){
//     if(h == NULL) return;
//     while(h != NULL){
//         Node *tmp = h;
//         h = h->next;
//         free(tmp);
//     }
//     free(h);
// }

void freeList(Node *h){
    if(h == NULL) return;
    freeList(h->next);
    free(h);
}

int main(){
    first = NULL;
    for(int i = 1; i <= 10; i++){
        first = addLast(i, first);
    }
    first = insertFirst(3, first);
    first = insertBefore(2, 5, first);
    first = insertAfter(4, 2, first);
    printList(first);
    printf("\n");
    // first = removeNode(7, first);
    first = removeNodeRecursive(8, first);
    printList(first);

    first = reverseList(first);
    printf("\n");
    printList(first);

    freeList(first);
    
    
    return 0;
 
}
