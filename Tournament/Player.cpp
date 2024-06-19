#include "Player.h"

Player::Player(string name, string role, int power) {
	player_name = name;
	player_role = role;
	player_power = power;
}

string Player::get_name() { return player_name; }
string Player::get_role() { return player_role; }
int Player::get_power() { return player_power; }
string Player::get_team() { return current_team; }

void Player::set_team(string team) { current_team = team; }
void Player::set_power(int power) {
	if (power >= 0 && power <= 100) {
		player_power = power;
	}
}