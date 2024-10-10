#include <iostream>
using namespace std;

struct StackNode
{
    int data;
    StackNode *next;
};

StackNode *CreateNode(int data);
bool IsEmpty(StackNode *top);
void Push(StackNode **top, int data);
int Pop(StackNode **top);
void ShowStack(StackNode *top);

int main(){
    StackNode *top = nullptr;
    Push(&top, 1); 
    Push(&top, 2);
    Push(&top, 3);
    ShowStack(top);
    cout << "\nThe value was popped from stack: " << Pop(&top) << endl;
    ShowStack(top);
    return 0;
}

StackNode *CreateNode(int data){
    StackNode *newNode = new StackNode;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

bool IsEmpty(StackNode *top){
    return top == nullptr;
}

void Push(StackNode **top, int data){
    StackNode *newNode = CreateNode(data);
    if (*top == nullptr) {
        *top = newNode;
        return;
    }
    newNode->next = *top;
    *top = newNode;
}

int Pop(StackNode **top){
    if (IsEmpty(*top)) {
        cout << "Stack is empty\n";
        return 0;
    }
    int data = (*top)->data;
    StackNode *temp = *top;
    *top = (*top)->next;
    delete temp;
    return data;
}

void ShowStack(StackNode *top){
    while (top != nullptr) {
        cout << top->data << " ";
        top = top->next;
    }
}
