#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode *next;
};

struct Queue {
    ListNode *front;
    ListNode *rear;
    int size;  // Added to track queue size
};

Queue* CreateQueue();
bool IsEmptyQueue(Queue *Q);
void EnQueue(Queue *Q, int data);
int DeQueue(Queue *Q);
void DeleteQueue(Queue *Q);
int QueueSize(Queue *Q);

int main() {
    Queue *myQueue = CreateQueue();

    if (myQueue == nullptr) {
        cout << "Failed to create the queue." << endl;
        return -1;
    }

    // Enqueue some elements
    EnQueue(myQueue, 10);
    EnQueue(myQueue, 20);
    EnQueue(myQueue, 30);

    // Dequeue and print elements
    while (!IsEmptyQueue(myQueue)) {
        cout << "Dequeued: " << DeQueue(myQueue) << endl;
    }

    // Delete the queue
    DeleteQueue(myQueue);

    return 0;
}

Queue* CreateQueue() {
    Queue *Q = new Queue;
    if (!Q)
        return nullptr;
    Q->front = nullptr;
    Q->rear = nullptr;
    Q->size = 0;  
    return Q;
}

bool IsEmptyQueue(Queue *Q) {
    return Q->front == nullptr;
}

void EnQueue(Queue *Q, int data) {
    ListNode *newNode = new ListNode;
    if (!newNode) {
        cout << "Memory allocation failed." << endl;
        return;
    }
    newNode->data = data;
    newNode->next = nullptr;
    if (Q->rear) {
        Q->rear->next = newNode;
    }
    Q->rear = newNode;
    if (Q->front == nullptr) {
        Q->front = Q->rear;
    }
    Q->size++; 
}

int DeQueue(Queue *Q) {
    if (IsEmptyQueue(Q)) {
        cout << "Queue is empty." << endl;
        return -1;  
    }
    int data = Q->front->data;
    ListNode *temp = Q->front;
    Q->front = Q->front->next;
    if (Q->front == nullptr) {
        Q->rear = nullptr;
    }
    delete temp;
    Q->size--;  
    return data;
}

void DeleteQueue(Queue *Q) {
    while (Q->front) {
        ListNode *temp = Q->front;
        Q->front = Q->front->next;
        delete temp;
    }
    delete Q;
}

int QueueSize(Queue *Q) {
    return Q->size; 
}
