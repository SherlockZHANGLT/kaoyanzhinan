#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

const int MAXN=1e5+7;
const int INF= INT_MAX;
const int MOD=1e9+7;

vector<int> graph[MAXN];
int inDegree[MAXN];
long long earliest[MAXN];
long long latest[MAXN];
long long time[MAXN];

long long CriticalPath(int n){
    vector<int> topology;
    queue<int> node;
    for(int i=1; i<=n; ++i){
        if(inDegree[i]==0) node.push(i);
    }
    long long totalTime=0;
    while(!node.empty()){
        int u=node.front();
        topology.push_back(u);
        node.pop();
        for(int i=0; i<graph[u].size(); ++i){
            int v=graph[u][i];
            earliest[v]=max(earliest[v], earliest[u]+time[u]);
            inDegree[v]--;
            if(inDegree[v]==0){
                node.push(v);
                totalTime=max(totalTime, earliest[v]+time[v]);
            }
        }
    }
    for(int i=topology.size()-1; i>=0; --i){
        int u=topology[i];
        if(graph[u].size()==0) latest[u]=totalTime-time[u];
        else latest[u]=INF;
        for(int j=0; j<graph[u].size(); ++j){
            int v=graph[u][j];
            latest[u]=min(latest[u], latest[v]-time[u]);
        }
    }
    return totalTime;
}

int main(){
    int n,m;
    while(scanf("%d%d", &n, &m)!=EOF){
        memset(graph, 0, sizeof(graph));
        memset(earliest, 0, sizeof(earliest));
        memset(latest, 0, sizeof(latest));
        memset(inDegree, 0, sizeof(inDegree));
        memset(time, 0, sizeof(time));
        for(int i=1; i<=n; ++i){
            scanf("%lld", &time[i]);
        }
        while(m--){
            int from, to;
            scanf("%d%d", &from, &to);
            graph[from].push_back(to);
            inDegree[to]++;
        }
        long long totalTime=CriticalPath(n);
        long long ans=1;
        for(int i=1; i<=n; ++i){
            ans*=latest[i]-earliest[i]+1;
            ans%=MOD;
        }
        printf("%lld\n%lld\n", totalTime, ans);
    }
    return 0;
}