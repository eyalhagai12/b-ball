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
    Game &get_current_game() const; // get current game
    void next();                    // go to next game

    // friend functions
    friend std::ostream &operator<<(std::ostream &out, const Schedule &schedule);
};
