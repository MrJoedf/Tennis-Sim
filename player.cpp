//
// Created by Joe D on 3/15/20.
//

#include "player.h"

void player::setName(string name){
    this->name=name;
}

void player::setServe(int serveRate){
    this->serveRating=serveRate;
}

void player::setReturn(int returnRate){
    this->returnRating=returnRate;
}

string player::getName(){
    return this->name;
}

int player::getServe(){
    return this->serveRating;
}

int player::getReturn(){
    return this->returnRating;
}