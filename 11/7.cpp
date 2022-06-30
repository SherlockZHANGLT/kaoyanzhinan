#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

const int MAXN=1001;
const int INF= INT_MAX;

struct Edge{
    int to;
    int length;
    int price;
    Edge(int t, int l, int p): to(t), length(l), price(p){}
};

struct Point{
    int number;
    int distance;
    Point(int n, int d):number(n), distance(d){}
    bool operator<(const Point& p) const{
        return distance>p.distance;
    }
};

vector<Edge> graph[MAXN];
int dis[MAXN];
int cost[MAXN];

void Dijkstra(int s){
    priority_queue<Point> myPriorityQueue;
    dis[s]=0;
    cost[s]=0;
    myPriorityQueue.push(Point(s, dis[s]));
    while(!myPriorityQueue.empty()){
        int u=myPriorityQueue.top().number;
        myPriorityQueue.pop();
        for(int i=0; i<graph[u].size(); ++i){
            int v=graph[u][i].to;
            int l=graph[u][i].length;
            int p=graph[u][i].price;
            if(dis[v]>dis[u]+l || (dis[v]==dis[u]+l && cost[v]>cost[u]+p)){
                dis[v]=dis[u]+l;
                cost[v]=cost[u]+p;
                myPriorityQueue.push(Point(v, dis[v]));
            }
        }
    }
    return ;
}

int main(){
    int n,m;
    while(scanf("%d%d", &n, &m)!=EOF){
        if(n==0 && m==0) break;
        memset(graph, 0, sizeof(graph));
        fill(dis, dis+n+1, INF);
        fill(cost, cost+n+1, INF);
        while(m--){
            int from, to, length, price;
            scanf("%d%d%d%d", &from, &to, &length, &price);
            graph[from].push_back(Edge(to, length, price));
            graph[to].push_back(Edge(from, length, price)); 
        }
        int s,t;
        scanf("%d%d", &s, &t);
        Dijkstra(s);
        printf("%d %d\n", dis[t], cost[t]);
    }
    return 0;
}