//
// Created by Joe D on 3/15/20.
//

#include "set.h"
#include <iostream>
using namespace std;

int set::playSet(player player1, player player2) {
    player temp;
    while (this->p1Games != 6 && this->p2Games != 6) {
        game Game(player1, player2);
        if (Game.playGame() == 1) {
            this->p1Games++;
            cout << this->p1Games << " - " << this->p2Games << endl;

        } else if (Game.playGame() == 0) {
            game Game(player1, player2);
            this->p2Games++;
            cout << this->p1Games << " - " << this->p2Games << endl;
        }

        game Game1(player2, player1);
        if (Game1.playGame()==1) {
            this->p2Games++;
            cout << this->p1Games << " - " << this->p2Games << endl;

        } else if (Game1.playGame() == 0) {
            game Game1(player2, player1);
            this->p1Games++;
            cout << this->p1Games << " - " << this->p2Games << endl;
        }
        if (this->p1Games == 6 || this->p2Games == 6) {
            if (this->p1Games == 6 && p2Games < 5) {
                cout << this->p1Games << " - " << this->p2Games << endl;
                break;
            } else if (this->p2Games == 6 && p1Games < 5) {
                cout << this->p1Games << " - " << this->p2Games << endl;
                break;

            }
            if (this->p1Games == 6 && p2Games == 5) {
                if (Game.playGame() == 1) {
                    this->p1Games++;
                    cout << this->p1Games << " - " << this->p2Games << endl;
                    break;
                } else if (Game.playGame() == 0) {
                    this->p2Games++;
                    cout << this->p1Games << " - " << this->p2Games << endl;
                    break;
                }
            } if (this->p2Games == 6 && p1Games == 5) {
                if (Game1.playGame() == 1) {
                    this->p2Games++;
                    cout << this->p1Games << " - " << this->p2Games << endl;
                    break;
                } else if (Game1.playGame() == 0) {
                    this->p1Games++;
                    cout << this->p1Games << " - " << this->p2Games << endl;
                    break;
                }
            }
            break;
        } //if statement
    }
    winner();
}

void set::winner(){
    if(p1Games>p2Games){
        cout<<p1.getName()<<" WINS THE SET "<<p1Games<<"-"<<p2Games<<endl;
    }else if(p2Games>p1Games){
        cout<<p2.getName()<<" WINS THE SET "<<p2Games<<"-"<<p1Games<<endl;
    }
}