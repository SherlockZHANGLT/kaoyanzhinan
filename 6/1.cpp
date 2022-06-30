#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    unsigned int n;
    while(scanf("%d",&n) !=EOF){
        vector<int> binary;
        while(n!=0){
            binary.push_back(n%2);
            n/=2;
        }
        reverse(binary.begin(),binary.end());
        for(int i=0; i<binary.size(); ++i){
            printf("%d",binary[i]);
        }
        cout<<endl;
    }
    return 0;
}