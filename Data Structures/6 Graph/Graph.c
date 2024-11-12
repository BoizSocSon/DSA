#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100001

struct Node {
    int id;
    struct Node *next;
};

typedef struct Node Node;

int n, m;
Node *A[N];
bool visited[N];

Node *CreateNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->id = data;
    newNode->next = NULL;
    return newNode;
}

Node *add(int v, Node *h){
    Node *newNode = CreateNode(v);
    if(newNode == NULL) return h;
    newNode->next = h;
    return newNode;
}

void input(){
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= m; i++){
        int u, v;
        scanf("%d %d",&u,&v);
        A[u] = add(v,A[u]);
        A[v] = add(u,A[v]);
    }
}

void printGraph(){
    for(int i = 1; i <= m; i++){
        printf("A[%d]: ", i);
        for(Node *p = A[i]; p != NULL; p = p->next){
            printf("%d ",p->id);
        }
        printf("\n");
    }
}

void dfs(int u){
    visited[u] = true;
    printf("%d ", u);
    for(Node *p = A[u]; p!= NULL; p = p->next){
        if(visited[p->id] == false) 
            dfs(p->id);
    }
}

void solve(){
    for(int v = 1; v <= m; v++)
        visited[v] = false;

    int nbCC = 0; // Thành phần liên thông
    for(int v = 1; v <= m; v++){
        if(visited[v] == false){
            nbCC++; 
            dfs(v);
        }
    }
    printf("\nNumber of connected components: %d\n", nbCC);
}

int main(){
    input();
    // printGraph();
    solve();
    return 0;
}

// 8 8
// 1 2
// 1 7
// 1 8
// 2 7
// 4 5
// 4 6
// 5 6
// 7 8