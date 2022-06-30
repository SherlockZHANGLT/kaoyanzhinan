#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN=10000;
int father[MAXN];
int height[MAXN];
int inDegree[MAXN];
bool visit[MAXN];

void Initial(){
    for(int i=0; i<MAXN; ++i){
        father[i]=i;
        height[i]=0;
        inDegree[i]=0;
        visit[i]=false;
    }
}

int Find(int x){
    if(x!=father[x]) father[x]=Find(father[x]);
    return father[x];
}

void Union(int x, int y){
    x=Find(x);
    y=Find(y);
    if(x!=y){
        if(height[x]<height[y]) father[x]=y;
        else if(height[x]>height[y]) father[y]=x;
        else{
            father[y]=x;
            height[x]++;
        }
    }
    return;
}

bool IsTree(){
    bool flag=true;
    int component=0;
    int root=0;
    for(int i=0; i<MAXN; ++i){
        if(!visit[i]) continue;
        if(father[i]==i) component++;
        if(inDegree[i]==0) root++;
        else if(inDegree[i]>1) flag=false;
    }
    if(component !=1 || root !=1) flag=false;
    if(component ==0 && root==0) flag=true;
    return flag;
}

int main(){
    int x,y;
    int caseNum=0;
    Initial();
    while(scanf("%d%d", &x, &y) !=EOF){
        if(x==-1 && y==-1) break;
        if(x==0 && y==0){
            if(IsTree()) printf("Case %d is a tree.\n", ++caseNum);
            else printf("Case %d is not a tree.\n", ++caseNum);
            Initial();
        }
        else{
            Union(x,y);
            inDegree[y]++;
            visit[x]=true;
            visit[y]=true;
        }
    }
    return 0;
}