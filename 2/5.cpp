#include<iostream>
#include<cstdio>
using namespace std;

char matrix[80][80];

int main(){
    int n;
    char a,b;
    bool firstCase = true;
    while(scanf("%d %c %c", &n, &a, &b) != EOF){
        if(firstCase == true) firstCase = false;
        else cout<<endl;
        for(int i=0; i<=n/2; i++){
            char c;
            if(i % 2 ==0) c=b;
            else c=a;
            for(int k=0; k<n-i*2; k++){
                matrix[i][i+k]=c;
                matrix[i+k][i]=c;
                matrix[n-i-1-k][n-i-1]=c;
                matrix[n-i-1][n-i-1-k]=c;
            }
        }
        if(n!=1){
            matrix[0][0]=' ';
            matrix[0][n-1]=' ';
            matrix[n-1][n-1]=' ';
            matrix[n-1][0]=' ';
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<matrix[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}