#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Student{
    string name;
    int score;
    int order;
};

bool CompareDescend(Student x, Student y){
    if(x.score == y.score) return x.order < y.order;
    else return x.score > y.score;
}

bool CompareAscend(Student x, Student y){
    if(x.score == y.score) return x.order < y.order;
    else return x.score < y.score;
}

int main(){
    int n;
    int type;
    while(scanf("%d%d", &n, &type) !=EOF){
        Student arr[n];
        for(int i=0; i<n; ++i) {
            cin >> arr[i].name >> arr[i].score;
            arr[i].order=i;
        }
        if(type ==0) sort(arr, arr+n, CompareDescend);
        else sort(arr, arr+n, CompareAscend);
        for(int i=0; i<n; ++i) cout << arr[i].name << " " << arr[i].score <<endl;
    }
    return 0;
}