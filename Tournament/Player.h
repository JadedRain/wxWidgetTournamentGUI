#pragma once
#include <iostream>

using namespace std;

class Player
{
private:
	string current_team;
	string player_name;
	string player_role;
	int player_power;


public:
	Player(string name = "Unnamed", string role = "None", int power = 0);
	string get_name();
	string get_role();
	int get_power();
	string get_team();
	void set_power(int power);
	void set_team(string team);

};

