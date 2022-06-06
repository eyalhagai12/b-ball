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
    Season(const Season &other);
    Season(Season &&other) noexcept;
    ~Season() = default;

    // methods
    void play_game();                                      // play the upcoming game
    void play_games(size_t n_games);                       // play the n games of the games
    void play_rest();                                      // play the rest of the games
    void play_all_games();                                 // play all games
    std::vector<Team *> get_top_teams(long n_teams) const; // get the top n teams
    size_t n_positive_diff_teams() const;                  // get the number of teams with a positive score difference
    std::pair<Team *, size_t> longet_win_streak() const;   // get the team with the longest win streak and the win streak
    std::pair<Team *, size_t> longet_loss_streak() const;  // get the team with the longest lose streak and the lose streak
    Team &top_scores();                                    // get the team that scored the most
    Team &top_scored();                                    // get the team that got scored the most

    // operator overloads
    Season &operator=(const Season &other);
    Season &operator=(Season &&other) noexcept;
};
