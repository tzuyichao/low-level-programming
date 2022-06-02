#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int n = matrixColSize[0];
    int* returnColSize = (int*)malloc(n*sizeof(int));

    int** res = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; ++i) {
        res[i] = (int*)malloc(matrixSize*sizeof(int));
        returnColSize[i] = matrixSize;
    }
    *returnSize = n;
    *returnColumnSizes = returnColSize;
    
    printf("%d %d\n", *returnSize, (*returnColumnSizes)[0]);
    
    for(int i=0; i<matrixSize; ++i) {
        for(int j=0; j<n; ++j) {
            res[j][i] = matrix[i][j];
        }
    }
    
    return res;
}

int main() {
    int m = 3;
    int colSize[3] = {3, 3, 3};
    int** matrix = (int**) malloc(m*sizeof(int*));
    for(int i=0; i<m; ++i) {
        matrix[i] = (int*) malloc(colSize[i]*sizeof(int));
    }

    matrix[0][0] = 1;
    matrix[0][1] = 1;
    matrix[0][2] = 1;
    matrix[1][0] = 2;
    matrix[1][1] = 2;
    matrix[1][2] = 2;
    matrix[2][0] = 3;
    matrix[2][1] = 3;
    matrix[2][2] = 3;

    for(int i=0; i<3; ++i) {
        for(int j=0; j<colSize[i]; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int r;
    int* c;
    printf("before transpose...");
    int** res = transpose(matrix, m, colSize, &r, &c);
    // printf("r: %d\n", r);
    // for(int i=0; i<r; ++i) {
    //     printf("%d ", c[i]);
    // }
    for(int i=0; i<r; ++i) {
        for(int j=0; j<c[i]; ++j) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<r; ++i) {
        free(res[i]);
    }
    free(res);

    for(int i=0; i<m; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}