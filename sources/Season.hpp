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
    std::vector<Team *> get_top_teams(long n_teams) const;
    size_t n_positive_diff_teams() const;
};
