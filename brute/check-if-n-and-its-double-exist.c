

bool checkIfExist(int* arr, int arrSize)
{
    int idx = 0;
    int db[arrSize*2];
    if(arr[0] % 2 == 0) {
        db[idx++] = arr[0] / 2;
    }
    db[idx++] = arr[0] * 2;
    
    for(int i=1; i<arrSize; i++) {
        for(int j=0; j<idx; j++) {
            if(db[j] == arr[i]) {
                return true;
            }
        }
        if(arr[i] % 2 == 0) {
            db[idx++] = arr[i] / 2;
        }
        db[idx++] = arr[i] * 2;
    }
    
    return false;
}