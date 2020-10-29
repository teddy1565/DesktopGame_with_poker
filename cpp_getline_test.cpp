#include<iostream>
#include<list>
using namespace std;
string speak(){
    string mes;
    getline(cin,mes);
    return mes;
};
int main(){
    cout<<speak()<<endl;
    return 0;
}