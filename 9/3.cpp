#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

const int MAXN=30;
int p,q;
bool visit[MAXN][MAXN];
int direction[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};

bool DFS(int x, int y, int step, string ans){
    if(step==p*q) {
        cout<<ans<<endl<<endl;
        return true;
    }
    else{
        for(int i=0; i<8; ++i){
            int nx=x+direction[i][0];
            int ny=y+direction[i][1];
            char col=ny+'A';
            char row=nx+'1';
            if(nx<0 || nx>=p || ny<0 || ny>=q || visit[nx][ny]) continue;
            visit[nx][ny]=true;
            if(DFS(nx, ny, step+1, ans+col+row)) return true;
            visit[nx][ny]=false;
        }
    }
    return false;
}

int main(){
    int n;
    scanf("%d", &n);
    int caseNum=0;
    while(n--){
        scanf("%d%d", &p, &q);
        memset(visit, false, sizeof(visit));
        cout<<"Scenario #"<<++caseNum<<":"<<endl;
        visit[0][0]=true;
        if(!DFS(0,0,1,"A1")) cout<<"impossible"<<endl<<endl;
    }
    return 0;
}