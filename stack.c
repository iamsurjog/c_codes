#include<stdio.h>
#include<time.h>

int LinearSearch(int arr[], int val, int start, int len){
    if (start == len){
        return -1;
    }
    if (arr[start] == val){
        return start;
    }else{
        return LinearSearch(arr, val, start+1, len);
    }
}


int BinarySearch(int arr[], int low, int high, int val)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == val)
            return mid;

        if (arr[mid] < val)
            return BinarySearch(arr, low, mid - 1, val);

        else
            return BinarySearch(arr, mid + 1, high, val);
    }

    return -1;
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int val = 3;

    //binary search
    clock_t t; 
    t = clock(); 
    int c = BinarySearch(arr, 0, n-1, val);
    t = clock() - t;
    printf("%d\n", c);
    double time_taken = ((double)t)/CLOCKS_PER_SEC; 
    printf("The binary search took %f seconds to execute \n", time_taken);

    //linear search
    t = clock(); 
    c = LinearSearch(arr, val, 0, n-1);
    t = clock() - t;
    printf("%d\n", c);
    time_taken = ((double)t)/CLOCKS_PER_SEC; 
    printf("The linear search took %f seconds to execute \n", time_taken);
}