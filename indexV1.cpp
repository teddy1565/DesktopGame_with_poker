#include<iostream>
#include<list>
using namespace std;

class Card{
    private:
        int value;
        string disp_value;
        string kind;
        int rank;
    public:
        Card(){
            this->value=0;
            this->kind="undefined";
            this->rank=0;
            this->disp_value="undefined";
        };
        Card(string k,string dv,int v,int r){
            this->value=v;
            this->kind=k;
            this->rank=r;
            this->disp_value=dv;
        };
        int Get_value(){
            return this->value;
        };
        string Get_kind(){
            return this->kind;
        };
        int Get_rank(){
            return this->rank;
        };
        string Get_display_value(){
            return this->disp_value;
        };
        list<string> Get_info(){
            list<string> response;
            response.push_back(this->kind);
            response.push_back(this->disp_value);
            return response;
        };
        string Get_dis_kind_and_value(){
            return (this->kind)+to_string(this->value);
        };
};
class Desktop{
    private:
        class Deck{
            private:
                list<Card> Cards;
            public:
                Deck(){
                    string kind[4]={"Spade","Heart","Club","Dianmond"};
                    string DV[13]={"A","2","3","4","5","6","7","8","9","10","11","12","13"};
                    for(int i=0;i<13;i++){
                        for(int j=0;j<4;j++){
                            Card tmp(kind[j],DV[i],i+1,(i+1)*(j+1));
                            Cards.push_back(tmp);
                        }
                    }
                    Card ghost("Ghost","Ghost",0,0);
                    Cards.push_back(ghost);
                    Cards.push_back(ghost);
                };
                list<Card> remove_this(list<Card> s,Card source){
                    list<Card> m;
                    list<Card>::iterator it;
                    for(it=s.begin();it!=s.end();it++){
                        if(it->Get_info()==source.Get_info())break;
                        m.push_back(*it);
                    }
                    for(;it!=s.end();it++){
                        m.push_back(*it);
                    }
                    return m;
                };
                int Get_Deck_leng(){
                    list<Card>::iterator it;
                    int k=0;
                    for(it=this->Cards.begin();it!=this->Cards.end();it++,k++);
                    return k;
                };
                Card Draw(){
                    srand(time(0));
                    int target = rand()%(this->Get_Deck_leng());
                    list<Card>::iterator it;
                    Card tmp;
                    int r=0;
                    for(it=this->Cards.begin();it!=this->Cards.end();it++,r++){
                        if(r==target){
                            break;
                        }
                    }
                    tmp = *it;
                    this->Cards = this->remove_this(this->Cards,*it);
                    return tmp;
                };
                list<Card> Draw(int x){
                    srand(time(0));
                    list<Card>::iterator it;
                    list<Card> res;
                    Card tmp;
                    for(int a=0;a<x;a++){
                        int target = rand()%(this->Get_Deck_leng());
                        int r=0;
                        for(it=this->Cards.begin();it!=this->Cards.end();it++,r++){
                            if(r==target)break;
                        }
                        tmp = *it;
                        this->Cards = this->remove_this(this->Cards,*it);
                        res.push_back(tmp);
                    }
                    return res;  
                };
        };
        class DICE{
            public:
                int drop(){
                    srand(time(0));
                    return (rand()%6)+1;
                };
                int drop(int x){
                    srand(time(0));
                    return (rand()%(6*x))+1;
                };
        };
        class display_desktop{
            private:
                list<Card> user_drop;
                string view_engine;
            public:
                display_desktop(int total_slove){
                    list<Card>::iterator it;
                    this->view_engine="";
                    int i=1;
                    for(it=this->user_drop.begin();it!=this->user_drop.end();it++,i++){
                        this->view_engine+=(it->Get_dis_kind_and_value()+" ");
                        if(i==5){
                            this->view_engine+="\n";
                            i=1;
                        }
                    }
                };
                void show(){
                    cout<<"=============="<<endl;
                    cout<<this->view_engine<<endl;
                    cout<<"=============="<<endl;
                };
        };
        
    public:
        Desktop(){

        };
        Deck center_deck;
        DICE dice;
};
class user{
    private:
        class handle{
            private:
                list<Card> Cards;
            public:
                list<Card> remove_this(list<Card> s,Card source){
                    list<Card> m;
                    list<Card>::iterator it;
                    for(it=s.begin();it!=s.end();it++){
                        if(it->Get_info()==source.Get_info())break;
                        m.push_back(*it);
                    }
                    for(;it!=s.end();it++){
                        m.push_back(*it);
                    }
                    return m;
                };
                handle(){

                };
                handle(Card x){
                    this->Cards.push_back(x);
                };
                handle(list<Card> x){
                    this->Cards=x;
                };
                void push_card(Card x){
                    this->Cards.push_back(x);
                };
                void push_card(list<Card> x){
                    list<Card>::iterator it;
                    for(it=x.begin();it!=x.end();it++){
                        this->Cards.push_back(*it);
                    }
                };
                bool drop_this(Card x){
                    list<Card>::iterator it;
                    for(it=this->Cards.begin();it!=this->Cards.end();it++){
                        if(it->Get_info()==x.Get_info()){
                            this->Cards=this->remove_this(this->Cards,*it);
                            return true;
                        }
                    }
                    return false;
                };
                void drop_this(list<Card> x){
                    list<Card>::iterator it;
                    list<Card>::iterator x_it;
                    for(x_it=x.begin();x_it!=x.end();x_it++){
                        for(it=this->Cards.begin();it!=this->Cards.end();it++){
                            if(it->Get_info()==x_it->Get_info()){
                                this->Cards=this->remove_this(this->Cards,*it);
                                break;
                            }
                        }
                    }
                };
                list<Card> Get_handle(){
                    return this->Cards;
                };
        };
        int queue_rank;
        handle handles;
        string name;
        bool computer;
    public:
        user(){
            this->name="undefined";
            this->queue_rank=-1;
        };
        user(string n,int QR){
            this->name=n;
            this->queue_rank=QR;
            this->computer=false;
        };
        user(bool com){
            this->computer=com;
        };
        user(string n){
            this->name = n;
            this->computer=false;
        };
        void push_handle(Card x){
            this->handles.push_card(x);
        };
        void push_handle(list<Card> x){
            this->handles.push_card(x);
        };
        void drop_this(Card x){
            this->handles.drop_this(x);
        };
        void drop_this(list<Card> x){
            this->handles.drop_this(x);
        };
        void drop_this(string s){
            //split string
            
        };
        void watch_handle(){
            list<Card> tmp = this->handles.Get_handle();
            list<Card>::iterator it;
            for(it=tmp.begin();it!=tmp.end();it++){
                cout<<it->Get_kind()<<" "<<it->Get_value()<<endl;
            }
            cout<<"== End of line =="<<endl;
        };
        string speak(){
            string mes;
            getline(cin,mes);
            return mes;
        };
        int Get_queue(){
            return this->queue_rank;
        }
        string Get_name(){
            return this->name;
        };
        void update_queue(int x){
            this->queue_rank = x;
        };
        int Get_handle_num(){
            list<Card> s = this->handles.Get_handle();
            list<Card>::iterator it;
            int j=0;
            for(it=s.begin();it!=s.end();it++,j++);
            return j;
        };
        list<Card> Get_handle(){
            return this->handles.Get_handle();
        };
};
class Router{
    private:
        Desktop desk;
        class Game{
            private:
                string Game_mode;
            public:
                Game(){

                };
                Game(string s){
                    this->Game_mode = s;
                };
        };
        int total_slots;
        list<user> users;
        list<user> __user_config_(){
            string name;
            bool rebuild = false;
            list<user> tmpConfig;
            int point = 0;
            do{
                tmpConfig.clear();
                cout<<"[Router] > Please enter total slots!"<<endl;
                cin>>this->total_slots;
                for(int i=0;i<total_slots;i++){
                    bool rename = true;
                    string ren;
                    string trash;
                    do{
                        cout<<"[Router] > Please enter you name(ID)"<<endl;;
                        getline(cin,name);
                        getline(cin,name);
                        cout<<"[Router] > Do you want this name?[Y/N]: ";
                        cin>>ren;
                        if(ren=="Y"||ren=="y"){
                            rename = true;
                            system("clear");
                        }
                        else if(ren=="N"||ren=="n")rename = false;
                    }while(rename==false);
                    bool de = false;
                    do{
                        cout<<"[Router] > Hi "<<name<<endl;
                        cout<<"[Router] > Enter 'D' to drop dice."<<endl;
                        cin>>ren;
                        if(ren=="D"||ren=="d"){
                            point = desk.dice.drop(((this->total_slots/6)+1));
                            de=true;
                            bool sacas= false;
                            do{
                                cout<<"[Router] > Your point is: "<<point<<endl;
                                string tm;
                                cout<<"[Router] > Press 'C' to create next user"<<endl;
                                cin>>tm;
                                if(tm=="C"||tm=="c")sacas=true;
                                else system("clear");
                            }while(sacas==false);
                            system("clear");
                        }else system("clear");
                    }while(de==false);
                    user tmpusers = user(name,point);
                    tmpConfig.push_back(tmpusers);
                }
                string asscea;
                cout<<"Router > Do you want rebuild players config?[Y/N]: ";
                if(asscea=="Y"||asscea=="y")rebuild=true;
            }while(rebuild==true);
            list<user> response;
            list<user>::iterator user_it;
            list<user>::iterator match_it;
            list<user> match_tmp;
            list<user> tmpref = tmpConfig;
            for(int i=0;i<this->total_slots;i++){
                match_tmp.clear();
                int ranking=this->total_slots;
                user Max = tmpref.front();
                for(user_it=tmpref.begin();user_it!=tmpref.end();user_it++){
                    if(user_it->Get_queue()>Max.Get_queue()){
                        Max = *user_it;
                    }else{
                        if(user_it->Get_name()!=Max.Get_name()){
                            match_tmp.push_back(*user_it);
                        }else continue;
                    }
                }
                Max.update_queue(i+1);
                response.push_back(Max);
                tmpref = this->remove_this(tmpref,Max);
            }
            return response;
        };
        list<user> remove_this(list<user> users,user target){
            list<user>::iterator it;
            list<user> res;
            for(it=users.begin();it!=users.end();it++){
                if(it->Get_name()!=target.Get_name()){
                    res.push_back(*it);
                }
            }
            return res;
        };
    public:
        Router(){
            
        };
        Router(string s){
            if(s=="start"){
                system("clear");
                cout<<"**SYSTEM**"<<endl;
                cout<<"Control Center --> On line"<<endl;
                cout<<">>Router --> Building\n"<<endl;
                cout<<"==Player config building=="<<endl;
                this->users = this->__user_config_();
            }
        }
        void user_move(user thisuser){
            string op;
            bool esclicp=false;
            do{
                cout<<"next move?"<<endl;
                cin>>op;
                if(op=="n"){
                    esclicp=true;
                }else if(op=="message"){
                    thisuser.speak();
                }else if(op=="drop"){
                    string select_card;
                    getline(cin,select_card);
                    thisuser.drop_this(select_card);
                }
                system("clear");// maybe different on windows
            }while(esclicp==true);
        };
        void player_list(){
            list<user>::iterator it;
            int i=1;
            cout<<"=======Player List======="<<endl;
            for(it=this->users.begin();it!=this->users.end();it++,i++){
                cout<<i<<"."<<it->Get_name()<<endl;
            }
            cout<<"=======End Of Line======="<<endl;
        };
        list<user> Get_player(){
            return this->users;
        };
        void licen(int initial_num){
            list<user>::iterator r_it;
            for(r_it=this->users.begin();r_it!=this->users.end();r_it++){
                r_it->push_handle(this->desk.center_deck.Draw(initial_num));
            }           
        };
        void start(){

        };
        void start(string Game_mode){
            Game game_process = Game(Game_mode);

        };
};
class Control_Center{
    private:
        Router route;
    public:
        Control_Center(){
            this->route = Router("start");
            cout<<"** SYSTEM **"<<endl;
            cout<<"Control Center --> On line"<<endl;
            cout<<"Router --> On line"<<endl;
            cout<<"User config --> Done"<<endl;
            cout<<"Game config --> Done"<<endl;
            cout<<"==============================="<<endl;
            cout<<"[Control_Center] > Have fun!"<<endl;
            cout<<"==============================="<<endl;
        };
        ~Control_Center(){
            cout<<"===Game Over==="<<endl;
            cout<<"** SYSTEM **"<<endl;
            cout<<"[SYSTEM] All station now disabled"<<endl;
        };
        void player_list(){
            this->route.player_list();
        };
        void player_state(){
            list<user> s;
            list<user>::iterator it;
            s = this->route.Get_player();
            for(it=s.begin();it!=s.end();it++){
                cout<<it->Get_name()<<endl;
                cout<<"\tqueue:"<<it->Get_queue()<<endl;
                cout<<"\thandle_cards:"<<it->Get_handle_num()<<endl;
            }
        };
        void player_state(string user_name){
            list<user> s;
            list<user>::iterator it;
            s = this->route.Get_player();
            bool find=false;
            for(it=s.begin();it!=s.end();it++){
                if(it->Get_name()==user_name){
                    find=true;
                    break;
                }
            }
            if(find){
                cout<<it->Get_name()<<":"<<endl;
                cout<<"\t"<<"handle_cards:"<<it->Get_handle_num()<<endl;
            }else{
                cout<<"Can't not find this player"<<endl;
            }
        };
        void initiation(int Game_mode){
            if(Game_mode==1){
                route.licen(2);
                route.start("Black Jack");
            }
        };
};
void Game_start(){
    Control_Center center = Control_Center();
    center.player_list();
    center.initiation(1);
}
int main(){
    Game_start();
    return 0;
}