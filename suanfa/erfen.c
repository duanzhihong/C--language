//二分法，在有序的数据中查找
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define keyType int

// 非递归
int binary_search(int arr[], int key, int length) {
    int low = 0;
    int height = length-1;
    while(low < height) {
        int mid = ceil((low+height)/2);
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key){
            height = mid -1;
        } else {
            low = mid+1;
        }
    }
    return -1;
}

// 递归
void digui(int arr[], int key, int low,int height){
    int mid = ceil((low+height)/2);
    if (arr[mid] == key) {
        printf("%d\n",mid);
    }
    if (arr[mid] > key) {
        digui(arr, key, low, mid-1);
    }
    if (arr[mid] < key) {
        digui(arr, key, mid+1, height);
    }

}




int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 6;
    int length = sizeof(arr)/sizeof(arr[0]);
    // int location = binary_search(arr, key, length);
    // printf("%d", location);
    digui(arr, 5, 0, 9);
}