#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
    string str = "hello world";
    cout<< str << endl;

    int n=str.size();
    printf("%d\n",n);

    for(int i=0; i<str.size();++i) printf("%c ",str[i]);
    printf("\n");
    for(string::iterator it=str.begin();it !=str.end(); ++it) printf("%c ", *it);
    printf("\n");

    str.insert(str.size(), " end world");
    cout<<str<<endl;
    str.erase(0,12);
    cout<<str<<endl;
    str.insert(0,"how to ");
    cout<<str<<endl;
    str.erase(7);
    cout<<str<<endl;
    str.clear();
    cout<<str<<endl;

    str = "hello world";
    int found = str.find("world");
    if(found != string::npos) printf("world found at : %d\n",found);
    string str2 = str.substr(6,5);
    cout << str2 <<endl;
    return 0;
}