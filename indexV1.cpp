#include<iostream>
#include<list>
#include<cstdarg>
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
            return (this->kind)+"\t"+to_string(this->value);
        };
};
class Desktop{
    private:
        class Deck{
            private:
                list<Card> Cards;
                class player_drop{
                    private:
                        list<Card> Cards;
                        string name;
                        int turn;
                    public:
                        player_drop(){
                            
                        };
                        player_drop(list<Card> handle,string user_name,int what_time){
                            this->Cards = handle;
                            this->name = user_name;
                            this->turn = what_time;
                        };
                        list<Card> Get_Drop_what(){
                            return this->Cards;
                        };
                        int Get_Drop_Time(){
                            return this->turn;
                        };
                        string Get_Drop_user(){
                            return this->name;
                        };
                };
                
                list<player_drop> LOG;
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
                    it++;
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
                    if(this->Run_out()){
                        Card un = Card("Run_out","Run_out",-1,-1);
                        return un;
                    }
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
                    if(this->Run_out()){
                        Card un = Card("Run_out","Run_out",-1,-1);
                        list<Card> r;
                        r.push_back(un);
                        return r;
                    }
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
                list<Card> Get_Center_Deck(){
                    return this->Cards;
                };
                bool Run_out(){
                    if(this->Get_Deck_leng()>0)return false;
                    return true;
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
                list<Card> drop_this(Card x){
                    list<Card>::iterator it;
                    list<Card> response;
                    for(it=this->Cards.begin();it!=this->Cards.end();it++){
                        if(it->Get_info()==x.Get_info()){
                            response.push_back(*it);
                            this->Cards=this->remove_this(this->Cards,*it);
                            return response;
                        }
                    }
                    Card c = Card();
                    response.push_back(c);
                    return response;
                };
                list<Card> drop_this(list<Card> x){
                    list<Card>::iterator it;
                    list<Card>::iterator x_it;
                    list<Card> response;
                    bool find=false;
                    for(x_it=x.begin();x_it!=x.end();x_it++){
                        for(it=this->Cards.begin();it!=this->Cards.end();it++){
                            if(it->Get_info()==x_it->Get_info()){
                                response.push_back(*it);
                                this->Cards=this->remove_this(this->Cards,*it);
                                find = true;
                                break;
                            }
                        }
                    }
                    if(find==false){
                        Card scscscs;
                        response.push_back(scscscs);
                    }
                    return response;
                };
                Card Handle_drop(string s){
                    list<Card>::iterator it;
                    Card tmp;
                    for(it=this->Cards.begin();it!=this->Cards.end();it++){
                        if(it->Get_dis_kind_and_value()==s){
                            tmp = *it;
                            this->Cards = this->remove_this(this->Cards,tmp);
                            break;
                        }
                    }
                    return tmp;
                };
                Card Handle_drop(int n){
                    list<Card>::iterator it;
                    Card tmp;
                    for(it=this->Cards.begin();it!=this->Cards.end();it++){
                        if(it->Get_rank()==n){
                            tmp = *it;
                            this->Cards = this->remove_this(this->Cards,tmp);
                            break;
                        }
                    }
                    return tmp;
                };
                list<Card> Handles_drop(list<string> s){
                    list<string>::iterator it;
                    list<Card>::iterator iit;
                    list<Card>response;
                    for(it=s.begin();it!=s.end();it++){
                        for(iit = this->Cards.begin();iit!=this->Cards.end();iit++){
                            if(*it==iit->Get_dis_kind_and_value()){
                                response.push_back(*iit);
                                this->Cards = this->remove_this(this->Cards,*iit);
                                break;
                            }
                        }
                    }
                    return response;
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
        void watch_handle(){
            list<Card> tmp = this->handles.Get_handle();
            list<Card>::iterator it;
            cout<<"== "<<this->name<<" handle =="<<endl;
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
class Rule{
    private:
        class winner{
            private:
                list<int> purpose;
                list<user> finish_order;
            public:
                winner(){};
                winner(int size, ...){
                    va_list args;
                    va_start(args,size);
                    for(int i=0;i<size;i++){
                        this->purpose.push_back(va_arg(args,int));
                    }
                    va_end(args);
                };
                void when_user_finish(user users){
                    this->finish_order.push_back(users);
                };
                bool Is_that_win(int total_Value){
                    list<int>::iterator it;
                    for(it=this->purpose.begin();it!=this->purpose.end();it++){
                        if(total_Value==*it)return true;
                    }
                    return false;
                };
                bool Is_that_win(list<Card> handles){
                    list<Card>::iterator it;
                    list<int>::iterator iit;
                    int sum=0;
                    for(it=handles.begin();it!=handles.end();it++){
                        sum+=it->Get_value();
                    }
                    for(iit=this->purpose.begin();iit!=this->purpose.end();it++){
                        if(sum==*iit)return true;
                    }
                    return false;
                };
        };
        class loser{
            private:
                list<int> purpose;
                list<user> lose_order;
            public:
                loser(){
                    
                };
                loser(int size, ...){
                    va_list args;
                    va_start(args,size);
                    for(int i=0;i<size;i++){
                        this->purpose.push_back(va_arg(args,int));
                    }
                    va_end(args);
                };
                void when_user_lost(user users){
                    this->lose_order.push_back(users);
                };
                bool Is_that_lost(int total_value){
                    list<int>::iterator it;
                    for(it=this->purpose.begin();it!=this->purpose.end();it++){
                        if(*it == total_value)return true;
                    }
                    return false;
                };
                bool Is_that_lost(list<Card> handle_drop){
                    int total_value = 0;
                    list<Card>::iterator it;
                    list<int>::iterator iit;
                    for(it=handle_drop.begin();it!=handle_drop.end();it++){
                        total_value += it->Get_value();
                    }
                    for(iit=this->purpose.begin();iit!=this->purpose.end();iit++){
                        if(total_value==*iit)return true;
                    }
                    return false;
                };
        };
        winner WIN;
        loser LOSE;
    public:
        Rule(){
        };
        Rule(string s){
            if(s=="Black Jack"){
                this->WIN = winner(1,21);
                this->LOSE = loser(1,22,23,24,25,26,27,28,29,30);
            }
        };
        void Process_step_state(user u,list<Card> handle_drop){
            if(this->LOSE.Is_that_lost(handle_drop)){
                this->LOSE.when_user_lost(u);
            }else if(this->WIN.Is_that_win(handle_drop)){
                this->WIN.when_user_finish(u);
            }
            //dynamic splices;
        };
};
class Router{
    private:
        Rule rule;
        Desktop desk;
        int turn;
        class Game{
            private:
                string Game_mode;
                Rule Game_Rule;
                int turn;
                bool finish;
            public:
                Game(){

                };
                Game(string s){
                    this->Game_mode = s;
                    this->turn=1;
                    this->finish=false;
                    cout<<"[Router] > Now playing ["<<this->Game_mode<<"]"<<endl;
                };
                void load(){
                    if(this->Game_mode=="Black Jack"){
                        this->Game_Rule = Rule(this->Game_mode);
                    }
                };
                int Get_turn(){
                    return this->turn;
                };
                void Update_turn(int x){
                    this->turn = x;
                };
                void move(user u){
                    
                };
                Rule Get_Rule(){
                    return this->Game_Rule;
                };
                void Update(Rule R){
                    this->Game_Rule = R;
                };
                bool Get_finish(){
                    return this->finish;
                };
        };
        class Display{
            private:
                class Show{
                    private:
                        list<user> users;
                        int turn;
                        int total_slots;
                    public:
                        Show(){

                        };
                        Show(list<user> u,int tn,int ts){
                            this->turn = tn;
                            this->users = u;
                            this->total_slots = ts;
                        };
                        void Personal_Handle(user u){//func(user u)
                            list<Card> H;
                            list<Card>::iterator it;
                            cout<<"Round: "<<this->turn<<endl;
                            cout<<"== "<<u.Get_name()<<" Handle =="<<endl;
                            H = u.Get_handle();
                            for(it=H.begin();it!=H.end();it++){
                                cout<<"\t"<<it->Get_dis_kind_and_value()<<endl;
                            }
                            cout<<"=== End Of Line ==="<<endl;
                        };
                        void All_Player_Handle(list<user> u){//func(list<user> x)
                            list<user>::iterator it;
                            for(it=u.begin();it!=u.end();it++){
                                this->Personal_Handle(*it);
                            }
                        };
                        void Desktop(list<Card> deck_drop){
                            system("clear");
                            cout<<"Round: "<<this->turn<<endl;
                            list<Card>::iterator it;
                            cout<<"===== Desktop Display ====="<<endl;
                            int i=0;
                            for(it=deck_drop.begin();it!=deck_drop.end();it++,i++){
                                cout<<it->Get_dis_kind_and_value()<<"\t";
                                if(i%3==0){
                                    cout<<endl;
                                    i=0;
                                }
                            }
                            cout<<"======= End Of Line ======="<<endl;
                        };
                        void PLAYER_LIST_SERVIVE(list<user> u){
                            list<user>::iterator it;
                            cout<<"Servive: ";
                            int i=0;
                            for(it=u.begin();it!=u.end();it++,i++){
                                cout<<it->Get_name()<<"\t";
                                if(i%3==0){
                                    cout<<endl;
                                    i=0;
                                }
                            }
                            cout<<endl;
                            cout<<"===== End Of Line ====="<<endl;
                        };
                };
                Show SHOW;
            public:
                Display(){
                    
                };
                void Personal_handle(user u){
                    this->SHOW.Personal_Handle(u);
                };
                void ALL_PLAYER_Handle(list<user> u){
                    this->SHOW.All_Player_Handle(u);
                };
                void PLAYER_LIST_SERVIVE(list<user> u){
                    
                };
                void Desktop(list<Card> deck){
                    this->Desktop(deck);
                };
                void Main_Viewr(list<user> users,user u,int turn){
                    cout<<"Round: "<<turn<<endl;
                    this->PLAYER_LIST_SERVIVE(users);
                };
        };
        int total_slots;
        bool Game_Finish;
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
                this->Game_Finish = false;
                this->turn=-1;
                system("clear");
                cout<<"**SYSTEM**"<<endl;
                cout<<"Control Center --> On line"<<endl;
                cout<<">>Router --> Building\n"<<endl;
                cout<<"==Player config building=="<<endl;
                this->users = this->__user_config_();
            }
        }
        void user_move(user thisuser){
            //something to do
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
        void licen(int initial_num){//only when initiation Game use
            list<user>::iterator r_it;
            for(r_it=this->users.begin();r_it!=this->users.end();r_it++){
                r_it->push_handle(this->desk.center_deck.Draw(initial_num));
            }
        };
        void licen(user u,int n){
            u.push_handle(this->desk.center_deck.Draw(n));
        };
        void licen(user u){
            u.push_handle(this->desk.center_deck.Draw(1));
        };
        void show_players_handles(){
            list<user>::iterator it;
            list<Card> ahandlers;
            list<Card>::iterator iit;
            cout<<"==Player Handles=="<<endl;
            for(it=this->users.begin();it!=this->users.end();it++){
                ahandlers = it->Get_handle();
                cout<<it->Get_name()<<": "<<endl;
                for(iit=ahandlers.begin();iit!=ahandlers.end();iit++){
                    cout<<"\t"<<iit->Get_dis_kind_and_value()<<endl;
                }
            }
            cout<<"==End Of Line=="<<endl;
        };
        void show_center_deck(){
            list<Card> arr;
            list<Card>::iterator it;
            arr = this->desk.center_deck.Get_Center_Deck();
            cout<<"==Center Deck=="<<endl;
            for(it=arr.begin();it!=arr.end();it++){
                cout<<it->Get_dis_kind_and_value()<<endl;
            }
            cout<<"==End Of Line=="<<endl;
        };
        void start(string Game_mode){ 
            Game game_process = Game(Game_mode);
            game_process.load();
            this->rule=game_process.Get_Rule();
            this->turn=game_process.Get_turn();
            list<user>::iterator user_it;
            while(this->Game_Finish==false){
                if(turn>100)break;
                for(user_it=this->users.begin();user_it!=this->users.end();user_it++){

                }
                this->turn++;
            }
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