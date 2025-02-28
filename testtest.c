#include <stdio.h>

int mcm(int arr[], int n);

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int res = mcm(arr, n);
    printf("%d", res);
	return 0;
}

int mcm(int arr[], int n){
    int dp[n][n];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            dp[i][j] = 0;
        }
    }
    for(int len = 2; len<n; len++){
        for(int i = 0; i<n-len; i++){
            int j = i+len;
            dp[i][j] = __INT_MAX__;
            for(int k = i+1; k<j; k++){
                int cost = dp[i][k] + dp[k][j] + arr[i]*arr[j]*arr[k];
                if (cost < dp[i][j]){
                    dp[i][j] = cost;
                }
            }
        }
    }

    for(int i = 0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%d, ", dp[i][j]);
        }
        printf("\n");
    }

    return dp[0][n-1];
}

// int mcm(int arr[], int n){
    // int dp[n][n];
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<n; j++){
    //         dp[i][j] = 0;
    //     }
    // }
    // for(int len = 2; len<n; len++){
    //     for(int i = 0; i < n - len; i++){
    //         int j = i+len;
    //         dp[i][j] = __INT_MAX__;
    //         for(int k = i+1; k<j; k++){
    //             int cost = dp[i][k] + dp[k][j] + arr[i]*arr[j]*arr[k];
    //             if(dp[i][j] > cost){
    //                 dp[i][j] = cost;
    //             }
    //         }
    //     }
    // }
//     return dp[0][n-1];
// }

// int lcs(char s1[], char s2[],int n,int m);
// int max(int a, int b);


// int main(){
// 	int n, m;
//     scanf("%d\n%d", &n, &m);
//     // printf("%d, %d", n,  m);
//     char s1[n];
//     char s2[m];
//     scanf("%s", s1);
//     scanf("%s", s2);
//     printf("%d", lcs(s1, s2, n, m));
// 	return 0;
// }

// int lcs(char s1[], char s2[],int n,int m){
//     int dp[n+1][m+1];
//     for(int i = 0; i<=n; i++){
//         for(int j = 0; j<=m; j++){
//             if(i==0 || j==0){
//                 dp[i][j] = 0;
//             }
//             else if(s1[i-1]==s2[j-1]){
//                 dp[i][j] = dp[i-1][j-1] + 1;
//             }else{
//                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//             }
//         }
//     }
//     return dp[n][m];
// }

// int max(int a, int b){
//     if (a>b){
//         return a;
//     }
//     return b;
// }

// int knapSack(int W, int wt[], int val[], int n);

// int main(){
//     int n;
//     int w;
//     scanf("%d", &n);
//     scanf("%d", &w);
//     int profit[n];
//     int weight[n];
//     for(int i = 0; i<n; i++){
//         scanf("%d, %d", &weight[i], &profit[i]);
//     }
//     // for(int i = 0; i<n; i++){
//     //     printf("%d, %d\n", weight[i], profit[i]);
//     // }
//     int res = knapSack(w, weight, profit, n);
//     printf("%d", res);
//     return 0;

// }

// int knapSack(int W, int wt[], int val[], int n){
//     int dp[n+1][W+1];
//     for (int i = 0; i<=n; i++){
//         for (int w = 0; w<=W; w++){
//             if(i==0||w==0){
//                 dp[i][w] = 0;
//             }else if(wt[i-1] <= w){
//                 dp[i][w] = max(dp[i-1][w], dp[i-1][w-wt[i]] + val[i-1]);
//             }else{
//                 dp[i][w] = dp[i-1][w];
//             }
//             printf("%d, ", dp[i][w]);
//         }
//         printf("\n");
//     }
//     return dp[n][W];
// }
