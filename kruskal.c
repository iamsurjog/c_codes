#include<stdio.h>
#include<stdlib.h>
#define inf INT_MAX

void min(int arr[7], int ans[2]);
void kruskal(int graph[7][7]);
int count(int arr[], int val, int n);

int main(){
    int graph[7][7] = {
        {inf, 28, inf, inf, inf, 10, inf}, 
        {28, inf, 16, inf, inf, inf, 14}, 
        {inf, 16, inf, 12, inf, inf, inf}, 
        {inf, inf, 12, inf, 22, inf, 18}, 
        {inf, inf, inf, 22, inf, 25, 24}, 
        {10, inf, inf, inf, 25, inf, inf}, 
        {inf, 14, inf, 18, 24, inf, inf}
    };
    kruskal(graph);
    return 0;
}

void min(int arr[7], int ans[2]){
    // 0 -> weight, 1 -> index
    ans[0] = inf;
    ans[1] = -1;
    for(int i = 0; i < 7; i++){
        if(arr[i] < ans[0]){
            ans[0] = arr[i];
            ans[1] = i;
        }
    }
}

int count(int arr[], int val, int n){
    int c = 0;
    for (int i = 0; i < n; i++){
        if(arr[i] == val) c++;
    }
    return c;
}

void kruskal(int graph[7][7]){
    int ans[2];
    int w[7];
    int v[7];
    int vertices[7];  
    for(int i = 0; i < 7; i++){
        vertices[i] = -1;
    }


    while(count(vertices, -1, 7) != 0){
        for(int i = 0; i < 7; i++){
            w[i] = inf;
            v[i] = -1;
        }
        for(int i = 0; i < 7; i++){
            min(graph[i], ans);
            if(ans[0] < w[i]){
                w[i] = ans[0];
                v[i] = ans[1];
            }
        }
        min(w, ans);

        if((count(vertices, ans[1], 7) + count(vertices, v[ans[1]], 7)) != 2){
            printf("%d - %d: %d\n", ans[1] + 1, v[ans[1]] + 1, w[ans[1]]);

            if(count(vertices, ans[1], 7) == 1){
                for(int i = 0; i < 7; i++){
                    if(vertices[i] == -1){
                        vertices[i] = v[ans[1]];
                        break;
                    }
                }
            }else if(count(vertices, v[ans[1]], 7) == 1){
                for(int i = 0; i < 7; i++){
                    if(vertices[i] == -1){
                        vertices[i] = ans[1];
                        break;
                    }
                }
            }else{
                for(int i = 0; i < 7; i++){
                    if(vertices[i] == -1){
                        vertices[i] = v[ans[1]];
                        vertices[i+1] = ans[1];
                        break;
                    }
                }
            }
        }
        graph[ans[1]][v[ans[1]]] = inf;
        graph[v[ans[1]]][ans[1]] = inf;
    }
}



