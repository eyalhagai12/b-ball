#include <iostream>
#include "Game.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Team team1("Eyals team", 0.2);
    Team team2("Tals team", 1.0);
    Game game(team1, team2);
    Team winner = game.play();
    cout << "Winning Team: " << winner.get_name() << endl;
    return 0;
}
