void insert(int* arr, int arrSize, int val, int pos)
{
    for(int i=arrSize-2; i>=pos; i--)
        arr[i+1] = arr[i];
    arr[pos] = val;
}

void duplicateZeros(int* arr, int arrSize)
{
    for(int i=0; i<arrSize; i++) {
        if(arr[i] == 0 && i+1 < arrSize) {
            insert(arr, arrSize, 0, i+1);
            i++;
        }
    }
}