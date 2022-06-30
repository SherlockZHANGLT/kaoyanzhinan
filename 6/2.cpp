#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string Div(string str, int x){
    int remain;
    for(int i=0; i<str.size(); ++i){
        int curr=remain*10+str[i]-'0';
        str[i]=curr/x+'0';
        remain=curr%x;
    }
    int pos=0;
    while(str[pos]=='0') ++pos;
    return str.substr(pos);
}

int main(){
    string str;
    while(getline(cin,str)){
        vector<int> binary;
        while(str.size()!=0){
            int last=str[str.size()-1]-'0';
            binary.push_back(last%2);
            str=Div(str,2);
        }
        reverse(binary.begin(),binary.end());
        for(int i=0; i<binary.size(); ++i) printf("%d",binary[i]);
        cout<<endl;
    }
    return 0;
}