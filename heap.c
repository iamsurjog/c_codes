#include<stdio.h>
#include<stdlib.h>
#define size 8

int top = 3;
int heap[size-1];

void print(){
    for (int i = 0; i<top; i++){
        printf("%d, ", heap[i]);
    }
    printf("\n");
}

int left(int i){
    return (i+1)*2-1;
}
int right(int i){
    return (i+1) * 2;
}
int parent(int i){
    return (i-1)/2;
}

int heapify(int pos){
    if (heap[pos] < heap[left(pos)]){
        int temp = heap[pos];
        heap[pos] = heap[left(pos)];
        heap[left(pos)] = temp;
        if (heap[pos] < heap[right(pos)]){
            int temp = heap[pos];
            heap[pos] = heap[right(pos)];
            heap[right(pos)] = temp;
            return 1;
        }    
    }
    if (heap[pos] < heap[right(pos)]){
        int temp = heap[pos];
        heap[pos] = heap[right(pos)];
        heap[right(pos)] = temp;
        if (heap[pos] < heap[left(pos)]){
            int temp = heap[pos];
            heap[pos] = heap[left(pos)];
            heap[left(pos)] = temp;
            return -1;
        }    
    }
    return 0;
}

void add(int a){
    if (top < size){
        heap[top] = a;
        int temp = parent(top);
        top++;
        while (temp >= 0){
            heapify(temp);
            temp = parent(temp);
        }
    }else{
        printf("Heap full");
    }
}

int remove(){
    int t = heap[0];
    heap[0] = heap[top];
    top--;
    int temp = 0;
    while (temp<top){
        heapify(temp);

    }

}

int main(){
    heap[0] = 1;
    heap[1] = 2;
    heap[2] = 3;
    heapify(2);
    print();
    add(7);
    add(0);
    print();
    // remove();
    // print();

}