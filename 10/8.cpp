#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

map<string, string> dictionary;

int main(){
    string str;
    while(getline(cin, str)){
        if(str=="@END@") break;
        int pos=str.find("]");
        string key=str.substr(0, pos+1);
        string value=str.substr(pos+2);
        dictionary[key]=value;
        dictionary[value]=key;
    }
    int n;
    scanf("%d", &n);
    getchar();
    while(n--){
        string key;
        getline(cin, key);
        string ans=dictionary[key];
        if(ans=="") ans="what?";
        else if(ans[0]=='[') ans=ans.substr(1, ans.size()-2);
        cout<<ans<<endl;
    }
    return 0;
}