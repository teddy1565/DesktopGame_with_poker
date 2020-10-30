#include<iostream>
#include<list>
using namespace std;

class Human{
    private:
        class man{
            private:
                string organ;
            public:
                man(){
                    this->organ="bird";
                };
                string whoami(){
                    return this->organ;
                };
        };
        class woman{
            private:
                string organ;
            public:
                woman(){
                    this->organ="pussy";
                };
                string whoami(){
                    return this->organ;
                };
        };
        bool gender;
        woman *WOMAN;
        man *MAN;
    public:
        Human(bool gend){
            this->gender = gend;
            this->WOMAN = new woman();
            this->MAN = new man();
            if(this->gender){
                delete this->WOMAN;
            }else{
                delete this->MAN;
            }
            cout<<"i'm born"<<endl;
        };
        ~Human(){
            cout<<"i'm dead"<<endl;
        };
};
int main(){
    Human baby = Human(true);
    return 0;
}