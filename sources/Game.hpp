#include "Team.hpp"
#include <vector>

class Game
{
private:
    Team home_team;
    Team guest_team;
    std::vector<int> score;

public:
    // constructor destructor
    Game(Team &home_team, Team &guest_team);
    ~Game() = default;

    // methods
    Team &play();                 // play game and return the winner
    Team &get_home_team();        // get home team
    Team &get_guest_team();       // get guest team
    std::vector<int> get_score(); // get the score of the game
};