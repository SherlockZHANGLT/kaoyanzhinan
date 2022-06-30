#include<iostream>
using namespace std;

int Reverse(int input){
    int rx = 0;
    while(input !=0){
        rx*=10;
        rx+=input%10;
        input/=10;
    }
    return rx;
}

int main(){
    for(int i=1000; i<1112; i++){
        if(i*9 == Reverse(i)) cout<<i<<endl;
    }
    return 0;
}