//
// Created by Joe D on 3/16/20.
//

#include "match.h"
#include "set.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

void match::setP1(){
    this->p1Set+=1;
}

void match::setP2(){
    this->p2Set+=1;
}

void match::setMatch(string score){
    this->matchScore=score;
    cout<<this->matchScore;
}

void match::getMatchScore() {
    cout<<this->matchScore;
}

int match::playMatch() {
    ofstream matchFile;
    matchFile.open("testmatch.txt");
    if(this->numSets==1){
            cout<<player1.getName()<<" TO SERVE: "<<endl;
            set set1(player1, player2);
            if (set1.playSet(player1, player2) == 1) {
                setP1();
                matchFile<<set1.getP1Games()<<"-"<<set1.getP2Games()<<endl;
                    } else if (set1.playSet(player1, player2) == 0) {
                        setP2();
                        matchFile<<set1.getP1Games()<<"-"<<set1.getP2Games()<<endl;
            }
        }
         if(this->numSets==3){
            //FIRST SET
             cout<<player1.getName()<<" TO SERVE: "<<endl;
            set set1(player1, player2);
            if (set1.playSet(player1, player2) == 1) {
                setP1();
                matchFile<<set1.getP1Games()<<"-"<<set1.getP2Games()<<endl;
            } else if (set1.playSet(player1, player2) == 0) {
                setP2();
                matchFile<<set1.getP1Games()<<"-"<<set1.getP2Games()<<endl;
            }

            //SECOND SET
             cout<<player2.getName()<<" TO SERVE: "<<endl;
            set set2(player2, player1);
            if (set2.playSet(player2, player1) == 1) {
                setP2();
                matchFile<<set1.getP1Games()<<"-"<<set1.getP2Games()<<", ";

            } else if (set2.playSet(player2, player1) == 0) {
                setP1();
                matchFile<<set1.getP1Games()<<"-"<<set1.getP2Games()<<", ";
            }

            if(this->p1Set==2 && this->p2Set>=1){
                cout<<player1.getName()<<" WINS "<<this->matchScore<<endl;
                return 1;
            } else if(this->p2Set==2 && this->p1Set>=1){
                cout<<player2.getName()<<" WINS "<<this->matchScore<<endl;
                return 2;

                //POTENTIAL THIRD SET
            }else if(this->p2Set==this->p2Set){
                cout<<player1.getName()<<" TO SERVE: "<<endl;
                set set3(player1, player2);
                if (set3.playSet(player1, player2) == 1) {
                    setP1();
                    matchFile<<set1.getP1Games()<<"-"<<set1.getP2Games()<<endl;
                    return 1;

                } else if (set3.playSet(player1, player2) == 0) {
                    setP2();
                    matchFile<<set1.getP1Games()<<"-"<<set1.getP2Games()<<", ";
                    return 2;
                }

            }

    }

}
