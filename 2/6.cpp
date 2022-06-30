#include<iostream>
#include<cstdio>
using namespace std;

int daytab[13]={0,31,28,31,30,31,30,31,31,30,31,30};

bool IsLeapYear(int year){
    return (year % 4 ==0 && year % 100 !=0) || (year % 400 == 0);
}

int main(){
    int year, month, day;
    int number = 0;
    bool leap;
    while(scanf("%d %d %d", &year, &month, &day) != EOF){
        number = 0;
        leap = IsLeapYear(year);
        for(int i=0; i<month; i++){
            number+= daytab[i];
        }
        number+= day;
        if(leap) number+=1;
        cout<<number<<endl;
    }
    return 0;
}