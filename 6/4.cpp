#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char IntToChar(int x){
    if(x<10) return x+'0';
    else return x-10+'A';
}

int CharToInt(char c){
    if(c>='0' && c<='9') return c-'0';
    else return c-'A'+10;
}

int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    string str;
    cin>>str;
    long long number=0;
    for(int i=0; i<str.size(); ++i){
        number*=m;
        number+=CharToInt(str[i]);
    }
    vector<char> ans;
    while(number!=0){
        ans.push_back(IntToChar(number%n));
        number/=n;
    }
    reverse(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); ++i) printf("%c",ans[i]);
    cout<<endl;
    return 0;
}