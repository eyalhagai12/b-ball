#include "Game.hpp"
#include <vector>

class League
{
private:
    std::vector<Team *> teams;
    
public:
    // construstor destructor
    League();
    League(std::vector<Team *> teams);
    ~League();

    // methods
    void play_all_games();                             // play all games
    void play_next_game();                             // play the next game
    std::vector<std::vector<int>> get_scores();        // get scores after playing games
    std::vector<Team *> get_top_teams(size_t n_teams); // get n top teams
};
