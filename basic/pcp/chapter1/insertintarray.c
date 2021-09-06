#include <stdio.h>

#define max 100

void main() {
    int p[max], n, i, j, k;

    printf("Enter length of array:");
    scanf("%d", &n);

    printf("Enter %d elements of array\n", n);
    for(i=0; i<n; i++) {
        scanf("%d", &p[i]);
    }
    printf("\nThe array is:\n");
    for(i=0; i<n; i++) {
        printf("%d\n", p[i]);
    }
    
    printf("\nEnter position where to insert:");
    scanf("%d", &k);
    k--;
    for(j=n-1; j>=k; j--) {
        p[j+1] = p[j];
    }
    printf("\nEnter the value to insrt:");
    scanf("%d", &p[k]);
    n++;
    printf("\nArray after insertion of element: \n");
    for(i=0; i<n; i++) {
        printf("%d\n", p[i]);
    }
}