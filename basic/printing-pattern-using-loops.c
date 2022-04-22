#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
    int l = n+n-1;
    int res[l][l];
    
    int k = l;
    int x = 0;
    int y = 0;
    for(int c=n; c>0; c--) {
        for(int i=x; i<k; i++) {
            res[i][y] = c;
            res[i][k-1] = c;
        }
        for(int i=y; i<k; i++) {
            res[x][i] = c;
            res[k-1][i] = c;
        }
        x += 1;
        y += 1;
        k -= 1;
    }

    for(int i=0; i<l; i++) {
        for(int j=0; j<l; j++) {
            printf("(%d, %d)= %d ", i, j, res[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}