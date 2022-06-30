#include <iostream>
#include <cstdio>
using namespace std;

int FE(int a, int b, int mod){
    int ans=1;
    while(b!=0){
        if(b%2==1){
            ans*=a;
            ans%=mod;
        }
        b/=2;
        a*=a;
        a%=mod;
    }
    return ans;
}

int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        if(a==0 && b==0) break;
        printf("%d\n",FE(a,b,1000));
    }
    return 0;
}