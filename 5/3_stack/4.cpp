#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

stack<long long> seq;

int main(){
    int n;
    long long num;
    while(scanf("%d",&n) !=EOF){
        while(n--){
            cin>>num;
            seq.push(num);
        }
        while(!seq.empty()){
            cout<<seq.top()<<" ";
            seq.pop();
        }
        cout<<endl;
    }
    return 0;
}