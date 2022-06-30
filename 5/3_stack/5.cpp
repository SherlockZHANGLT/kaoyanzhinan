#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;

int main(){
    string str;
    while(cin>>str){
        stack<int> bra;
        string ans(str.size(),' ');
        for(int i=0; i<str.size(); ++i){
            if(str[i]=='(') bra.push(i);
            else if(str[i]==')'){
                if(!bra.empty()) bra.pop();
                else ans[i] = '?';
            }
        }
        while(!bra.empty()){
            ans[bra.top()]='$';
            bra.pop();
        }
        cout<<str<<endl;
        cout<<ans<<endl;
    }
    return 0;
}