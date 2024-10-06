#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StackNode {
    char value;
    struct StackNode* next;
};

typedef struct StackNode Node;

Node *top = NULL;

Node *createNode(char value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void push(char c){
    Node *newNode = createNode(c);
    if(newNode == NULL)
    return;
    newNode->next = top;
    top = newNode;
}

char pop(){
    Node *temp = top;
    top = (top)->next;
    char c = temp->value;
    free(temp);
    return c;
}

int empty(){
    return (top == NULL);
}

int match(char o, char c){
    if(o == '(' && c == ')') return 1;
    if(o == '[' && c == ']') return 1;
    if(o == '{' && c == '}') return 1;
    return 0;
}

int check(char *s){
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            push(s[i]);
        } else { //s[i] la ngoac dong
            if(empty() == 1) return 0;
            char o = pop(); // lay ra ngoac mo tu stack
            if(match(o, s[i]) == 0) return 0;
        }
    }
}

int main(){
    char input[100];
    printf("Enter a string of parentheses: ");
    scanf("%s", input);

    if(check(input)){
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }

    return 0;
}