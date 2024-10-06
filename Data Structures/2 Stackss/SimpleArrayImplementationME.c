#include <stdio.h>
#define MAX 1000

int top;
int stack[MAX];

void push(int data) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = data;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return 0;
    } else {
        int data = stack[top--];
        return data;
    }
}

int main() {
    top = -1;
    int num = 0;
    int val;
    while(val != '\n') {
        printf("Enter an integer (or press Enter to stop): ");
        scanf("%d", &val);
        if(val!= '\n') {
            push(val);
            num++;
        }
    }
    
    return 0;
}
