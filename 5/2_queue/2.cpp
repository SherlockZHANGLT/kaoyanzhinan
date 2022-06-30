#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main(){
    int n, p, m;
    while(scanf("%d%d%d", &n, &p, &m) != EOF){
        if(n==0 && p==0 && m==0) break;
        queue<int> child;
        for(int i=1; i<=n; ++i) child.push(i);
        for(int i=1; i<p; ++i){
            child.push(child.front());
            child.pop();
        }
        while(!child.empty()){
            for(int i=1; i<m; ++i){
                child.push(child.front());
                child.pop();
            }
            if(child.size()==1) printf("%d\n", child.front());
            else printf("%d,",child.front());
            child.pop();
        }
    }
    return 0;
}