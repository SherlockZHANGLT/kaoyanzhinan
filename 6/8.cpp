#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN=10001;
vector<int> prime;
bool isPrime[MAXN];

void Initial(){
    for(int i=0; i<MAXN; ++i) isPrime[i]=true;
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2; i<MAXN; ++i){
        if(!isPrime[i]) continue;
        if(i%10==1) prime.push_back(i);
        for(int j=i*i; j<MAXN; j+=i) isPrime[j]=false;
    }
    return ;
}

int main(){
    Initial();
    int n;
    while(scanf("%d",&n)!=EOF){
        bool isOutput=false;
        for(int i=0; i<prime.size() && prime[i]<n; ++i){
            isOutput=true;
            printf("%d ",prime[i]);
        }
        if(!isOutput) printf("-1");
        cout<<endl;
    }
    return 0;
}