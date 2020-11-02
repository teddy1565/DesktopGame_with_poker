#include<iostream>
#include<list>
using namespace std;


class Card{
    private:
        int value;
        string kind;
        string inte_to_str(int n){
            if(n==1){
                return "A";
            }else if(n==2){
                return "2";
            }else if(n==3){
                return "3";
            }else if(n==4){
                return "4";
            }else if(n==5){
                return "5";
            }else if(n==6){
                return "6";
            }else if(n==7){
                return "7";
            }else if(n==8){
                return "8";
            }else if(n==9){
                return "9";
            }else if(n==10){
                return "10";
            }else if(n==11){
                return "J";
            }else if(n==12){
                return "Q";
            }else if(n==13){
                return "K";
            }
            return "undefined";
        };
    public:
        Card(){
            this->value=-1;
            this->kind="undefined";
        };
        Card(string k,int n){
            this->value = n;
            this->kind = k;
        };
        string Get_kind(){
            return this->kind;
        };
        int Get_value(){
            return this->value;
        };
        string Get_info(){
            return this->kind+" "+this->inte_to_str(this->value);
        };
};
class user{
    private:
        class handle{
            private:
                list<Card> Cards;
            public:
                handle(){};
                handle(list<Card> Cards){
                    this->Cards = Cards;
                };
                void Add_handle(Card c){
                    this->Cards.push_back(c);
                };
                void Add_handle(list<Card> c){
                    list<Card>::iterator it;
                    for(it=c.begin();it!=c.end();it++){
                        this->Cards.push_back(*it);
                    }
                };
                list<Card> Pull_handle(list<Card> c){
                    list<Card> response;
                    list<Card> UPdate;
                    list<Card>::iterator it;
                    list<Card>::iterator iit;
                    for(iit=c.begin();iit!=c.end();iit++){
                        for(it=this->Cards.begin();it!=this->Cards.end();it++){
                            if(iit->Get_info()==it->Get_info()){
                                response.push_back(*it);
                                continue;
                            }
                            UPdate.push_back(*it);
                        }
                        this->Cards = UPdate;
                    }
                    return response;
                };
                list<Card> Pull_handle(Card c){
                    list<Card>::iterator it;
                    list<Card> update;
                    list<Card> response;
                    for(it=this->Cards.begin();it!=this->Cards.end();it++){
                        if(it->Get_info()==c.Get_info())continue;
                        update.push_back(*it);
                    }
                    this->Cards = update;
                    response.push_back(c);
                    return response;
                };
                list<Card> Pull_handle(string s){
                    list<Card>::iterator it;
                    list<Card> update;
                    list<Card> response;
                    for(it=this->Cards.begin();it!=this->Cards.end();it++){
                        if(it->Get_info()==s){
                            response.push_back(*it);
                            continue;
                        }
                        update.push_back(*it);
                    }
                    this->Cards = update;
                    return response;
                };
                list<Card> Get_handles(){
                    return this->Cards;
                };
                int Get_handle_length(){
                    list<Card>::iterator it;
                    int i=1;
                    for(it=this->Cards.begin();it!=this->Cards.end();it++)i++;
                    return i;
                };
        };
        string name;
        int queue;
        bool computer;
        handle handles;
        int point;
        int dice_value;
    public:
        user(){
            this->computer=false;
            this->dice_value=0;
        };
        user(string n,int que){
            this->name = n;
            this->queue = que;
            this->computer=false;
            this->point=100;
        };
        user(string n,int que,int Dice_V){
            this->name = n;
            this->queue = que;
            this->computer=false;
            this->point=100;
            this->dice_value = Dice_V;
        };
        user(bool com,int que){
            this->name="COM"+to_string(que);
            this->point=100;
        };
        void show_handle(){
            list<Card> handleTmp = this->handles.Get_handles();
            list<Card>::iterator it;
            system("clear");
            cout<<"====== Handles =====";
            for(it=handleTmp.begin();it!=handleTmp.end();it++){
                cout<<it->Get_info()<<endl;
            }
            cout<<"==== End Of Line ====";
        };
        int Get_handle_length(){
            return this->handles.Get_handle_length();
        };
        list<Card> Pull_Handle(list<Card> c){
            return this->handles.Pull_handle(c);
        };
        list<Card> Pull_Handle(Card c){
            return this->handles.Pull_handle(c);
        };
        void show_point(){
            system("clear");
            cout<<"===== Point ====="<<endl;
            cout<<this->point<<endl;
            cout<<"== End Of Line =="<<endl;
        };
        int Get_point(){
            return this->point;
        };
        void Push_Dice_Value(int x){
            this->dice_value = x;
        };
        int Get_Dice_Value(){
            return this->dice_value;
        };
        void Push_queue(int x){
            this->queue = x;
        };
        string Get_name(){
            return this->name;
        };
        int Get_queue(){
            return this->queue;
        };
};
class Desktop{
    private:
        class tools{
            public:
                int DICE(){
                    srand(time(0));
                    return (rand()%6)+1;
                };
                int DICE(int x){
                    srand(time(0));
                    return (rand()%(6*x))+1;
                };
                list<int> DICE(int x,int total_slots){
                    srand(time(0));
                    list<int> response;
                    for(int i=0;i<total_slots;i++){
                        response.push_back((rand()%(6*x))+1);
                    }
                    return response;
                };
        };
        class throw_cards{
            private:
                list<Card> Cards;
                user u;
            public:
                throw_cards(){};
                throw_cards(list<Card> s,user users){
                    this->Cards = s;
                    this->u = users;
                };
                list<Card> Get_Cards(){
                    return this->Cards;
                };
                int Get_total_value(){
                    list<Card>::iterator it;
                    int sum=0;
                    for(it=this->Cards.begin();it!=this->Cards.end();it++){
                        sum+=it->Get_value();
                    }
                    return sum;
                };
        };
        int Get_Deck_length(){
            list<Card>::iterator it;
            int i=0;
            for(it=this->Deck.begin();it!=this->Deck.end();it++,i++);
            return i;
        };
        list<Card> Deck;
        list<throw_cards> trow_area;
    public:
        Desktop(){
            string kind[4]={"Spade","Heart","Diamond","Club"};
            for(int i=0;i<4;i++){
                for(int j=1;j<=13;j++){
                    Card TMP = Card(kind[i],j);
                    this->Deck.push_back(TMP);
                }
            }
            Card TMP = Card("Ghost",0);
            this->Deck.push_back(TMP);
            this->Deck.push_back(TMP);
        };
        Desktop(string option){
            if(option=="Inf"){
                string kind[4]={"Spade","Heart","Diamond","Club"};
                srand(time(0));
                for(int i=0;i<100;i++){
                    Card TMP = Card(kind[rand()%4],(rand()%13)+1);
                    this->Deck.push_back(TMP);
                }
            }else if(option=="Inf&Ghost"){
                srand(time(0));
                string kind[4]={"Spade","Heart","Diamond","Club"};
                for(int i=0;i<100;i++){
                    int v = rand()%14;
                    if(v==0){
                        Card TMP = Card("Ghost",0);
                        this->Deck.push_back(TMP);
                    }else{
                        Card TMP = Card(kind[rand()%4],v);
                        this->Deck.push_back(TMP);
                    }
                }
            }
        };
        void Recevie_Card(user who,list<Card> s){
            throw_cards TMP = throw_cards(s,who);
            this->trow_area.push_back(TMP);
        };
        list<Card> licen(int n){
            srand(time(0));
            list<Card>::iterator it;
            list<Card> response;
            list<Card> update;
            for(int j=0;j<n;j++){
                int target = (rand()%this->Get_Deck_length());
                int i=0;
                for(it=this->Deck.begin();it!=this->Deck.end();it++,i++){
                    if(i==target){
                        response.push_back(*it);
                    }else{
                        update.push_back(*it);
                    }
                }
                this->Deck = update;
            }
            return response;
        };
        tools tool;
};
class Control_Center{
    public:
        Control_Center(){};
};
class Router{
    private:
        Control_Center CONTROL;
        list<user> users;
        int turn;
        int total_slots;
        Desktop desktop;
    public:
        Router(){};
        void Build(){
            bool build=false;
            system("clear");
            cout<<"=========="<<endl;
            cout<<"Please enter total slots: ";
            cin>>this->total_slots;
            int i=0;
            do{
                string name;
                string checkname;
                do{
                    system("clear");
                    cout<<"=========="<<endl;
                    cout<<"Please enter ID : ";
                    cin>>name;
                    system("clear");
                    cout<<"=========="<<endl;
                    cout<<"Your name is "<<name<<endl;
                    cout<<"Do you want this name?[Y/N]"<<endl;
                    cin>>checkname;
                }while(checkname!="Y"&&checkname!="y");
                system("clear");
                cout<<"=========="<<endl;
                do{
                    cout<<"Please enter 'D' to drop dice"<<endl;
                    cin>>checkname;
                }while(checkname!="D"&&checkname!="d");
                int dice_value = this->desktop.tool.DICE((this->total_slots/6)+1);
                system("clear");
                cout<<"=========="<<endl;
                cout<<"Your Point is [ "<<dice_value<<" ]"<<endl;
                cout<<endl;
                do{
                    cout<<"Please enter 'c' to continue..."<<endl;
                    cin>>checkname;
                }while(checkname!="C"&&checkname!="c");
                user TMP = user(name,0,dice_value);
                this->users.push_back(TMP);
                cin>>checkname;
                i++;
            }while(i<total_slots);
            this->Build_sqrt();
        };
        void Build_sqrt(){
            list<user> response;
            list<user>::iterator it;
            int length=0;
            int sqlllt=1;
            for(it=this->users.begin();it!=this->users.end();it++,length++);
            for(int i=0;i<length;i++,sqlllt++){
                list<user> update;
                user TMP;
                for(it=this->users.begin();it!=this->users.end();it++){
                    if(it->Get_Dice_Value()>TMP.Get_Dice_Value()){
                        TMP = *it;
                    }
                }
                for(it=this->users.begin();it!=this->users.end();it++){
                    if(it->Get_Dice_Value()==TMP.Get_Dice_Value()&&it->Get_name()==TMP.Get_name())continue;
                    update.push_back(*it);
                }
                TMP.Push_queue(sqlllt);
                response.push_back(TMP);
                this->users = update;
            }
            this->users = response;
        };
        void Ready(){
            system("clear");
            cout<<"=============================="<<endl;
            list<user>::iterator it;
            cout<<"USER LIST:"<<endl;
            int i=1;
            for(it=this->users.begin();it!=this->users.end();it++,i++){
                cout<<"\t"<<i<<". "<<it->Get_name()<<endl;
            }
            cout<<"======== End Of Line ========"<<endl;
        };
        void Load(string s){
            
        };
};

int main(){
    Router r;
    r.Build();
    r.Ready();
    return 0;
}