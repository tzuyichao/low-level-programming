#include <stdio.h>


void insert(int* nums1, int nums1Size, int val, int pos) 
{
    for(int i=nums1Size-2; i>=pos; i--) {
        nums1[i+1] = nums1[i];
    }
    nums1[pos] = val;
}

int posToInsert(int* nums1, int size, int val) 
{
    for(int i=0; i<size; i++) {
        if(nums1[i] > val) {
            return i;
        }
    }
    return size;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    if(nums1Size == nums2Size) {
        for(int i=0; i<nums2Size; i++) {
            nums1[i] = nums2[i];
        }
    } else {
        for(int i=0; i<n; i++) {
            int pos = posToInsert(nums1, m+i, nums2[i]);
            insert(nums1, nums1Size, nums2[i], pos);
        }
    }
}

int main() 
{
    int nums1[] = {1, 2, 3, 0, 0, 0};
    int nums2[] = {2, 5, 6};
    merge(nums1, 6, 3, nums2, 3, 3);
    for(int i=0; i<6; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");
}