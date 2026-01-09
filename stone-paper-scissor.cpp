#include<iostream>
using namespace std;

void inputuser(char &p1, char &p2){
    cout<<"Player 1, Your Turn: ";
    cin >> p1;
    cout<<" " << endl;
    cout<<"Player 2, Your Turn: ";
    cin >> p2;
    cout<<" " << endl;
    }
    
void result(char p1, char p2){
    if(p1 == 'r' || p1 == 'R'){
        if(p2 == 's'  || p2 == 'S'){ cout<<"Player 1 wins!"<<endl;}
        else if(p2 == 'p' || p2 == 'P'){ cout<<"Player 2 wins!"<<endl;}
        else if(p2 == 'r' || p2 == 'R'){ cout<<"It's a tie!"<<endl;}
        else {cout << "It's an invalid move. Try Again!"<<endl;}
    }
    else if(p1 == 'p'  || p1 == 'P'){
        if(p2 == 's'|| p2 == 'S'){ cout<<"Player 2 wins!"<<endl;}
        else if(p2 == 'p'|| p2 == 'P'){ cout<<"It's a tie"<<endl;}
        else if(p2 == 'r'|| p2 == 'R'){ cout<<"Player 1 wins!"<<endl;}
        else {cout << "It's an invalid move. Try Again!"<<endl;}
    }
    else if(p1 == 's' || p1 == 'S'){
        if(p2 == 's'|| p2 == 'S'){ cout<<"It's a tie"<<endl;}
        else if(p2 == 'p'|| p2 == 'P'){ cout<<"Player 1 wins!"<<endl;}
        else if(p2 == 'r'|| p2 == 'R'){ cout<<"Player 2 wins!"<<endl;}
        else {cout << "It's an invalid move. Try Again!"<<endl;}
    }
    else {cout << "It's an invalid move. Try Again!"<<endl;}
    }


int main() {
    char p1, p2;
    int score_p1 = 0, score_p2=0;
    cout<<"Welcome to Rock Paper Scisssors Game"<<endl;
    cout<<"Use R for Rock,\nP for Paper, \nand S for Scissors"<<endl;
    cout<< " "<< endl;
    
    for(int i=1; i<=5; i++){
        inputuser(p1, p2);
        result(p1, p2);
        cout<< " "<< endl;
    }

    return 0;
}
