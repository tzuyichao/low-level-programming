#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int** dp;
    int m;
    int n;
} NumMatrix;


NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) 
{
    NumMatrix* obj = (NumMatrix*)malloc(sizeof(NumMatrix));
    obj->dp = (int**) malloc(matrixSize * sizeof(int*));
    obj->m = matrixSize;
    obj->n = matrixColSize[0];

    for(int i=0; i<obj->m; i++) {
        obj->dp[i] = (int*) malloc(obj->n * sizeof(int));
    }

    obj->dp[0][0] = matrix[0][0];
    for(int i=1; i<obj->m; i++)
        obj->dp[i][0] = obj->dp[i-1][0] + matrix[i][0];
    for(int i=1; i<obj->n; i++)
        obj->dp[0][i] = obj->dp[0][i-1] + matrix[0][i];
    for(int i=1; i<obj->m; i++) {
        for(int j=1; j<obj->n; j++) {
            obj->dp[i][j] = obj->dp[i-1][j] + obj->dp[i][j-1] + matrix[i][j] - obj->dp[i-1][j-1];
        }
    }

    return obj;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) 
{
    if(row1 == row2 && col1 == col2) {
        return obj->dp[row1][col1];
    }
    
    return obj->dp[row2][col2] - obj->dp[row2][col1-1] - obj->dp[row1-1][col2] + obj->dp[row1-1][col1-1];
}

void numMatrixFree(NumMatrix* obj) 
{
    free(obj->dp);
    free(obj);
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 
 * numMatrixFree(obj);
*/

int main() {
    
    return 0;
}