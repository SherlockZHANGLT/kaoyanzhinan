#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int> myPriorityQueue;

int main(){
    printf("the size of myPriorityQueue: %d\n", myPriorityQueue.size());
    myPriorityQueue.push(20);
    myPriorityQueue.push(100);
    myPriorityQueue.push(30);
    myPriorityQueue.push(50);
    printf("the top of myPriorityQueue: %d\n", myPriorityQueue.top());
    printf("the size of myPriorityQueue: %d\n", myPriorityQueue.size());
    int sum=0;
    while(!myPriorityQueue.empty()){
        printf("%d ",myPriorityQueue.top());
        sum+=myPriorityQueue.top();
        myPriorityQueue.pop();
    }
    printf("sum: %d\n", sum);
    return 0;
}