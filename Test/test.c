#include <stdio.h>

struct Node{
    int data;
    struct Node *next;
}

typedef struct Node Node;

Node *graph[101];

Node *createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(!newNode)
        return NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node *head, int data){
    Node *newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void Input(int vertices, int edges){
    int u, v;
    for(int i=0; i<edges; i++){
        scanf("%d %d", &u, &v);
        addNode(graph[u], v);
        addNode(graph[v], u);
    }
}

void PrintGraph(int vertices, int edges){
    for(int i=1; i<=vertices; i++){
        printf("%d: ", i);
        Node *temp = graph[i];
        while(temp!=NULL){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void BFS(int u){
    int visited[101] = {0};
    visited[u] = 1;
    printf("%d ", u);
    Node *temp = graph[u];
    while(temp!=NULL){
        if(!visited[temp->data]){
            BFS(temp->data);
        }
        temp = temp->next;
    }
}

int main(){

}