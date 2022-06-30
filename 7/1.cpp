#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int a;
    while(scanf("%d", &a)!=EOF){
        int min=0;
        int max=0;
        if(a%2==0){
            min=a/4+(a%4)/2;
            max=a/2;
        }
        printf("%d %d\n", min, max);
    }
    return 0;
}