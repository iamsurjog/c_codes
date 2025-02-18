#include <stdio.h>

int mcm(int arr[], int n);
int min(int a, int b);

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
        for (int j = 0; j<n; j++){
            dp[i][j] = 0;
        }
    }
    for(int len = 2; len<n; len++){
        for(int i = 0; i<n-len; i++){
            int j = i+len;
            dp[i][j] = __INT_MAX__;
            for(int k=i+1; k<j; k++){
                int cost = dp[i][k] + dp[k][j] + arr[i] * arr[j] * arr[k];
                dp[i][j] = min(dp[i][j], cost);
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

int min(int a, int b){
    if(a<b){
        return a;
    }
    return b;
}
