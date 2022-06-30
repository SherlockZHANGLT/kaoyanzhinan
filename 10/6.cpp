#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) !=EOF){
        priority_queue<int, vector<int>, greater<int>> myPriorityQueue;
        while(n--){
            int x;
            scanf("%d", &x);
            myPriorityQueue.push(x);
        }
        int ans=0;
        while(1<myPriorityQueue.size()){
            int a=myPriorityQueue.top();
            myPriorityQueue.pop();
            int b=myPriorityQueue.top();
            myPriorityQueue.pop();
            ans+=a+b;
            myPriorityQueue.push(a+b);
        }
        printf("%d\n", ans);
    }
    return 0;
}