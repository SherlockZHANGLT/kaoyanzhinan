#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN=100;
int dp[2*MAXN][MAXN];
int matrix[2*MAXN][MAXN];

int main(){
    int caseNum;
    scanf("%d", &caseNum);
    int casenumber=caseNum;
    while(caseNum--){
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; ++i){
            for(int j=0; j<=i; ++j){
                scanf("%d", &matrix[i][j]);
                dp[i][j]=matrix[i][j];
            } 
        }
        for(int i=n; i<2*n-1; ++i){
            for(int j=0; j<=2*(n-1)-i; ++j){
                scanf("%d", &matrix[i][j]);
                dp[i][j]=matrix[i][j];
            }
        }
        for(int i=2*(n-1)-1; i>=n-1; --i){
            for(int j=0; j<=2*(n-1)-i; ++j){
                if(j==0) dp[i][j]+=dp[i+1][j];
                else if(j==2*(n-1)-i) dp[i][j]+=dp[i+1][j-1];
                else dp[i][j]+=max(dp[i+1][j], dp[i+1][j-1]);
            }
        }
        for(int i=n-2; i>=0; --i){
            for(int j=0; j<=i; ++j) dp[i][j]+=max(dp[i+1][j], dp[i+1][j+1]);
        }
        printf("Case %d: %d\n", casenumber-caseNum, dp[0][0]);
    }
    return 0;
}