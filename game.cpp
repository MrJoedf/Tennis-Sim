//
// Created by Joe D on 3/15/20.
//

#include "game.h"
#include <iostream>
#include <iomanip>
using namespace std;

void game::setServerScore(int score){
    this->serveScore = score;
}

void game::setReturnScore(int score){
    this->serveScore = score;
}

int game::getServerScore(){
    return this->serveScore;
}

int game::getReturnScore(){
    return this->returnScore;
}
int game::playPoint() {
    using namespace std;
    srand(time(NULL) + rand());
    /*probability of server winning point is their serve rating
     * divided by their serve rating plus their opponent's return rating
     * For example: 90 serve against 90 return would yield probability of 50%
     * since they are evenly matched
     * */
    float prob = (this->server.getServe() * 1.0) / (this->server.getServe() + this->returner.getReturn())*100.0;
    float result = (rand() % 100) * 1.0;
    //cout << fixed << setprecision(2) << "PROB: " << prob << endl;
    //If result is less than or equal to probability of winning, server wins point since greater odds typically

    int serverWon = (result<=prob);
    return serverWon;

}

int game::playDeuce(){
    srand(time(NULL)+rand());

    float prob = (this->server.getServe()-(this->server.getServe()-this->returner.getReturn()))*100.0;
    float result = (rand()%100)*1.0;

    this->returnScore = 0;
    this->serveScore = 0;

    //if server wins point
    if(playPoint()==1){
        this->serveScore+=2;
    }else{ //if returner wins point
        this->returnScore+=1;
    }

    if(abs(serveScore-returnScore)==2){
        return(serveScore-returnScore)==2;
    }
    //If result is less than or equal to probability of winning, server wins point since greater odds typically

}
    int game::playGame() {
        while (this->serveScore < 4 && this->returnScore < 4) {
            if (playPoint() == 1) {
                this->serveScore++;
            }else{
                this->returnScore++;
            }
        }
        if (this->serveScore == 3 || this->returnScore == 3) {
            if (this->serveScore == this->returnScore) {
                return (playDeuce());
            }else{
                return (serveScore > returnScore);
            }
        }
    }

