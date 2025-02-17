#include<stdio.h>
#include<stdlib.h>
#define inf INT_MAX

void min(int arr[7], int ans[2]);
void prim(int graph[7][7]);
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
    prim(graph);
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

void prim(int graph[7][7]){
    int checked[7] = {0};  
    for(int i = 1; i < 7; i++){
        checked[i] = -1;
    }
    int w[7];
    int v[7];
    int ans[2];

    for(int edges = 0; edges < 6; edges++){  
        for(int i = 0; i < 7; i++){
            w[i] = inf;
            v[i] = -1;
        }

        for(int i = 0; i < 7 && checked[i] != -1; i++){
            int u = checked[i];
            min(graph[u], ans);
            if(ans[1] != -1 && ans[0] < w[u]){
                w[u] = ans[0];
                v[u] = ans[1];
            }
        }

        min(w, ans);
        int u = ans[1]; 
        printf("%d - %d: %d\n", u + 1, v[u] + 1, w[u]);

        graph[u][v[u]] = inf;
        graph[v[u]][u] = inf;

        for(int i = 0; i < 7; i++){
            if(checked[i] == -1){
                checked[i] = v[u];
                break;
            }
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
