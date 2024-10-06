#include <stdio.h>
#define N 20

int x[N];
int k,n;

void solution(){
    for(int i = 1; i <= k; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
}

int check(int v, int i){
    return 1;
}

void Try(int i){
    for(int v = x[i-1] + 1; v <= n-k+i; v++){
        if(check(v, i)){
            x[i] = v;
            if(i == k) solution();
            else Try(i+1);
        }
    }
}

int main(){
    scanf("%d %d",&k, &n);
    Try(1);
    return 0;
}

