//
// Created by Joe D on 3/16/20.
//

#ifndef TENNIS_MATCH_H
#define TENNIS_MATCH_H
#include "player.h"
#include "match.h"

class match {
    player player1;
    player player2;
    int numSets;
    bool tied;

    int p1Set;
    int p2Set;
    string matchScore;

public:
    match(player p1, player p2, int nSets){
        player1=p1;
        player2=p2;
        p1Set = 0;
        p2Set = 0;
        numSets=nSets;
        playMatch();
        tied = false;
    }


    int playMatch();

    void setP1();

    void setP2();

    void setMatch(string score);

    void getMatchScore();

    bool isTied();

};


#endif //TENNIS_MATCH_H
