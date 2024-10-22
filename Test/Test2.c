/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** pascalsTriangle = (int**)malloc(numRows * sizeof(int*));
    
    // Allocate space for the column sizes
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    
    // Set return size
    *returnSize = numRows;

    // Loop to generate each row of Pascal's Triangle
    for (int i = 0; i < numRows; i++) {
        // Allocate space for each row (i+1 elements in the i-th row)
        pascalsTriangle[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;  // Set the number of columns for the i-th row

        // First element in each row is always 1
        pascalsTriangle[i][0] = 1;

        // Calculate the rest of the elements in the row
        for (int j = 1; j < i; j++) {
            // Calculate value based on the previous row (using the relationship between elements)
            pascalsTriangle[i][j] = pascalsTriangle[i-1][j-1] + pascalsTriangle[i-1][j];
        }

        // Last element in each row is always 1 (if row has more than 1 element)
        pascalsTriangle[i][i] = 1;
    }

    return pascalsTriangle;
}