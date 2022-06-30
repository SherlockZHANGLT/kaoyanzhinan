#include<iostream>
using namespace std;

int Reverse(int x){
    int rx=0;
    while(x!= 0){
        rx*=10;
        rx+= x%10;
        x/=10;
    }
    return rx;
}

int main(){
    for(int i=0; i<=256; i++){
        if(i*i == Reverse(i*i)) cout<<i<<endl;
    }
    return 0;
}