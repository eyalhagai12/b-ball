#pragma once
#include "Schedule.hpp"

class Season
{
private:
    League &league;
    Schedule &schedule;

public:
    // constructors and destructor
    Season(League &league, Schedule &schedule);
    Season(std::vector<Team *> teams);
    ~Season() = default;

    // methods
    void play_game();
    void play_all_games();
};
