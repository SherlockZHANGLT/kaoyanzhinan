#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=25;
int side;
int m;
int sticks[MAXN];
bool visit[MAXN];

bool DFS(int sum, int number, int position){
    if(number==3) return true;
    int sample=0;
    for(int i=position; i<m; ++i){
        if(visit[i] || sum+sticks[i]>side || sticks[i]==sample) continue;
        visit[i]=true;
        if(sum+sticks[i]==side){
            if(DFS(0,number+1,0)) return true;
            else sample=sticks[i];
        }
        else{
            if(DFS(sum+sticks[i],number,i+1)) return true;
            else sample=sticks[i];
        }
        visit[i]=false;
    }
    return false;
}

bool Compare(int x, int y){
    return x>y;
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int length=0;
        scanf("%d", &m);
        for(int i=0; i<m; ++i){
            scanf("%d", &sticks[i]);
            length+=sticks[i];
        }
        memset(visit, false, sizeof(visit));
        if(length%4!=0){
            printf("no\n");
            continue;
        }
        side=length/4;
        sort(sticks, sticks+m, Compare);
        if(sticks[0]>side){
            printf("no\n");
            continue;
        }
        if(DFS(0,0,0)) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}