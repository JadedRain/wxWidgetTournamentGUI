#pragma once
#include <iostream>
#include <map>
#include "Player.h"

using namespace std;

class Team {
private:
    string name;
    int wins = 0;
    int loses = 0;
    map<string, Player> team_members =
    { {"Top", Player()},
      {"Jungle", Player()},
      {"Mid", Player()},
      {"ADC", Player()},
      {"Support", Player()}
    };

public:
    Team(string team_name = "No Team");
    void set_member(string role, Player player);
    void remove_member(string role);
    string get_name();
    int get_wins();
    int get_loses();
    void game_win();
    void game_loss();
    double average_power();
};