#include <iostream>
#include "ships.h"
int main() {
    int type;
    char tmp[20];
    do {
        cout << endl << "Enter the Grid type (5x8) (8x10) (10x12)";
        cin >> tmp;
    } while (strcmp(tmp, "5x8") && strcmp(tmp, "8x10") && strcmp(tmp, "10x12"));
    if(!strcmp(tmp,"5x8"))type=0;
    else if(!strcmp(tmp,"8x10"))type=1;
    else type=2;
    class Player a(type);
    class Player b(type);
    a.DeployShips();
    b.DeployShips();
    int win1,win2;
    win1=0;
    win2=0;
    while(!win1 && !win2){
        win1=a.Attack(b);
        win2=b.Attack(a);
    }
    if(win1) cout <<"Player "<<b.nameget()<<"WON!"<<endl;
    else cout <<"Player "<<a.nameget()<<"WON!"<<endl;
    return 0;
}