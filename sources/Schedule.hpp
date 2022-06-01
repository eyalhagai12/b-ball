#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "League.hpp"

class Schedule
{
private:
    std::vector<Game *> games;
    size_t idx;
    League &league;
    size_t games_left;

public:
    // constructor destructor
    Schedule(League &league);
    ~Schedule();

    // methods
    Game &get_current_game() const;                   // get current game
    void next();                                      // go to next game
    std::vector<std::vector<int>> get_scores() const; // get scores to all played games
    std::vector<Game *>::iterator begin();            // get the start of the iterator over all games
    std::vector<Game *>::iterator end();              // get the end of the iterator over all games
    size_t get_current_game_idx();                    // get the current game index
    size_t get_games_left();                          // get the number of games left

    // friend functions
    friend std::ostream &operator<<(std::ostream &out, const Schedule &schedule);
};
