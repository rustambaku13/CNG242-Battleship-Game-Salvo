//
// Created by Rustam Quliyev on 14/05/18.
//

#ifndef ASS4_SHIPS_H
#define ASS4_SHIPS_H
#include <vector>
#include <cmath>
#include <tuple>
#define  A 1
#define  B 5
#define  S 9
#define  P 14
using namespace std;
enum condition  {sunk,operative};
enum ShipType{aircraft,battleship,submarine,patrol};

class Ships {
protected :
    int size;
    int number_of_hits_to_sink;
    int shooting_cap;
    int times_shot;
    enum condition status;
public:
    enum condition staty(){return status;};
    int capy(){return shooting_cap;}
    int sizey(){
        return size;
    }
    enum ShipType type;
    Ships(){
        status = operative;
        times_shot=0;
    }

    void Shoot(char ***p){



        int i;
        tuple <char,int> point;
        for(i=0;i<shooting_cap;i++){

            cout <<"Where do you want to shoot"<<endl;
            cin >> get<0>(point)>>get<1>(point);
            if((*p)[get<0>(point)-97][get<1>(point)]=='0'){
                cout <<"This point was shot before shoot again";
                i--;
            }
            else (*p)[get<0>(point)-97][get<1>(point)] = '0';
        }
    };
    void TakeHit(){
        times_shot++;
    }
    void update_status(){
        if(status == sunk)return;
        if(times_shot >=number_of_hits_to_sink) {
            if(status==sunk)return;
            status = sunk;
            switch (type) {
                case aircraft:
                    cout << "One Aircraft is DOWN!" << endl;
                    break;
                case battleship:
                    cout << "AHHH Battleship is down!" << endl;
                    break;
                case submarine:
                    cout << "You have Lost your Submarine!" << endl;
                    break;
                case patrol:
                    cout << "One Patrol Boat Less!" << endl;
                    break;
            }
        }

    }
};

class AircraftCarrier:public Ships {
public:
    AircraftCarrier(){
        size = 5;
        number_of_hits_to_sink = 4;
        shooting_cap=3;
        type=aircraft;
    }

};
class Battleship:public Ships {
public:
    Battleship(){
        size =4;
        number_of_hits_to_sink = 3;
        shooting_cap=5;
        type=battleship;
    }


};
class Submarine:public Ships {
public:
    Submarine(){
        size =3;
        number_of_hits_to_sink = 2;
        shooting_cap=2;
        type=submarine;
    }


};
class PatrolBoat:public Ships {
    public:
    PatrolBoat(){
        size =1;
        number_of_hits_to_sink = 1;
        shooting_cap=1;
        type=patrol;
    }


};

class Player {
private:
    char name[50];
    vector<Ships> myships;
    int **grid;
    char ** shooting_grid;
    int size;
public :
    Player(int type) {
        char tmp[20];
        cout << "Enter your name:";
        cin >> name;

        if (type==0) {
            size = 5;
            grid = new int *[5];
            shooting_grid = new char *[5];
            int i,j;
            for (i = 0; i < 5; i++) {
                shooting_grid[i] = new char[8];
                grid[i] = new int[8];
                for(j=0;j<8;j++){
                    grid[i][j]=0;
                    shooting_grid[i][j]='.';
                }
            }
            myships.push_back(AircraftCarrier());
            myships.push_back(Battleship());
            myships.push_back(Submarine());
            myships.push_back(PatrolBoat());
            myships.push_back(PatrolBoat());

        }
        else if (type==1) {
            size = 8;
            grid = new int *[8];
            shooting_grid = new char *[8];
            int i,j;
            for (i = 0; i < 8; i++) {
                grid[i] = new int[10];
                shooting_grid[i] = new char[10];
                for(j=0;j<10;j++){
                    grid[i][j]=0;
                    shooting_grid[i][j] = '.';
                }
            }

            myships.push_back(AircraftCarrier());
            myships.push_back(AircraftCarrier());
            myships.push_back(Battleship());
            myships.push_back(Battleship());
            myships.push_back(Submarine());
            myships.push_back(Submarine());
            myships.push_back(PatrolBoat());
            myships.push_back(PatrolBoat());
            myships.push_back(PatrolBoat());
            myships.push_back(PatrolBoat());

        } else {
            size = 10;
            grid = new int *[10];
            shooting_grid = new char *[10];
            int i,j;
            for (i = 0; i < 10; i++) {
                shooting_grid[i] = new char[12];
                grid[i] = new int[12];
                for(j=0;j<12;j++){
                    grid[i][j]=0;
                    shooting_grid[i][j]='.';
                }
            }
            myships.push_back(AircraftCarrier());
            myships.push_back(AircraftCarrier());
            myships.push_back(AircraftCarrier());
            myships.push_back(AircraftCarrier());
            myships.push_back(Battleship());
            myships.push_back(Battleship());
            myships.push_back(Battleship());
            myships.push_back(Submarine());
            myships.push_back(Submarine());
            myships.push_back(PatrolBoat());
            myships.push_back(PatrolBoat());
            myships.push_back(PatrolBoat());
            myships.push_back(PatrolBoat());

        }
    }

    ~Player() {
        int i;
        for (i = 0; i < size; i++) {
            delete[] grid[i];
        }

    }

    void DeployShips(){

        cout <<name << " Please Deploy your Ships"<<endl<<endl<<endl;
        int i=0;
        int a=A;
        int b=B;
        int s =S;
        int p=P;
        tuple <char,int> p1,p2;
        while((myships.begin()+i)!=myships.end()){

            int sqrty;
            if((myships.begin()+i)->type==aircraft){


                   cout<<"Enter the coordinates of the Aircraft Carrier"<<endl;
                   cin >> get<0>(p1);
                   cin >> get<1>(p1);
                   cin >> get<0>(p2);
                   cin >> get<1>(p2);

                if(get<0>(p1)==get<0>(p2)){
                    while(abs(get<1>(p1)-get<1>(p2))!=(myships.begin()+i)->sizey()-1){
                        cout <<"Wrong coordinates Enter again"<<endl;
                        cout<<"Enter the coordinates of the Aircraft Carrier"<<endl;
                        cin >> get<0>(p1);
                        cin >> get<1>(p1);
                        cin >> get<0>(p2);
                        cin >> get<1>(p2);
                    }
                    int k = get<1>(p1);
                    int start = k;
                    int j = get<1>(p2);
                    int inc = (j-k)/((myships.begin()+i)->sizey()-1);
                    for(k;k!=j+inc;k=k+inc){
                        if(grid[get<0>(p1)-97][k]!=0){
                            BacktrackY(get<0>(p1),start,k-inc,inc);
                            i--;
                            a--;
                            break;
                        }
                        grid[get<0>(p1)-97][k]=a;


                    }
                }

                else if(get<1>(p1)==get<1>(p2)) {
                    while(abs(get<0>(p1)-get<0>(p2))!=(myships.begin()+i)->sizey()-1){
                        cout <<"Wrong coordinates Enter again"<<endl;
                        cout<<"Enter the coordinates of the Aircraft Carrier"<<endl;
                        cin >> get<0>(p1);
                        cin >> get<1>(p1);
                        cin >> get<0>(p2);
                        cin >> get<1>(p2);
                    }
                    int k = get<0>(p1) - 97;
                    int j = get<0>(p2) - 97;
                    int start = k;
                    int inc = (j - k) / ((myships.begin() + i)->sizey()-1);
                    for (k; k != j+inc; k = k + inc) {
                        if(grid[k][get<1>(p1)]!=0){
                            BacktrackX(get<1>(p1),start,k-inc,inc);
                            i--;
                            a--;
                            break;
                        }
                        grid[k][get<1>(p1)] = a;

                    }
                }
                else {

                        while(abs(get<0>(p1)- get<0>(p2))!=((myships.begin() + i)->sizey() -1)||abs(get<1>(p1)- get<1>(p2))!=((myships.begin() + i)->sizey()-1) ){
                            cout <<"Wrong coordinates Enter again"<<endl;
                            cout<<"Enter the coordinates of the Aircraft Carrier"<<endl;
                            cin >> get<0>(p1);
                            cin >> get<1>(p1);
                            cin >> get<0>(p2);
                            cin >> get<1>(p2);
                            sqrty = sqrt( pow(abs(get<0>(p1)-get<0>(p2)),2) +  pow(abs(get<1>(p1)-get<1>(p2)),2));

                        }
                        float slope = (get<1>(p1)-get<1>(p2))/(get<0>(p2)-get<0>(p1));
                        if(slope>0) {
                            if ((get<0>(p2) - get<0>(p1)) > 0) {
                                tuple<char, int> t = p1;
                                for (t; (get<0>(t)!= get<0>(p2)+1)&&(get<1>(t)!=get<1>(p2)-1); (get<0>(t))++, (get<1>(t))--) {
                                    if(grid[get<0>(t) - 97][get<1>(t)]!=0){
                                        get<0>(t)--;
                                        get<1>(t)++;
                                        backtrackDiagonal(p1,t,+1,-1);
                                        i--;
                                        a--;
                                        break;
                                    }
                                    grid[get<0>(t) - 97][get<1>(t)] = a;
                                }

                            } else {
                                tuple<char, int> t = p2;
                                for (t; (get<0>(t)!= get<0>(p1)+1)&&(get<1>(t)!=get<1>(p1)-1); (get<0>(t))++, (get<1>(t))--) {
                                    if(grid[get<0>(t) - 97][get<1>(t)]!=0){
                                        get<0>(t)--;
                                        get<1>(t)++;
                                        backtrackDiagonal(p2,t,+1,-1);
                                        i--;
                                        a--;
                                        break;
                                    }
                                    grid[get<0>(t) - 97][get<1>(t)] = a;
                                }

                            }
                        }
                        else{
                            if((get<0>(p2)-get<0>(p1)) >0){
                                tuple <char,int> t = p1;
                                for(t;(get<0>(t)!= get<0>(p2)+1)&&(get<1>(t)!=get<1>(p2)+1);(get<0>(t))++,(get<1>(t))++){
                                    if(grid[get<0>(t) - 97][get<1>(t)]!=0){
                                        get<0>(t)--;
                                        get<1>(t)--;
                                        backtrackDiagonal(p1,t,-1,-1);
                                        i--;
                                        a--;
                                        break;
                                    }
                                    grid[get<0>(t)-97][get<1>(t)] = a;
                                }

                            }

                            else {
                                tuple <char,int> t=p2;
                                for(t;(get<0>(t)!= get<0>(p1)+1)&&(get<1>(t)!=get<1>(p1)+1);(get<0>(t))++,(get<1>(t))++){
                                    if(grid[get<0>(t) - 97][get<1>(t)]!=0){
                                        get<0>(t)--;
                                        get<1>(t)--;
                                        backtrackDiagonal(p2,t,-1,-1);
                                        i--;
                                        a--;
                                        break;
                                    }
                                    grid[get<0>(t)-97][get<1>(t)] = a;
                                }


                            }

                        }

                    }
                a++;
                }
            else if((myships.begin()+i)->type==battleship){
                cout<<"Enter the coordinates of the Battleship"<<endl;
                cin >> get<0>(p1);
                cin >> get<1>(p1);
                cin >> get<0>(p2);
                cin >> get<1>(p2);

                if(get<0>(p1)==get<0>(p2)){
                    while(abs(get<1>(p1)-get<1>(p2))!=(myships.begin()+i)->sizey()-1){
                        cout <<"Wrong coordinates Enter again"<<endl;
                        cout<<"Enter the coordinates of the Battleship"<<endl;
                        cin >> get<0>(p1);
                        cin >> get<1>(p1);
                        cin >> get<0>(p2);
                        cin >> get<1>(p2);
                    }
                    int k = get<1>(p1);
                    int j = get<1>(p2);
                    int start =k;
                    int inc = (j-k)/((myships.begin()+i)->sizey()-1);
                    for(k;k!=j+inc;k=k+inc){
                        if(grid[get<0>(p1)-97][k]!=0){
                            BacktrackY(get<0>(p1),start,k-inc,inc);
                            i--;
                            b--;
                            break;
                        }
                        grid[get<0>(p1)-97][k]=b;

                    }
                }

                else if(get<1>(p1)==get<1>(p2)) {
                    while(abs(get<0>(p1)-get<0>(p2))!=(myships.begin()+i)->sizey()-1){
                        cout <<"Wrong coordinates Enter again"<<endl;
                        cout<<"Enter the coordinates of the Battleship"<<endl;
                        cin >> get<0>(p1);
                        cin >> get<1>(p1);
                        cin >> get<0>(p2);
                        cin >> get<1>(p2);
                    }
                    int k = get<0>(p1) - 97;
                    int start =k;
                    int j = get<0>(p2) - 97;
                    int inc = (j - k) / ((myships.begin() + i)->sizey()-1);
                    for (k; k != j+inc; k = k + inc) {
                        if(grid[k][get<1>(p1)]!=0){
                            BacktrackX(get<1>(p1),start,k-inc,inc);
                            i--;
                            b--;
                            break;
                        }
                        grid[k][get<1>(p1)] = b;

                    }
                }
                else {
                    while(abs(get<0>(p1)- get<0>(p2))!=((myships.begin() + i)->sizey() -1)||abs(get<1>(p1)- get<1>(p2))!=((myships.begin() + i)->sizey()-1) ){
                        cout <<"Wrong coordinates Enter again"<<endl;
                        cout<<"Enter the coordinates of the Aircraft Carrier"<<endl;
                        cin >> get<0>(p1);
                        cin >> get<1>(p1);
                        cin >> get<0>(p2);
                        cin >> get<1>(p2);
                        sqrty = sqrt( pow(abs(get<0>(p1)-get<0>(p2)),2) +  pow(abs(get<1>(p1)-get<1>(p2)),2));

                    }
                    float slope = (get<1>(p1)-get<1>(p2))/(get<0>(p2)-get<0>(p1));
                    if(slope>0) {
                        if ((get<0>(p2) - get<0>(p1)) > 0) {
                            tuple<char, int> t = p1;
                            for (t; (get<0>(t)!= get<0>(p2)+1)&&(get<1>(t)!=get<1>(p2)-1); (get<0>(t))++, (get<1>(t))--) {
                                if(grid[get<0>(t) - 97][get<1>(t)]!=0){
                                    get<0>(t)--;
                                    get<1>(t)++;
                                    backtrackDiagonal(p1,t,+1,-1);
                                    i--;
                                    b--;
                                    break;
                                }
                                grid[get<0>(t) - 97][get<1>(t)] = b;
                            }

                        } else {
                            tuple<char, int> t = p2;
                            for (t; (get<0>(t)!= get<0>(p1)+1)&&(get<1>(t)!=get<1>(p1)-1); (get<0>(t))++, (get<1>(t))--) {
                                if(grid[get<0>(t) - 97][get<1>(t)]!=0){
                                    get<0>(t)--;
                                    get<1>(t)++;
                                    backtrackDiagonal(p2,t,+1,-1);
                                    i--;
                                    b--;
                                    break;
                                }
                                grid[get<0>(t) - 97][get<1>(t)] = b;
                            }

                        }
                    }
                    else{
                        if((get<0>(p2)-get<0>(p1)) >0){
                            tuple <char,int> t = p1;
                            for(t;(get<0>(t)!= get<0>(p2)+1)&&(get<1>(t)!=get<1>(p2)+1);(get<0>(t))++,(get<1>(t))++){
                                if(grid[get<0>(t) - 97][get<1>(t)]!=0){
                                    get<0>(t)--;
                                    get<1>(t)--;
                                    backtrackDiagonal(p1,t,-1,-1);
                                    i--;
                                    b--;
                                    break;
                                }
                                grid[get<0>(t)-97][get<1>(t)] = b;
                            }

                        }

                        else {
                            tuple <char,int> t=p2;
                            for(t;(get<0>(t)!= get<0>(p1)+1)&&(get<1>(t)!=get<1>(p1)+1);(get<0>(t))++,(get<1>(t))++){
                                if(grid[get<0>(t) - 97][get<1>(t)]!=0){
                                    get<0>(t)--;
                                    get<1>(t)--;
                                    backtrackDiagonal(p2,t,-1,-1);
                                    i--;
                                    b--;
                                    break;
                                }
                                grid[get<0>(t)-97][get<1>(t)] = b;
                            }


                        }

                    }

                }
                b++;
            }
            else if((myships.begin()+i)->type==submarine){
                cout<<"Enter the coordinates of the Submarine"<<endl;
                cin >> get<0>(p1);
                cin >> get<1>(p1);
                cin >> get<0>(p2);
                cin >> get<1>(p2);

                if(get<0>(p1)==get<0>(p2)){
                    while(abs(get<1>(p1)-get<1>(p2))!=(myships.begin()+i)->sizey()-1){
                        cout <<"Wrong coordinates Enter again"<<endl;
                        cout<<"Enter the coordinates of the Submarine"<<endl;
                        cin >> get<0>(p1);
                        cin >> get<1>(p1);
                        cin >> get<0>(p2);
                        cin >> get<1>(p2);
                    }
                    int k = get<1>(p1);
                    int j = get<1>(p2);
                    int start=k;
                    int inc = (j-k)/((myships.begin()+i)->sizey()-1);
                    for(k;k!=j+inc;k=k+inc){
                        if(grid[get<0>(p1)-97][k]!=0){
                            BacktrackY(get<0>(p1),start,k-inc,inc);
                            i--;
                            s--;
                            break;
                        }
                        grid[get<0>(p1)-97][k]=s;

                    }
                }

                else if(get<1>(p1)==get<1>(p2)) {
                    while(abs(get<0>(p1)-get<0>(p2))!=(myships.begin()+i)->sizey()-1){
                        cout <<"Wrong coordinates Enter again"<<endl;
                        cout<<"Enter the coordinates of the Submarine"<<endl;
                        cin >> get<0>(p1);
                        cin >> get<1>(p1);
                        cin >> get<0>(p2);
                        cin >> get<1>(p2);
                    }
                    int k = get<0>(p1) - 97;
                    int j = get<0>(p2) - 97;
                    int start = k;
                    int inc = (j - k) / ((myships.begin() + i)->sizey()-1);
                    for (k; k != j+inc; k = k + inc) {
                        if(grid[k][get<1>(p1)]!=0){
                            BacktrackX(get<1>(p1),start,k-inc,inc);
                            i--;
                            s--;
                            break;
                        }
                        grid[k][get<1>(p1)] = s;

                    }
                }
                else {
                    while(abs(get<0>(p1)- get<0>(p2))!=((myships.begin() + i)->sizey() -1)||abs(get<1>(p1)- get<1>(p2))!=((myships.begin() + i)->sizey()-1) ){
                        cout <<"Wrong coordinates Enter again"<<endl;
                        cout<<"Enter the coordinates of the Aircraft Carrier"<<endl;
                        cin >> get<0>(p1);
                        cin >> get<1>(p1);
                        cin >> get<0>(p2);
                        cin >> get<1>(p2);
                        sqrty = sqrt( pow(abs(get<0>(p1)-get<0>(p2)),2) +  pow(abs(get<1>(p1)-get<1>(p2)),2));

                    }
                    float slope = (get<1>(p1)-get<1>(p2))/(get<0>(p2)-get<0>(p1));
                    if(slope>0) {
                        if ((get<0>(p2) - get<0>(p1)) > 0) {
                            tuple<char, int> t = p1;
                            for (t; (get<0>(t)!= get<0>(p2)+1)&&(get<1>(t)!=get<1>(p2)-1); (get<0>(t))++, (get<1>(t))--) {
                                if(grid[get<0>(t) - 97][get<1>(t)]!=0){
                                    get<0>(t)--;
                                    get<1>(t)++;
                                    backtrackDiagonal(p1,t,+1,-1);
                                    i--;
                                    s--;
                                    break;
                                }
                                grid[get<0>(t) - 97][get<1>(t)] = s;
                            }

                        } else {
                            tuple<char, int> t = p2;
                            for (t; (get<0>(t)!= get<0>(p1)+1)&&(get<1>(t)!=get<1>(p1)-1); (get<0>(t))++, (get<1>(t))--) {
                                if(grid[get<0>(t) - 97][get<1>(t)]!=0){
                                    get<0>(t)--;
                                    get<1>(t)++;
                                    backtrackDiagonal(p2,t,+1,-1);
                                    i--;
                                    s--;
                                    break;
                                }
                                grid[get<0>(t) - 97][get<1>(t)] = s;
                            }

                        }
                    }
                    else{
                        if((get<0>(p2)-get<0>(p1)) >0){
                            tuple <char,int> t = p1;
                            for(t;(get<0>(t)!= get<0>(p2)+1)&&(get<1>(t)!=get<1>(p2)+1);(get<0>(t))++,(get<1>(t))++){
                                if(grid[get<0>(t) - 97][get<1>(t)]!=0){
                                    get<0>(t)--;
                                    get<1>(t)--;
                                    backtrackDiagonal(p1,t,-1,-1);
                                    i--;
                                    s--;
                                    break;
                                }
                                grid[get<0>(t)-97][get<1>(t)] = s;
                            }

                        }

                        else {
                            tuple <char,int> t=p2;
                            for(t;(get<0>(t)!= get<0>(p1)+1)&&(get<1>(t)!=get<1>(p1)+1);(get<0>(t))++,(get<1>(t))++){
                                if(grid[get<0>(t) - 97][get<1>(t)]!=0){
                                    get<0>(t)--;
                                    get<1>(t)--;
                                    backtrackDiagonal(p2,t,-1,-1);
                                    i--;
                                    s--;
                                    break;
                                }
                                grid[get<0>(t)-97][get<1>(t)] = s;
                            }


                        }

                    }

                }
                s++;
            }
            else if((myships.begin()+i)->type==patrol){
                cout<<"Enter the coordinates of the Patrol Boat"<<endl;
                cin >> get<0>(p1);
                cin >> get<1>(p1);
                grid[get<0>(p1)-97][get<1>(p1)] = p;
                p++;
            }
            printGrid();
        i++;
        }

        cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"--------------------"<<endl;
        cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"--------------------"<<endl;
        cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"--------------------"<<endl;
        cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"--------------------"<<endl;

    };

    void printGrid(){
        if(size==5){
            int i,j;
            cout <<"  a b c d e"<<endl;
            for(i=0;i<8;i++){
                cout <<i<<"|";
                for(j=0;j<5;j++){
                    cout <<grid[j][i];
                    if(j!=4)cout <<"_";
                }
                cout <<endl;

            }

        }

        else if(size==8){
            int i,j;
            cout <<"  a b c d e f g h"<<endl;
            for(i=0;i<10;i++){
                cout <<i<<"|";
                for(j=0;j<8;j++){
                    cout <<grid[j][i];
                    if(j!=7)cout <<"_";
                }
                cout <<endl;

            }

        }

        else {
            int i,j;
            cout <<"   a b c d e f g h i j"<<endl;
            for(i=0;i<12;i++){
                cout <<i;
                if(i<10)cout <<" ";
                cout <<"|";
                for(j=0;j<10;j++){
                    cout <<grid[j][i];
                    if(j!=9)cout <<"_";

                }
                cout <<endl;

            }

        }


    };
    int shooterFinder(){
        int i;
        int max=0;
        int max_ind=-1;
        for(i=0;(myships.begin()+i)!=myships.end();i++){
            if((myships.begin()+i)->staty() == operative){
                if(max ==0){
                    max = (myships.begin()+i)->capy();
                    max_ind = i;
                }
                else if((myships.begin()+i)->capy() > max){
                    max = (myships.begin()+i)->capy();
                    max_ind = i;
                }




            }

        }
        return max_ind;
    };

    int Attack(class Player &p2){
        int shooter = shooterFinder();
        if(shooter==-1){cout <<"GAMEE OVEEERRRR!"<<endl;return 1;};
        cout <<name<<" ";
        (myships.begin()+shooter)->Shoot(&shooting_grid);
        cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"--------------------"<<endl;
        cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"--------------------"<<endl;
        cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"--------------------"<<endl;
        cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"--------------------"<<endl;
        p2.TakeShot(&shooting_grid);



    }
    int nthShip(int add, enum ShipType type){
        int i;
        for(i=0;(myships.begin()+i)!=myships.end();i++){
            if((myships.begin()+i)->type==type){
                if(add==1)return i;
                add--;
            }

        }


    }
    void TakeShot(char ***attacker_grid){
        if (size==5){
            int i,j;
            int elem;
            int add;
            for(i=0;i<5;i++){

                for(j=0;j<8;j++){
                    if(grid[i][j]!=-1 && (*attacker_grid)[i][j]=='0'){
                        elem = grid[i][j];
                        grid[i][j] = -1;
                        if(elem >=A && elem <B){
                            add=nthShip(elem-A+1,aircraft);
                            (myships.begin()+add)->TakeHit();
                        }
                        else if(elem >=B && elem <S){
                                add=nthShip(elem-B+1,battleship);
                                (myships.begin()+add)->TakeHit();
                            }

                        else if(elem >=S && elem <P){
                                add=nthShip(elem-S+1,submarine);
                                (myships.begin()+add)->TakeHit();
                            }

                        else {
                            add=nthShip(elem-P+1,patrol);
                            (myships.begin()+add)->TakeHit();
                        }

                    }
                }
            }
        }
       else if (size==8){
            int i,j;
            int elem;
            int add;
            for(i=0;i<8;i++){

                for(j=0;j<10;j++){
                    if(grid[i][j]!=-1 && (*attacker_grid)[i][j]=='0'){
                        elem = grid[i][j];
                        if(elem >=A && elem <B){
                            add=nthShip(elem-A+1,aircraft);
                            (myships.begin()+add)->TakeHit();
                        }

                        else if(elem >=B && elem <S){
                                add=nthShip(elem-B+1,battleship);
                                (myships.begin()+add)->TakeHit();
                            }

                       else if(elem >=S && elem <P){
                                add=nthShip(elem-S+1,submarine);
                                (myships.begin()+add)->TakeHit();
                            }

                        else {
                            add=nthShip(elem-P+1,patrol);
                            (myships.begin()+add)->TakeHit();
                        }

                    }
                }
            }
        }
        else if (size==10){
            int i,j;
            int elem;
            int add;
            for(i=0;i<10;i++){

                for(j=0;j<12;j++){
                    if(grid[i][j]!=-1 && (*attacker_grid)[i][j]=='0'){
                        elem = grid[i][j];
                        if(elem >=A && elem <B){
                            add=nthShip(elem-A+1,aircraft);
                            (myships.begin()+add)->TakeHit();
                        }

                        else if(elem >=B && elem <S){
                                add=nthShip(elem-B+1,battleship);
                                (myships.begin()+add)->TakeHit();
                            }
                        else if(elem >=S && elem <P){
                                add=nthShip(elem-S+1,submarine);
                                (myships.begin()+add)->TakeHit();
                            }

                        else {
                            add=nthShip(elem-P+1,patrol);
                            (myships.begin()+add)->TakeHit();
                        }

                    }
                }
            }
        }
        Evaluate();
    }
    void Evaluate (){
        int i;
        for(i=0;(myships.begin()+i)!=myships.end();i++){
            (myships.begin()+i)->update_status();
        }
    }

    void BacktrackY(char x,int start, int j, int inc){
        cout <<"OVERLAP TRY AGAIN"<<endl;
        for(j;j!=start-inc;j=j-inc){
            grid[x-97][j]=0;
        }
    }

    void BacktrackX(int y,int start,int j,int inc){
        cout <<"OVERLAP TRY AGAIN"<<endl;
        for(j;j!=start-inc;j=j-inc){
            grid[j][y]=0;
        }

    };

    void backtrackDiagonal(tuple <char,int> p1,tuple <char,int> p2, int incx,int incy){
            cout <<"OVERLAP TRY AGAIN"<<endl;
            for(p2;  (get<0>(p2)!=get<0>(p1)+incy)&&(get<1>(p2)!=get<1>(p1)+incx) ; get<0>(p2)=get<0>(p2)+incy,get<1>(p2)=get<1>(p2)+incx){
                grid[get<0>(p2)-97][get<1>(p2)]=0;

            }





    }

    const char * nameget(){
        return name;
    }

};



#endif //

// ASS4_SHIPS_H
