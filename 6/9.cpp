#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 10001;
vector<int> prime;
bool isPrime[MAXN];

void Initial(){
    for(int i=0; i<MAXN; ++i) isPrime[i]=true;
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2; i<MAXN; ++i){
        if(!isPrime[i]) continue;
        prime.push_back(i);
        for(int j=i*i; j<MAXN; j+=i) isPrime[j]=false;
    }
    return ;
}

int main(){
    Initial();
    int n;
    while(scanf("%d",&n)!=EOF){
        int ans=0;
        for(int i=0; i<prime.size() && prime[i]<=n; ++i){
            int factor=prime[i];
            while(n%factor==0){
                n/=factor;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}