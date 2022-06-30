#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN=25;

int height[MAXN];
int dp[MAXN];

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        for(int i=0; i<n; ++i) scanf("%d", &height[i]);
        int ans=0;
        for(int i=0; i<n; ++i){
            dp[i]=1;
            for(int j=0; j<i; ++j){
                if(height[i]<=height[j]) dp[i]=max(dp[i], dp[j]+1);
            }
            ans=max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}