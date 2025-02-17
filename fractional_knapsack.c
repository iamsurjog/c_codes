#include<stdio.h>
#include<stdlib.h>

typedef struct data{
    float weight;
    float value;
    float ratio;
    float usage;
}data;

int comperator(const void* a,const void* b);
void fractional_knappy(data arr[], int n, float w);

int main(){
    int n;
    float w;
    scanf("%d", &n);
    data arr[n];
    scanf("%f", &w);
    for(int i = 0; i<n; i++){
        scanf("%f", &arr[i].weight);
        scanf("%f", &arr[i].value);
        arr[i].ratio = arr[i].value/arr[i].weight;
    }
    qsort(arr, n, sizeof(data), comperator);
    fractional_knappy(arr, n, w);
    for(int i = 0; i<n; i++){
        printf("%.2f, %.2f, %.2f, %.2f\n", arr[i].value, arr[i].weight, arr[i].ratio, arr[i].usage);
    }
    return 0;
}

void fractional_knappy(data arr[], int n, float w){
    int flag = 0;
    for(int i = 0; i<n; i++){
        if(flag == 0){
            if(w - arr[i].weight > 0){
                arr[i].usage = 1;
                w = w - arr[i].weight;
            }else{
                arr[i].usage = w/arr[i].weight;
                flag = 1;
            }
        }else{
            arr[i].usage = 0;
        }
    }
}

int comperator(const void* a,const void* b){
    data a_struct =  *(data*)a;
    data b_struct =  *(data*)b;
    if(b_struct.ratio > a_struct.ratio){
        return 1;
    }else if(b_struct.ratio < a_struct.ratio){
        return -1;
    }
    return 0;
}
