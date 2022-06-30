#include <iostream>
#include <cstdio>
using namespace std;

int CountNodes(int m, int n){
    if(m>n) return 0;
    else return 1+CountNodes(m*2,n)+CountNodes(m*2+1,n);
}

int main(){
    int m,n;
    while(scanf("%d%d", &m, &n) !=EOF) printf("%d\n", CountNodes(m,n));
    return 0;
}