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
    cout << n_pos_teams << " Teams Have Scored More Than They Got Scored" << endl;
    return 0;
}
