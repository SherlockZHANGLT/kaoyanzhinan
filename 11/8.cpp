#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=500;

vector<int> graph[MAXN];
int inDegree[MAXN];

bool TopologicalSort(int n){
    queue<int> node;
    for(int i=0; i<n; ++i){
        if(inDegree[i]==0) node.push(i);
    }
    int number=0;
    while(!node.empty()){
        int u=node.front();
        node.pop();
        number++;
        for(int i=0; i<graph[u].size(); ++i){
            int v=graph[u][i];
            inDegree[v]--;
            if(inDegree[v]==0) node.push(v);
        }
    }
    return n==number;
}

int main(){
    int n,m;
    while(scanf("%d%d", &n, &m)!=EOF){
        if(n==0 && m==0) break;
        memset(graph, 0, sizeof(graph));
        memset(inDegree, 0, sizeof(inDegree));
        while(m--){
            int from, to;
            scanf("%d%d", &from, &to);
            graph[from].push_back(to);
            inDegree[to]++;
        }
        if(TopologicalSort(n)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}