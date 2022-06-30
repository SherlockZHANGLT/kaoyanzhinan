#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int INF = INT_MAX /10;
const int MAXN=10000;

int dp[MAXN];
int v[MAXN];
int w[MAXN];

int main(){
    int caseNum;
    scanf("%d", &caseNum);
    while(caseNum--){
        int e,f;
        scanf("%d%d",&e, &f);
        int m=f-e;
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; ++i) scanf("%d%d", &v[i], &w[i]);
        dp[0]=0;
        for(int i=1; i<=m; ++i) dp[i]=INF;
        for(int i=0; i<n; ++i){
            for(int j=w[i]; j<=m; ++j) dp[j]=min(dp[j], dp[j-w[i]]+v[i]);
        }
        if(dp[m]==INF) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n", dp[m]);
    }
    return 0;
}