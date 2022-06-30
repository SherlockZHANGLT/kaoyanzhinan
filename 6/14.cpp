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
    BigInteger(int x);
    BigInteger operator=(string str);
    BigInteger operator*(const BigInteger& b);
    friend istream& operator>>(istream& in, BigInteger& x);
    friend ostream& operator<<(ostream& out, BigInteger& x);
};

istream& operator>>(istream& in, BigInteger& x){
    string str;
    in>>str;
    x=str;
    return in;
}

ostream& operator<<(ostream& out, BigInteger& x){
    for(int i=x.length-1; i>=0 ;--i) out<<x.digit[i];
    return out;
}

BigInteger::BigInteger(){
    memset(digit, 0, sizeof(digit));
    length=0;
}

BigInteger::BigInteger(int x){
    memset(digit, 0, sizeof(digit));
    length=0;
    if(x==0) digit[length++]=x;
    while(x!=0){
        digit[length++]=x%10;
        x/=10;
    }
}

BigInteger BigInteger::operator=(string str){
    memset(digit, 0, sizeof(digit));
    length =str.size();
    for(int i=0; i<length; ++i) digit[i]=str[length-i-1]-'0';
    return *this;
}

BigInteger BigInteger::operator*(const BigInteger& b){
    BigInteger ans;
    ans.length=length+b.length;
    for(int i=0; i<length; ++i){
        for(int j=0; j<b.length; ++j) ans.digit[i+j]+=digit[i]*b.digit[j];
    }
    for(int i=0; i<ans.length; ++i){
        ans.digit[i+1]+=ans.digit[i]/10;
        ans.digit[i]%=10;
    }
    while(ans.digit[ans.length-1]==0 && ans.length>1) ans.length--;
    return ans;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        BigInteger ans(1);
        for(int i=1; i<=n; ++i) ans=ans*BigInteger(i);
        cout<<ans<<endl;
    }
    return 0;
}