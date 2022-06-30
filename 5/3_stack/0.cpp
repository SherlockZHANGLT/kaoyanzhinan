#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

stack<int> mys;

int main(){
    for(int i=0; i<10; ++i) mys.push(i);
    printf("the top of mys: %d\n", mys.top());
    printf("the size of mys: %d\n", mys.size());
    int sum=0;
    while(!mys.empty()){
        sum+=mys.top();
        mys.pop();
    }
    printf("sum: %d\n", sum);
    return 0;
}