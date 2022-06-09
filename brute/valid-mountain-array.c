

bool validMountainArray(int* arr, int arrSize){
    if(arrSize < 3)
        return false;
    int m = 0;
    int c = arr[0];
    for(int i=1; i<arrSize; i++) {
        if(arr[i] > c) {
            c = arr[i];
            m = i;
        }
    }
    if(m == 0 || m == arrSize - 1)
        return false;
    for(int i=0; i<m-1; i++) {
        if(arr[i] >= arr[i+1])
            return false;
    }
    for(int i=m; i<arrSize-1; i++) {
        if(arr[i] <= arr[i+1])
            return false;
    }
    
    return true;
}