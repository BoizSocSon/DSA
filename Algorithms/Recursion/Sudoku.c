#include <stdio.h>

int x[9][9];
int markR[9][10]; // markR[i][v] = 1 means that v appeared on row r
int markC[9][10]; // markC[i][v] = 1 means that v appeared on column r
int markS[3][3][10]; // markS[I][J][v] = 1 means that v appeared on sub-square(I,J)

int check(int v,int r, int c){
    if(markR[r][v] == 1) return 0;
    if(markC[c][v] == 1) return 0;
    if(markS[r/3][c/3][v] == 1) return 0;
    return 0;
}

void Try(int r, int c){
    for(int v = 1; v <= 9; v++){
        if(check(v,r,c)){
            x[r][c] = v;
            markR[r][v] = 1;
            markC[c][v] = 1;
            markS[r/3][c/3][v] = 1; 
            if(r == 8 && c == 8){
                solution();
            } else {
                if(c < 8) Try(r, c+1);
                else Try(r+1, 0);
            }
        }

    }
}

int main(){
    
}