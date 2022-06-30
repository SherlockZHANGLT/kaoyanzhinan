#include <iostream>
#include <cstdio>
using namespace std;

int Fibonacci(int n){
    if(n==1 || n==0) return n;
    else return Fibonacci(n-1) + Fibonacci(n-2);
}

int main(){
    int n;
    while(scanf("%d", &n) !=EOF) printf("%d\n",Fibonacci(n));
    return 0;
}