#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=1000;
struct JavaBean{
    double weight;
    double cost;
};
JavaBean arr[MAXN];

bool Compare(JavaBean x, JavaBean y){
    return (x.weight/x.cost) > (y.weight/y.cost);
}

int main(){
    int m,n;
    while(scanf("%d%d", &m, &n) !=EOF){
        if(m==-1 && n==-1) break;
        for(int i=0; i<n; ++i) scanf("%lf%lf", &arr[i].weight, &arr[i].cost);
        sort(arr, arr+n, Compare);
        double ans=0;
        for(int i=0; i<n; ++i){
            if(m>=arr[i].cost){
                m-=arr[i].cost;
                ans+=arr[i].weight;
            }
            else{
                ans+=arr[i].weight*(m/arr[i].cost);
                break;
            }
        }
        printf("%.3f\n", ans);
    }
    return 0;
}