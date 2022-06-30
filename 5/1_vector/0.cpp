#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> myv;

int main(){
    for(int i=0;i<5; ++i){
        myv.push_back(i);
    }
    myv.insert(myv.begin(),3,15);
    myv.pop_back();
    for(int i=0; i<myv.size(); ++i) printf("%d ", myv[i]);
    printf("\n");
    myv.erase(myv.begin()+5, myv.end());
    vector<int>::iterator it;
    for(it=myv.begin(); it !=myv.end(); it++) printf("%d ", *it);
    printf("\n");
    myv.clear();
    return 0;
}