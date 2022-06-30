#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN=10000;

int dp[MAXN];
int v[MAXN];
int w[MAXN];
int k[MAXN];
int value[MAXN];
int weight[MAXN];

int main(){
    int caseNum;
    scanf("%d", &caseNum);
    while(caseNum--){
        int n,m;
        scanf("%d%d", &m, &n);
        int number=0;
        for(int i=0; i<n; ++i){
            scanf("%d%d%d", &w[i], &v[i], &k[i]);
            for(int j=1; j<=k[i]; j<<=1){
                value[number] = j*v[i];
                weight[number] = j*w[i];
                number++;
                k[i]-=j;
            }
            if(k[i]>0){
                value[number] = k[i]*v[i];
                weight[number]=k[i]*w[i];
                number++;
            }
        }
        for(int i=0; i<=m; ++i) dp[i]=0;
        for(int i=0; i<number; ++i){
            for(int j=m; j>=weight[i]; --j) dp[j]=max(dp[j], dp[j-weight[i]]+value[i]);
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}