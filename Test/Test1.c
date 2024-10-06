// NCr = (NCr - 1 * (N - r + 1)) / r

#include <stdio.h>
#include <stdlib.h>

// Function declaration
int** generate(int numRows, int* returnSize, int** returnColumnSizes);

int main() {
    int numRows = 5;  // Specify the number of rows
    int returnSize;   // To hold the size of the returned array (number of rows)
    int* returnColumnSizes;  // To hold the size of each row (number of columns per row)
    
    // Call the generate function
    int** result = generate(numRows, &returnSize, &returnColumnSizes);
    
    // Print the generated 2D array
    printf("Generated 2D array:\n");
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    // Free the allocated memory
    for (int i = 0; i < numRows; i++) {
        free(result[i]);  // Free each row
    }
    free(result);  // Free the array of pointers
    free(returnColumnSizes);  // Free the column sizes array

    return 0;
}

// Function implementation
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    // Allocate memory for the array of column sizes
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    // Allocate memory for the 2D array
    int **arr = (int**)malloc(numRows * sizeof(int*));

    // Initialize the 2D array and returnColumnSizes
    for (int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;  // Set the size for each row
        arr[i] = (int*)malloc((i + 1) * sizeof(int));  // Allocate memory for each row
        // for (int j = 0; j <= i; j++) {
        //     arr[i][j] = j + 1;  // Fill the array with some values (e.g., 1 to i+1)
        // }
    }

    int prev = 1;
    for(int i = 1; i <= numRows; i++) {
        int curr = (prev*(numRows - i + 1))/i;
        prev = curr;
    }

    // Set the returnSize
    *returnSize = numRows;

    return arr;
}
