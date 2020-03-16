//
// Created by Joe D on 3/15/20.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class player {
    string name;
    int serveRating;
    int returnRating;

public:
    void setName(string name);

    void setServe(int serveRate);

    void setReturn(int returnRate);

    string getName();

    int getServe();

    int getReturn();

    player(){
        name = "";
        serveRating = 0;
        returnRating = 0;
    }

    player(string name, int serveRating, int returnRating){
        setName(name);
        setServe(serveRating);
        setReturn(returnRating);
    }
};


#endif //TENNIS_PLAYER_H
