#include <iostream>
#include <cstdio>
using namespace std;

const int MAXM=100;
const int MAXN=100;

int nextTable[MAXM];
int pattern[MAXM];
int text[MAXN];

void GetNextTable(int m){
    int j=0;
    nextTable[j]=-1;
    int i=nextTable[j];
    while(j<m){
        if(i==-1 || pattern[j]==pattern[i]){
            i++;
            j++;
            nextTable[j]=i;
        }
        else i=nextTable[i];
    }
    return ;
}

int KMP(int n, int m){
    GetNextTable(m);
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(j==-1 || text[i]==pattern[j]){
            i++;
            j++;
        }
        else j=nextTable[j];
    }
    if(j==m) return i-j+1;
    else return -1;
}

int main(){
    int caseNum;
    scanf("%d", &caseNum);
    int n,m;
    while(caseNum--){
        scanf("%d%d",&n, &m);
        for(int i=0; i<n; ++i) scanf("%d", &text[i]);
        for(int i=0; i<m; ++i) scanf("%d",&pattern[i]);
        printf("%d\n", KMP(n,m));
    }
    return 0;
}