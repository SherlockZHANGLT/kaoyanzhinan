#include <iostream>
#include <cstdio>
using namespace std;

int daytab[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool IsLeapYear(int year){
    return (year % 4 ==0 && year % 100 != 0) || (year % 400 == 0);
}

int main(){
    int year, month, day;
    int number;
    while(scanf("%d %d", &year, &number) != EOF){
        if(IsLeapYear(year)) daytab[2]=29;
        else daytab[2]=28;
        month = 0;
        while(number > daytab[month]){
            number-=daytab[month];
            month++;
        }
        day = number;
        printf("%04d-%02d-%02d", year, month, day);

    }
    return 0;
}