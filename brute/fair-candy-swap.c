
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize){
    int* res = (int*)malloc(2*sizeof(int));
    *(returnSize) = 2;
    int totalA = 0, totalB = 0;

    for(int i=0; i<aliceSizesSize; ++i) {
        totalA += *(aliceSizes+i);
    }
    for(int i=0; i<bobSizesSize; ++i) {
        totalB += *(bobSizes+i);
    }

    qsort(bobSizes, 0, bobSizesSize, cmpfunc);
    for(int i=0; i<bobSizesSize; ++i) {
        for(int j=0; j<aliceSizesSize; ++j) {
            int test = (totalA-totalB+ bobSizes[i]*2)/2;
            if(test == aliceSizes[j]) {
                res[0] = aliceSizes[j];
                res[1] = bobSizes[i];
                return res;
            }
        }
    }

    return res;
}