// NCr = (NCr - 1 * (N - r + 1)) / r

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    
    *returnSize = rowIndex + 1;
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    int numRows = *returnSize;

    result[0] = 1;
    for(int i = 1; i <= rowIndex; i++){
        result[i] = (result[i-1] * (rowIndex - i + 1)) / i;
    }
    return result;
}

int main(){
    int rowIndex = 5;
    int* returnSize;
    int* result = getRow(rowIndex, &returnSize);
}
