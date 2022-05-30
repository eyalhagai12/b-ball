#include <iostream>
#include "Season.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    League league;
    Schedule sch(league);
    Season s(league, sch);
    s.play_all_games();

    long n_teams = 4;
    cout << endl
         << n_teams << " Top Teams: " << endl;
    vector<Team *> top_teams = s.get_top_teams(n_teams);
    for (Team *team : top_teams)
    {
        cout << team->get_name() << endl;
    }

    size_t n_pos_teams = s.n_positive_diff_teams();
    cout << endl
         << n_pos_teams << " Teams Have Scored More Than They Got Scored" << endl;

    auto w_streak = s.longet_win_streak();
    cout << endl
         << w_streak.first->get_name() << " has had the longest win streak, They won "
         << w_streak.second << " times in a row!" << endl;
    return 0;
}
