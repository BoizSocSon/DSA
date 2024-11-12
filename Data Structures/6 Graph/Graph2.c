#include <stdio.h>
#include <stdlib.h>
#define N 100001

struct Node{
    int value;
    struct Node *next;
};

struct QNode{
    int value;
    struct QNode *next;
};

typedef struct Node Node;
typedef struct QNode QNode;

int n, m;
Node *arr[N];
QNode *head, *tail;
int d[N];

void InitQueue(){
    head = NULL;
    tail = NULL;
}

int IsEmpty(){
    return head == NULL && tail == NULL;
}

QNode *CreateQNode(int value){
    QNode *newNode = (QNode*)malloc(sizeof(QNode));
    if(!newNode){
        printf("Memory error\n");
        return NULL;
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

QNode *Pop(){
    if(IsEmpty())
        return NULL;
    QNode *temp = head;
    head = head->next;
    if(head == NULL)
        tail = NULL;
    return temp;
}

void Push(int v){
    QNode *newNode = CreateQNode(v);
    if(!newNode)
        return;
    if(IsEmpty()){
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

Node *CreateNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory error\n");
        return NULL;
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

Node *AddNode(int data, Node *head){
    Node *newNode = CreateNode(data);
    if(!newNode)
        return head;
    newNode->next = head;
    return newNode;
}

void Input(){
    scanf("%d %d", &n , &m);
    for(int i = 1; i <= m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        arr[u] = AddNode(v, arr[u]);
        arr[v] = AddNode(u, arr[v]);
    }
}

void PrintGraph(){
    for(int i = 1; i <= n; i++){
        printf("A[%d]: ", i);
        for(Node *p = arr[i]; p!= NULL; p = p->next){
            printf("%d ", p->value);
        }
        printf("\n");
    }
}

int BFS(int u){
    d[u] = 0;
    InitQueue();
    Push(u);
    while(!IsEmpty()){
        QNode *p = Pop();
        int v = p->value;
        for(Node *q = arr[v]; q!= NULL; q = q->next){
            int x = q->value;
            if(d[x] > -1){
                if((d[v] + d[x]) % 2 == 0)
                    return 0;
            } else {
                d[x] = d[v] + 1;
                Push(x);
            }
        }
    }
    return 1;
}

void Solve(){
    int ans = 1;
    for(int v = 1; v <= n; v++)
        d[v] = -1;

    for(int v = 1; v <= n; v++){
        if(d[v] == -1){
            int ok = BFS(v);
            if(ok == 0){
                ans = 0;
                break;
            }
        }
    }
    printf("%d\n", ans);
}

int main(){
    Input();
    Solve();
    return 0;
}