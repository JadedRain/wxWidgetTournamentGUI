#include <iostream>
#include <map>
#include "Team.h"


using namespace std;

Team::Team(string team_name) {
    name = team_name;
}

void Team::set_member(string role, Player player)
{
    if (player.get_role() == role) {
        team_members[role] = player;
    }
}
void Team::remove_member(string role) {
    if (team_members.find(role) != team_members.end()) {
        team_members[role] = Player();
    }
}
string Team::get_name() {
    return name;
}

int Team::get_wins() {
    return wins;
}

int Team::get_loses() {
    return loses;
}

void Team::game_win() {
    wins++;
}

void Team::game_loss() {
    loses++;
}

double Team::average_power() {
    double total_power = 0;
    for (auto i = team_members.begin(); i != team_members.end(); i++) {
        total_power += i->second.get_power();
    }
    return total_power / team_members.size();
}
