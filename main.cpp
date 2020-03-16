#include "player.h"
#include "game.h"
#include "set.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>


using namespace std;
void printPlayers(player Roster[], int size){
    cout<<"\nPLAYERS:\n";
    for(int i=0; i<size; i++){
        cout<<"#"<<i+1<<" "<<Roster[i].getName()<<endl;
    }
}


int main() {
    string line;
    int numPlayers = 0;

    string playerName;
    string playerServe;
    string playerReturn;

    ifstream playerFile;
    ifstream playerCount;
    playerCount.open("players.txt");
    while (getline(playerCount, line)) {
        numPlayers++;
    }
    playerCount.close();

    player Players[10];
    player tempPlayer;
    playerFile.open("players.txt");

    //Getting players from file and adding to array
    for (int i = 0; i < numPlayers; i++) {
        getline(playerFile, playerName, ',');
            tempPlayer.setName(playerName);

        getline(playerFile, playerServe, ',');
            tempPlayer.setServe(stoi(playerServe));

        getline(playerFile, playerReturn);
            tempPlayer.setReturn(stoi(playerReturn));

        Players[i] = tempPlayer;
    }
        //cout<<playerFile.is_open()<<endl;

        int choice;
        cout << "Welcome to TENNIS SIM!" << endl;
        cout << "Would you like to simulate 1 match or 1 tourney?" << endl;
        cout << "1. Single match" << endl
             << "2. Tournament" << endl;
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"You chose SINGLE MATCH."<<endl;
                int serveChoice, returnChoice;
                printPlayers(Players, numPlayers);
                cout<<"\nPick two players (first choice will serve first): "<<endl;
                    cin>>serveChoice>>returnChoice;
                        cout<<"MATCHUP: \n"<<"#"<<serveChoice<<" "<<Players[serveChoice-1].getName()
                        <<" VS "<<"#"<<returnChoice<<" "<<Players[returnChoice-1].getName()<<endl;

               /* if(final.playGame()){
                    cout<<"SERVER WON GAME"<<endl;
                }else{
                    cout<<"RETURNER BROKE!"<<endl;
                }*/

               set firstSet(Players[serveChoice-1], Players[returnChoice-1]);
                firstSet.playSet(Players[serveChoice-1], Players[returnChoice-1]);

            }
        }

        return 0;
    }

