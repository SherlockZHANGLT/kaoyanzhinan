#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

queue<int> myq;

int main(){
    for(int i=0; i<10; ++i) myq.push(i);
    printf("the front of myq :%d\n", myq.front());
    printf("the back of myq :%d\n", myq.back());
    printf("the size of myq :%d\n", myq.size());
    int sum=0;
    while(!myq.empty()){
        sum+=myq.front();
        myq.pop();
    }
    printf("sum: %d\n", sum);
    return 0;
}