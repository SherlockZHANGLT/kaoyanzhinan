#include <iostream>
#include <cstdio>
using namespace std;

struct Matrix{
    int matrix[10][10];
    int row, col;
    Matrix(int r, int c):row(r), col(c){}
};

Matrix Multiply(Matrix x, Matrix y){
    Matrix ans(x.row, y.col);
    for(int i=0; i<x.row; ++i){
        for(int j=0; j<y.col; ++j){
            ans.matrix[i][j]=0;
            for(int k=0; k<x.col; ++k) ans.matrix[i][j]+=x.matrix[i][k]*y.matrix[k][j];
        }
    }
    return ans;
}

void PrintMatrix(Matrix x){
    for(int i=0; i<x.row; ++i){
        for(int j=0; j<x.col; ++j){
            printf("%d ",x.matrix[i][j]);
        }
        cout<<endl;
    }
    return ;
}

Matrix FE(Matrix x, int k){
    Matrix ans(x.row, x.col);
    for(int i=0; i<x.row; ++i){
        for(int j=0; j<x.col; ++j){
            if(i==j) ans.matrix[i][j]=1;
            else ans.matrix[i][j]=0;
        }
    }
    while(k!=0){
        if(k%2==1) ans=Multiply(ans,x);
        k/=2;
        x=Multiply(x,x);
    }
    return ans;
}

int main(){
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        Matrix x(n,n);
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j) scanf("%d",&x.matrix[i][j]);
        }
        Matrix ans=FE(x,k);
        PrintMatrix(ans);
    }
    return 0;
}