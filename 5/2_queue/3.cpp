#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct animal{
    int number;
    int order;
    animal(int n, int o):number(n), order(o){}
};

int main(){
    queue<animal> cats;
    queue<animal> dogs;
    int n;
    int order=0;
    scanf("%d", &n);
    int method, type;
    for(int i=0; i<n; ++i){
        scanf("%d%d", &method, &type);
        if(method ==1){
            if(type>0) dogs.push(animal(type, order++));
            else cats.push(animal(type, order++));
        }
        else{
            if((type ==0 && dogs.empty() && cats.empty()) || (type==1 && dogs.empty()) || (type==-1 && cats.empty())) printf("sorry, there is no pet for you!");
            else if(type==0 && !dogs.empty() && !cats.empty()){
                if(dogs.front().order<cats.front().order){
                    printf("%d ", dogs.front().number);
                    dogs.pop();
                }
                else{
                    printf("%d ", cats.front().number);
                    cats.pop();
                }
            }
            else if(type==0 && dogs.empty()){
                printf("%d ",cats.front().number);
                cats.pop();
            }
            else if(type==0 && cats.empty()){
                printf("%d ",dogs.front().number);
                dogs.pop();
            }
            else if(type ==1){
                printf("%d ",dogs.front().number);
                dogs.pop();
            }
            else if(type ==-1){
                printf("%d ",cats.front().number);
                cats.pop();
            }
        }
    }
    return 0;
}