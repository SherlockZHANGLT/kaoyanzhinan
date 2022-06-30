#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 10001;
bool arr[MAXN];

int main(){
    int l, m;
    scanf("%d %d", &l, &m);
    for(int i=0; i<=l; i++) arr[i]=true;
    int number = l+1;
    int a,b;
    while(m--){
        scanf("%d %d", &a, &b);
        for(int i=a; i<=b; ++i){
            if(arr[i]){
                arr[i] = false;
                number--;
            }
        }
    }
    printf("%d\n",number);
    return 0;
}