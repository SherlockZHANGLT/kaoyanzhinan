#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
using namespace std;

struct Complex{
    int real;
    int imag;
    Complex(int a, int b): real(a), imag(b){}
    bool operator< (Complex c) const{
        return real* real + imag* imag < c.real*c.real +c.imag * c.imag;
    }
};

int main(){
    int n;
    while(scanf("%d", &n) !=EOF){
        priority_queue<Complex> myPriorityQueue;
        while(n--){
            string str;
            cin>>str;
            if(str=="Pop"){
                if(myPriorityQueue.empty()) printf("empty\n");
                else{
                    Complex current=myPriorityQueue.top();
                    myPriorityQueue.pop();
                    printf("%d+i%d\n", current.real, current.imag);
                    printf("SIZE = %d\n", myPriorityQueue.size());
                }
            }
            else{
                int a,b;
                scanf("%d+i%d", &a, &b);
                myPriorityQueue.push(Complex(a,b));
                printf("SIZE = %d\n", myPriorityQueue.size());
            }
        }
    }
    return 0;
}