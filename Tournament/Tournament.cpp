#include <iostream>
#include "Team.h"
#include "Player.h"
#include "Tournament_Runner.h"


using namespace std;

//int main()
//{
//    vector<string> names = { "Cloud9", "NRG", "T1", "Team Liquid", "TES", "GENG", "G2"};
//    Player blaber("Blaber", "Jungle", 86);
//    vector<Team> teams;
//    srand((unsigned)time(nullptr));
//    for (auto i : names) {
//        Team team(i);
//        team.set_member("Jungle", Player("Greg", "Jungle", rand() % 100 + 1));
//        teams.push_back(team);
//    }
//
//    Tournament_Runner msi(teams);
//    cout << "SERIES 1" << endl;
//    msi.create_bracket();
//    msi.show_bracket();
//    msi.play_series();
//    cout << "SERIES 2" << endl;
//    msi.create_bracket();
//    msi.show_bracket();
//    msi.play_series();
//    cout << "SERIES 3" << endl;
//    msi.create_bracket();
//    msi.show_bracket();
//    msi.play_series();
//    cout << "Winner: " << msi.get_winner().get_name() << endl;
//
//    
//}
