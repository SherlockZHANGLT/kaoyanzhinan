#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int h=0;
    cin>>h ;
    int row, col;
    while(h!=0){
        row = h;
        col = h+(h-1)*2;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(j < row+i*2) cout<<"*";
                else cout<<" ";
            }
            cout<<endl;
        }
        cin>>h;
    }
    return 0;
}