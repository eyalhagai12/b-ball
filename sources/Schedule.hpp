#include <iostream>
#include <vector>

#include "League.hpp"

class Schedule
{
private:
    std::vector<Game *> games;
    size_t idx;
    League &league;

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

    // friend functions
    friend std::ostream &operator<<(std::ostream &out, const Schedule &schedule);
};
