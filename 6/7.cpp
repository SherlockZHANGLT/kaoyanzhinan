#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

bool Judge(int x){
    if(x<2) return false;
    int bound=sqrt(x);
    for(int i=2; i<=bound; ++i){
        if(x%i==0) return false;
    }
    return true;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(Judge(n)) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}