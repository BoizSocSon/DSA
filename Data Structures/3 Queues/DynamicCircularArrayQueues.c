#include <stdio.h>
#include <stdlib.h>

struct DynArrayQueue
{
    int front, rear;
    int capacity;
    int *array;
};

typedef struct DynArrayQueue DynArrayQueue;

DynArrayQueue *CreateDynQueue();
int IsEmptyQueue(DynArrayQueue *Q);
int IsFullQueue(DynArrayQueue *Q);
int QueueSize(DynArrayQueue *Q);
void ResizeQueue(DynArrayQueue *Q);
void EnQueue(DynArrayQueue *Q, int data);
void ResizeQueue(DynArrayQueue *Q);
int DeQueue(DynArrayQueue *Q);
void DeleteQueue(DynArrayQueue *Q);

int main(void) {
    DynArrayQueue *queue = CreateDynQueue();

    if (!queue) {
        printf("Failed to create queue\n");
        return 1;
    }

    // EnQueue some elements
    EnQueue(queue, 1);   //front 0 // rear 0 // capacity 1
    EnQueue(queue, 2);  
    EnQueue(queue, 3);
    EnQueue(queue, 4);
    EnQueue(queue, 5);

    printf("Queue size: %d\n", QueueSize(queue));

    // Dequeue some elements
    int dequeued = DeQueue(queue);
    printf("Dequeued: %d\n", dequeued);
    dequeued = DeQueue(queue);
    printf("Dequeued: %d\n", dequeued);

    printf("Queue size: %d\n", QueueSize(queue));

    // EnQueue some more elements
    EnQueue(queue, 6);
    EnQueue(queue, 7);
    EnQueue(queue, 8);

    printf("Queue size: %d\n", QueueSize(queue));

    // Delete the queue
    DeleteQueue(queue);

    return 0;
}

DynArrayQueue *CreateDynQueue(){
    DynArrayQueue *Q = (DynArrayQueue*)malloc(sizeof(DynArrayQueue));
    if(!Q){
        return NULL;
    }
    Q->capacity = 1;
    Q->front = Q->rear = -1;
    Q->array = (int*)malloc(sizeof(int));
    if(!Q->array){
        return NULL;
    }
    return Q;
}
int IsEmptyQueue(DynArrayQueue *Q){
    return Q->front == -1;
}

int IsFullQueue(DynArrayQueue *Q){
    return (Q->rear + 1) % Q->capacity == Q->front;
}

int QueueSize(DynArrayQueue *Q){
    if(Q->front == -1){
        return 0;
    }
    return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;
}

void EnQueue(DynArrayQueue *Q, int data){
    if(IsFullQueue(Q))
        ResizeQueue(Q);
    Q->rear = (Q->rear + 1) % Q->capacity;
    Q->array[Q->rear] = data;
    if(Q->front == -1)
        Q->front = Q->rear;
}

void ResizeQueue(DynArrayQueue *Q){
    int size = Q->capacity;
    Q->capacity = Q->capacity*2;
    Q->array = (int*)realloc(Q->array, Q->capacity);
    if(!Q->array){
        printf("Memory Error!");
        return;
    }
    if(Q->front > Q->rear){
        for(int i = 0; i < Q->front; i++){
            Q->array[i + size] = Q->array[i];
        }
        Q->rear = Q->rear + size;
    }
}

int DeQueue(DynArrayQueue *Q){
    int data = 0;
    if(IsEmptyQueue(Q)){
        printf("Queue is Empty!");
        return 0;
    }
    else{
        data = Q->array[Q->front];
        if(Q->front == Q->rear)
            Q->front = Q->rear = -1;
        else
            Q->front = (Q->front + 1) % Q->capacity;
    }
    return data;
}

void DeleteQueue(DynArrayQueue *Q){
    if(Q){
        if(Q->array)
            free(Q->array);
        free(Q);
    }
}