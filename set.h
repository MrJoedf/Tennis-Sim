//
// Created by Joe D on 3/15/20.
//

#ifndef SET_H
#define SET_H
#include "player.h"
#include "game.h"

class set {
    int p1Games;
    int p2Games;
    player p1;
    player p2;

public:
    set(player player1, player player2){
        p1Games;
        p2Games;
        p1=player1;
        p2=player2;
    }

    int playSet(player player1, player player2);
    int tieBreak();
    void winner();
};


#endif //TENNIS_SET_H
