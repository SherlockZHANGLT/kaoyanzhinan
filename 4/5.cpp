#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int number[26];

int main(){
    string str;
    while(getline(cin,str)){
        memset(number, 0, sizeof(number));
        for(int i=0; i<str.size(); ++i){
            if('A'<=str[i] && 'Z'>= str[i]) number[str[i]-'A']++;
        }
        for(int i=0; i<26; ++i) printf("%c:%d\n", 'A'+i, number[i]);
    }
    return 0;
}