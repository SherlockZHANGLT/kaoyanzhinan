#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN=100;

int matrix[MAXN][MAXN];
int total[MAXN][MAXN];
int arr[MAXN];
int dp[MAXN];

int MaxSubsequence(int n){
    int maximum=arr[0];
    for(int i=0; i<n; ++i){
        if(i==0) dp[i]=arr[i];
        else dp[i]=max(arr[i], dp[i-1]+arr[i]);
        maximum=max(maximum, dp[i]);
    }
    return maximum;
}

int MaxSubmatrix(int n){
    int maximal=0;
    for(int i=0; i<n; ++i){
        for(int j=i; j<n; ++j){
            for(int k=0; k<n; ++k){
                if(i==0) arr[k]=total[j][k];
                else arr[k]=total[j][k]-total[i-1][k];
            }
            int current=MaxSubsequence(n);
            maximal=max(maximal, current);
        }
    }
    return maximal;
}

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j) scanf("%d", &matrix[i][j]);
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(i==0) total[i][j]=matrix[i][j];
                else total[i][j]=total[i-1][j]+matrix[i][j];
            }
        }
        int ans=MaxSubmatrix(n);
        printf("%d\n",ans);
    }
    return 0;
}