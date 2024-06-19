#include "Tournament_Runner.h"
#include <time.h>

Tournament_Runner::Tournament_Runner(vector<Team> teams) {
	num_teams = teams.size();
	teams_in_tournament = teams;
}
Tournament_Runner::Tournament_Runner() {

}

void Tournament_Runner::create_bracket() {
	srand((unsigned)time(nullptr));

	// Creates bracket for tournament by going through each team in the tournament randomly and 
	// adding two the array before pushing that array to the bracket
	int counter = 0;
	array<Team, 2> match;
	while (teams_in_tournament.size() > 0) {
		num_teams = teams_in_tournament.size(); 
		int team_index = rand() % num_teams;
		Team t = teams_in_tournament[team_index];
		teams_in_tournament.erase(teams_in_tournament.begin() + team_index);
		match[counter % 2] = t;
		counter++;
		if ((counter) % 2 == 0 || num_teams <= 1) {
			bracket.push_back(match);
			match = array<Team, 2>();
		}
	}

}


void Tournament_Runner::show_bracket() {
	for (auto i = bracket.begin(); i < bracket.end(); i++) {
		cout << "Team 1: " << i->at(0).get_name() << endl;
		cout << "Team 2: " << i->at(1).get_name() << endl;
		cout << "------------------------------" << endl;
	}
}

void Tournament_Runner::play_series() {
	for (auto match : bracket) {
		double team_one_power = match[0].average_power();
		double team_two_power = match[1].average_power();

		//cout << team_one_power << endl;
		//cout << team_two_power << endl;
		if (team_one_power > team_two_power) {
			match[0].game_win();
			match[1].game_loss();
			teams_in_tournament.push_back(match[0]);
		}
		else if (team_one_power < team_two_power) {
			match[1].game_win();
			match[0].game_loss();
			teams_in_tournament.push_back(match[1]);
		}
		else {
			teams_in_tournament.push_back(match[0]);
			teams_in_tournament.push_back(match[1]);
		}
	}
	bracket = vector<array<Team, 2>>();
}

vector<array<Team, 2>> Tournament_Runner::get_bracket() {
	return bracket;
}

Team Tournament_Runner::get_winner() {
	if (teams_in_tournament.size() == 1) {
		return teams_in_tournament[0];
	}
	cout << teams_in_tournament[0].average_power() << endl;
	cout << teams_in_tournament[1].average_power() << endl;
	cout << "No winner yet!" << endl;
	return Team();
}
