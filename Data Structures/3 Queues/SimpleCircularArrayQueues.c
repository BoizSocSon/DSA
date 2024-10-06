#include <stdio.h>
#include <stdlib.h>

struct ArrayQueue
{
    int front, rear;
    int capacity;
    int *array;
};

typedef struct ArrayQueue ArrayQueue;

ArrayQueue *Queue(int size);
int IsEmptyQueue(ArrayQueue *Q);
int IsFullQueue(ArrayQueue *Q);
int QueueSize(ArrayQueue *Q);
void EnQueue(ArrayQueue *Q, int data);
int DeQueue(ArrayQueue *Q);
void DeleteQueue(ArrayQueue *Q);

int main(void){
    ArrayQueue *queue = Queue(5); // Create a queue of size 5

    EnQueue(queue, 10); // Add 10 to the queue
    EnQueue(queue, 20); // Add 20 to the queue
    EnQueue(queue, 30); // Add 30 to the queue
    EnQueue(queue, 40); // Add 40 to the queue
    EnQueue(queue, 50); // Add 50 to the queue
    
    // printf("Queue size: %d\n", QueueSize(queue)); // Output: Queue size: 3

    printf("Dequeued: %d\n", DeQueue(queue)); // Output: Dequeued: 10

    // printf("Queue size: %d\n", QueueSize(queue)); // Output: Queue size: 2

    printf("Dequeued: %d\n", DeQueue(queue)); // Output: Dequeued: 20

    // printf("Queue size: %d\n", QueueSize(queue)); // Output: Queue size: 1

    // printf("Dequeued: %d\n", DeQueue(queue)); // Output: Dequeued: 30
    EnQueue(queue, 10); // Add 10 to the queue
    EnQueue(queue, 20); // Add 20 to the queue

    // printf("Queue size: %d\n", QueueSize(queue)); // Output: Queue size: 0

    DeleteQueue(queue); // Delete the queue

    return 0;
}

ArrayQueue *Queue(int size){
    ArrayQueue *Q = (ArrayQueue*)malloc(sizeof(ArrayQueue));
    if(!Q)
        return NULL;
    Q->capacity = size;
    Q->front = Q->rear = -1;
    Q->array = (int*)malloc(sizeof(int)*size);
    if(!Q->array)
        return NULL;
    return Q;
}

int IsEmptyQueue(ArrayQueue *Q){
    return Q->front == -1;
}

int IsFullQueue(ArrayQueue *Q){
    return (Q->rear+1) % Q->capacity == Q->front;
}

int QueueSize(ArrayQueue *Q){
    // if(Q->front == -1){
    //     return 0;
    // }
    return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;
}

void EnQueue(ArrayQueue *Q, int data){
    if(IsFullQueue(Q)){
        printf("Queue is full\n");
    }
    else {
        Q->rear = (Q->rear + 1) % Q->capacity;
        Q->array[Q->rear] = data;
        if(Q->front == -1)
            Q->front = Q->rear;
    }
}

int DeQueue(ArrayQueue *Q){
    int data = 0;
    if(IsEmptyQueue(Q)){
        printf("Queue is empty\n");
        return 0;
    }
    else {
        data = Q->array[Q->front];
        if(Q->front == Q->rear)
            Q->front = Q->rear = -1;
        else
            Q->front = (Q->front + 1) % Q->capacity;
    }
    return data;
}

void DeleteQueue(ArrayQueue *Q){
    if(Q){
        if(Q->array)
            free(Q->array);
        free(Q);
    }
}