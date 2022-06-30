#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN=1000;
int arr[MAXN];
int dp[MAXN];

int main(){
    int n;
    while(scanf("%d", &n) !=EOF){
        for(int i=0; i<n; ++i) scanf("%d", &arr[i]);
        int ans=arr[0];
        for(int i=0; i<n; ++i){
            dp[i]=arr[i];
            for(int j=0; j<i; ++j){
                if(arr[i]>=arr[j]) dp[i]=max(dp[i], dp[j]+arr[i]);
            }
            ans=max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}