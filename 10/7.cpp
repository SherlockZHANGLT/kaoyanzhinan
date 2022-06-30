#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map<string, string> student;

int main(){
    int n;
    scanf("%d", &n);
    getchar();
    for(int i=0; i<n; ++i){
        string str;
        getline(cin, str);
        int pos=str.find(" ");
        string key=str.substr(0,pos);
        student[key]=str;
    }
    int m;
    scanf("%d", &m);
    for(int i=0; i<m; ++i){
        string key;
        cin>>key;
        string ans=student[key];
        if(ans=="") ans="No Answer!";
        cout<<ans<<endl;
    }
    return 0;
}