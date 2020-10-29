#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> a;
    a.push_back(10);
    a.push_back(55);
    a.push_back(1033);
    a.push_back(2);
    list<int>::iterator it;
    for(it=a.begin();it!=a.end();it++){
        cout<<*it<<endl;
    }
    a.remove_if(*it);
    for(it=a.begin();it!=a.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}