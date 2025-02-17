#include<stdio.h>
#include<stdlib.h>

typedef struct MinHeap
{
    int *A;
    int max_size;
    int size;
} MinHeap;

MinHeap * init_MinHeap(int max_size);
void read_inputMinHeap(MinHeap *Q, int n);
void buildMinHeap(MinHeap *Q);
void minHeapify(MinHeap *Q, int index);

int extractMin(MinHeap *Q);
void addElement(MinHeap *Q, int x);
void Heapsort(MinHeap *Q);
void printHeap(MinHeap *Q);



int main()
{
    MinHeap *Q;
    int choice=0, max_size, n, x;
    scanf("%d", &max_size);
    Q = init_MinHeap(max_size);
    scanf("%d", &n);
    read_inputMinHeap(Q, n);
    while(1)
    {   
        scanf("%d", &choice);
        //printf("Choice=%d\n", choice);
        // For initialization of link list
        if(choice==0)
        {
                init_MinHeap(max_size);
               
        }
        else if(choice ==1)
        {
            buildMinHeap(Q);
        }
        else if(choice==2)
        {      
               // printf("Enter the elements to be inserted \n");
                scanf("%d", &x);
                addElement(Q, x);
             
        }
        else if(choice==3)
        {
                x = extractMin(Q);
                printf("%d\n", x);
               
        }
        else if(choice==4)
        {
                printHeap(Q);
                
        }
        else if(choice ==5)
        {   
            Heapsort(Q);
            
        }
        else
            break;
    }
    return 0;
}


MinHeap * init_MinHeap(int max_size)
{
    MinHeap *Q;
    Q = (MinHeap*)malloc(sizeof(MinHeap));
    if(Q==NULL)
        return NULL;
    Q->A = (MinHeap*)malloc(sizeof(int) * max_size);
    if(Q->A == NULL)
    {
        free(Q);
        return NULL;
    }
    Q->A[0] = -999; // default value at index 0; start index from 1
    Q->max_size = max_size;
    Q->size = 0;
    return Q;
}

void read_inputMinHeap(MinHeap *Q, int n) {
    for (int i = 1; i <= n && i <= Q->max_size; i++) {
        scanf("%d, ", &Q->A[i]);
        Q->size++;
    }
    buildMinHeap(Q);
}

void buildMinHeap(MinHeap *Q) {
    for (int i = (Q->size / 2); i >= 1; i--) {
        minHeapify(Q, i);
    }
}

void minHeapify(MinHeap *Q, int index) {
    int left = 2 * index;
    int right = 2 * index + 1;
    int smallest = index;

    if (left <= Q->size && Q->A[left] < Q->A[smallest]) {
        smallest = left;
    }
    if (right <= Q->size && Q->A[right] < Q->A[smallest]) {
        smallest = right;
    }

    if (smallest != index) {
        int temp = Q->A[index];
        Q->A[index] = Q->A[smallest];
        Q->A[smallest] = temp;
        minHeapify(Q, smallest);
    }
}

int extractMin(MinHeap *Q) {
    if (Q->size < 1) {
        printf("Heap is empty.\n");
        return -9999;
    }

    int min = Q->A[1];
    Q->A[1] = Q->A[Q->size];
    Q->size--;
    minHeapify(Q, 1);

    return min;
}

void addElement(MinHeap *Q, int x) {
    if (Q->size >= Q->max_size) {
        printf("Heap is full.\n");
        return;
    }

    Q->size++;
    int i = Q->size;
    Q->A[i] = x;
    
    while ((i > 1) && (Q->A[i] <= Q->A[i / 2])) {
        int temp = Q->A[i];
        Q->A[i] = Q->A[i / 2];
        Q->A[i / 2] = temp;
        i = i / 2;
    }
    
    minHeapify(Q, i);

}

void printHeap(MinHeap *Q) {
    for (int i = 1; i <= Q->size; i++) {
        if(i != Q->size)
            printf("%d, ", Q->A[i]);
        else
            printf("%d", Q->A[i]);
    }
    printf("\n");
}

void Heapsort(MinHeap *Q) {
    int original_size = Q->size;
    int *sorted = malloc(sizeof(int) * (Q->size + 1));

    for (int i = 1; i <= original_size; i++) {
        sorted[i] = extractMin(Q);
    }

    for (int i = 1; i <= original_size; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    // Restore the original heap by reinserting sorted elements
    for (int i = 1; i <= original_size; i++) {
        Q->A[i] = sorted[i];
    }
    Q->size = original_size;
    buildMinHeap(Q);

    free(sorted);
}