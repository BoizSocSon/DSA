#include <iostream>

using namespace std;

struct Queue{
    int front;
    int rear;
    int capacity;
    int* array;
};

Queue *newQueue(int size){
    Queue* queue = new Queue();
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = size;
    queue->array = new int[size];
    return queue;
}

bool IsEmpty(Queue* queue){
    return queue->front == -1;
}

bool IsFull(Queue* queue){
    return (queue->rear + 1) % queue->capacity == queue->front;
}

// capacity = 10
// rear = 9
// front = 8

int QueueSize(Queue* queue){
    return (queue->capacity - queue->front + queue->rear + 1) % queue->capacity;
}

int Front(Queue* queue){
    if(IsEmpty(queue)){
        cout << "Queue is empty, can't get front" << endl;
        return -1;
    }
    return queue->array[queue->front];
}

int Rear(Queue* queue){
    if(IsEmpty(queue)){
        cout << "Queue is empty, can't get rear" << endl;
        return -1;
    }
    return queue->array[queue->rear];
}

void EnQueue(Queue* queue, int item){
    if(IsFull(queue)){
        cout << "Queue is full, can't enqueue " << item << endl;
    }
    else{
        if(queue->front == -1)
            queue->front = queue->rear;
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->array[queue->rear] = item;
        cout << "Enqueued " << item << endl;
    }
}

int DeQueue(Queue *queue){
    int data = 0;
    if(IsEmpty(queue)){
        cout << "Queue is empty, can't dequeue" << endl;
        return -1;
    } else {
        data = queue->array[queue->front];
        if(queue->front == queue->rear)
            queue->front = queue->rear = -1;
        else
            queue->front = (queue->front + 1) % queue->capacity;
        cout << "Dequeued " << data << endl;
        return data;
    }
}

int main(){

}