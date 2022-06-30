#include <iostream>
#include <cstdio>
using namespace std;

int daytab[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool IsLeapYear(int year){
    return (year % 4 ==0 && year % 100 != 0) || (year % 400 ==0);
}

int NumberOfYear(int year){
    if(IsLeapYear) return 366;
    else return 365;
}

int main(){
    int year, month, day;
    int number;
    int casenum;
    scanf("%d", &casenum);
    while(casenum--){
        scanf("%d %d %d %d", &year, &month, &day, &number);
        if(IsLeapYear(year)) daytab[2]=29;
        else daytab[2]=28;
        for(int i=0; i<month; i++){
            number+=daytab[i];
        }
        number += day;
        while(number > NumberOfYear(year)){
            number-=NumberOfYear(year);
            year++;
        }
        month = 0;
        if(IsLeapYear(year)) daytab[2]=29;
        else daytab[2]=28;
        while(number > daytab[month]){
            number-=daytab[month];
            month++;
        }
        day = number;
        printf("%04d-%02d-%02d\n",year, month, day);
    }
    return 0;
}