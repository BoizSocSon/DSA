#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

struct Queue
{
    struct ListNode *front;
    struct ListNode *rear;
};

typedef struct ListNode ListNode;
typedef struct Queue Queue;

Queue *CreatQueue();
int IsEmptyQueue(Queue *Q);
void EnQueue(Queue *Q, int data);
int DeQueue(Queue *Q);
void DeleteQueue(Queue *Q);
int QueueSize(Queue *Q);

int main(void) {
    Queue *myQueue = CreatQueue();

    if (myQueue == NULL) {
        printf("Failed to create the queue.\n");
        return -1;
    }

    // Enqueue some elements
    EnQueue(myQueue, 10);
    EnQueue(myQueue, 20);
    EnQueue(myQueue, 30);

    // Dequeue and print elements
    while (!IsEmptyQueue(myQueue)) {
        printf("Dequeued: %d\n", DeQueue(myQueue));
    }

    // Delete the queue
    DeleteQueue(myQueue);

    return 0;
}

Queue *CreatQueue(){
    Queue *Q = (Queue*)malloc(sizeof(Queue));
    ListNode *temp = (ListNode*)malloc(sizeof(ListNode)); 
    if(!Q)
        return NULL;
    Q->front = NULL;
    Q->rear = NULL;
    return Q;
}

int IsEmptyQueue(Queue *Q){
    return Q->front == NULL;
}

void EnQueue(Queue *Q, int data){
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    if(!newNode)
        return ;
    newNode->data = data;
    newNode->next = NULL;
    if(Q->rear)
        Q->rear->next = newNode;
    Q->rear = newNode;
    if(Q->front == NULL)
        Q->front = Q->rear;
}

int DeQueue(Queue *Q){
    int data = 0;
    ListNode *temp = NULL;
    if(IsEmptyQueue(Q)){
        printf("Queue is empty\n");
        return 0;
    }
    else {
        temp = Q->front;
        data = Q->front->data;
        Q->front = Q->front->next;
        // if(Q->front == NULL)
        //     Q->rear = NULL;
        free(temp);
    }
    return data;
}

void DeleteQueue(Queue *Q){
    ListNode *temp = NULL;
    while(Q->front){
        temp = Q->front;
        Q->front = Q->front->next;
        free(temp);
    }
    free(Q);
    Q = NULL;
}

int QueueSize(Queue *Q) {
    int size = 0;
    ListNode *temp = Q->front;
    while (temp) {
        size++;
        temp = temp->next;
    }
    return size;
}