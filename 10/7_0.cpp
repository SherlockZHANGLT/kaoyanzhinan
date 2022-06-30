#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map<string ,int> myMap;

int main(){
    myMap["Emma"]=67;
    myMap["Benedict"]=100;
    myMap.insert(pair<string, int>("Bob", 72));
    myMap.insert(pair<string, int>("Mary", 85));
    myMap.insert(pair<string, int>("Alice", 93));
    printf("the size of myMap: %d\n", myMap.size());
    printf("the score of Benedict: %d\n", myMap["Benedict"]);
    printf("the score of Mary: %d\n", myMap.at("Mary"));
    myMap.erase("Benedict");
    map<string, int>::iterator it;
    for(it=myMap.begin(); it!=myMap.end(); it++){
        cout<<"the score of "<<it->first;
        cout<<": "<<it->second<<endl;
    }
    myMap.clear();
    if(myMap.empty()) printf("myMap is empty\n");
    else printf("myMap is not empty\n");
    it=myMap.find("Bob");
    if(it !=myMap.end()) printf("Bob is found\n");
    else printf("Bob is not found\n");
    printf("the size of myMap: %d\n", myMap.size());
    return 0;
}