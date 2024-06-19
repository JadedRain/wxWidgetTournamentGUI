#pragma once
#include <vector>
#include <array>
#include "Team.h"
class Tournament_Runner {
private:
	int num_teams;
	vector<Team> teams_in_tournament;
	vector<array<Team, 2>> bracket;
public:
	Tournament_Runner(vector<Team> teams);
	Tournament_Runner();
	void create_bracket();
	void show_bracket();
	void play_series();
	vector<array<Team, 2>> get_bracket();
	Team get_winner();
};

