#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
    string str;
    while(getline(cin,str)){
        if(str == "ENDOFINPUT") break;
        getline(cin,str);
        for(int i=0; i<str.size();++i){
            if('A'<=str[i] && str[i]<='Z') str[i] = 'A' + (str[i]-'A'-5+26)%26;
        }
        cout<<str<<endl;
        getline(cin,str);
    }
    return 0;
}