#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

const int MAXN=10000;

struct BigInteger{
    int digit[MAXN];
    int length;
    BigInteger();
    BigInteger operator=(string str);
    BigInteger operator+(const BigInteger& b);
    friend istream& operator>>(istream& in, BigInteger& x);
    friend ostream& operator<<(ostream& out, BigInteger& x);
};

istream& operator>>(istream& in, BigInteger& x){
    string str;
    in>>str;
    x=str;
    return in;
}

ostream &operator<<(ostream& out, const BigInteger& x){
    for(int i=x.length-1; i>=0; --i) out<<x.digit[i];
    return out;
}

BigInteger::BigInteger(){
    memset(digit, 0, sizeof(digit));
    length=0;
}

BigInteger BigInteger::operator=(string str){
    memset(digit, 0, sizeof(digit));
    length = str.size();
    for(int i=0; i<length; ++i) digit[i]=str[length-i-1]-'0';
    return *this;
}

BigInteger BigInteger::operator+(const BigInteger& b){
    BigInteger ans;
    int carry=0;
    for(int i=0; i<length || i<b.length ;++i){
        int current=carry+digit[i]+b.digit[i];
        carry=current/10;
        ans.digit[ans.length++]=current%10;
    }
    if(carry !=0) ans.digit[ans.length++]=carry;
    return ans;
}

int main(){
    BigInteger a;
    BigInteger b;
    while(cin >>a>>b) cout<<a+b<<endl;
    return 0;
}