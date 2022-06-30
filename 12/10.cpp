#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN=100;

int dp[MAXN][MAXN];
int matrix[MAXN][MAXN];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        for(int j=0; j<=i; ++j){
            scanf("%d", &matrix[i][j]);
            dp[i][j]=matrix[i][j];
        }
    }
    for(int i=n-2; i>=0; --i){
        for(int j=0; j<=i; ++j) dp[i][j]+=max(dp[i+1][j], dp[i+1][j+1]);
    }
    printf("%d\n", dp[0][0]);
    return 0;
}