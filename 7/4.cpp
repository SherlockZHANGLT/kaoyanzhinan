#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Program{
    int startTime;
    int endTime;
};

const int MAXN=100;
Program arr[MAXN];

bool Compare(Program x, Program y){
    return x.endTime<y.endTime;
}

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        if(n==0) break;
        for(int i=0; i<n; ++i) scanf("%d%d", &arr[i].startTime, &arr[i].endTime);
        sort(arr, arr+n, Compare);
        int curTime=0;
        int ans=0;
        for(int i=0; i<n; ++i){
            if(curTime<=arr[i].startTime){
                curTime=arr[i].endTime;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}