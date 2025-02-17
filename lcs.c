#include <stdio.h>

int lcs(char s1[], char s2[],int n,int m);

int max(int a, int b);


int main(){
	int n, m;
    scanf("%d\n%d", &n, &m);
    // printf("%d, %d", n,  m);
    char s1[n];
    char s2[m];
    scanf("%s", s1);
    scanf("%s", s2);
    printf("%d", lcs(s1, s2, n, m));
	return 0;
}

int lcs(char s1[], char s2[],int n,int m){
    int dp[m+1][n+1];
    for (int i = 0; i<=n; i++){
        for(int j = 0; j<=m; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }else if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            // printf("%d(%d, %d), ", dp[i][j], i, j);
        }
        // printf("\n");
    }
    // printf("%d, %d, %d\n", n,m,dp[n][m]);
    return dp[n][m];
}

int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}