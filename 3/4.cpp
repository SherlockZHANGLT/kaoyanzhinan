#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN =200;
int arr[MAXN];

int main(){
    int n;
    while(scanf("%d", &n) !=EOF){
        for(int i=0; i<n; ++i) scanf("%d", &arr[i]);
        int x;
        scanf("%d", &x);
        int ans=-1;
        for(int i=0; i<n; ++i){
            if(arr[i] ==x){
                ans = i;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}