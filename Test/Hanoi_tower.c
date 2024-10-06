#include <stdio.h>

int count = 0;

void move(int n, char A, char B, char C){
    if(n==1){
        count++;
        printf("Step %d: %c -> %c\n",count, A, B);
    } else {
        move(n-1, A,C,B);
        move(1,A,B,C);
        move(n-1, C, B, A);
    }
}

int main(void){
    int n;
    move(20,'A','B','C');
    return 0;
}