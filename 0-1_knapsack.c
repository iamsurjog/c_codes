#include<stdio.h>

int knapSack(int w, int wt[], int val[], int n);

int max(int a, int b);

int main(){
    int n;
    int w;
    scanf("%d", &n);
    scanf("%d", &w);
    int profit[n];
    int weight[n];
    for(int i = 0; i<n; i++)
    printf("%d", knapSack(w, weight, profit, n));
    return 0;

}

knapSack(int W, int wt[], int val[], int n){
    int dp[n+1][W+1];
    for(int i = 0; i<=n; i++){
        for(int w = 0; w<=W; w++){
            if(i==0 || w==0){
                dp[i][w] = 0;
            }
            else if(wt[i-1] <= w){
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-wt[i]] + val[i-1]);
            }else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}