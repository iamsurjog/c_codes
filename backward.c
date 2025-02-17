#include<stdio.h>

int main(){
    int a = 10;
    int *ptr = &a;
    for(int i = 0; i <5000; i++){
        printf("%d-", *(ptr-i));
    }
}