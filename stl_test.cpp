#include<iostream>
#include<list>
using namespace std;

list<int> re(){
    list<int> a;
    a.front();
    return a;
}

int main(){
    cout<<*re().begin()<<endl;
    return 0;
}