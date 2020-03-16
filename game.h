//
// Created by Joe D on 3/15/20.
//

#ifndef GAME_H
#define GAME_H

using namespace std;
#include "player.h"
#include <ctime>
#include <cstdlib>


class game {
    player server;
    player returner;

    int serveScore;
    int returnScore;

public:
    game(player player1, player player2){
        this->server = player1;
        this->returner = player2;
        this->serveScore = 0;
        this->returnScore = 0;
    }

    void setServerScore(int score);

    void setReturnScore(int score);

    int getServerScore();

    int getReturnScore();

    int playPoint();

    int playDeuce();

    int playGame();
};


#endif //TENNIS_GAME_H
