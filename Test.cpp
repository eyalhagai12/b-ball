#include "doctest.h"
#include "Season.hpp"

#include <iostream>

League league;
Schedule schedule(league);
Season season(league, schedule);


bool compare_teams_test(Team *team1, Team *team2)
{
    // get ratios
    float t1_ratio = team1->get_wins();
    float t2_ratio = team2->get_wins();

    if (team1->get_losses() > 0)
    {
        t1_ratio /= team1->get_losses();
    }
    if (team2->get_losses() > 0)
    {
        t2_ratio /= team2->get_losses();
    }

    // compare
    if (t1_ratio > t2_ratio)
    {
        return true;
    }
    if (t1_ratio < t2_ratio)
    {
        return false;
    }
    return team1->get_score_diff() > team2->get_score_diff();
}

TEST_CASE("Test top teams")
{
    CHECK_NOTHROW_MESSAGE(season.play_game(), "play game threw an error!");
    CHECK_THROWS(season.get_top_teams(4));
    CHECK_NOTHROW_MESSAGE(season.play_games(10), "play 10 games threw an error!");
    CHECK_NOTHROW_MESSAGE(season.get_top_teams(4), "get top teams threw an error, when we played more than 4 games before");
}

TEST_CASE("Test longest win and lose streak")
{
    season.play_rest();
    std::pair<Team *, size_t> longest_win_streak = season.longet_win_streak();
    std::pair<Team *, size_t> longest_loss_streak = season.longet_loss_streak();

    for (Team *team : league)
    {
        CHECK_MESSAGE(team->get_win_streak() <= longest_win_streak.second, "We have a team with a longer win streak then the function returned!");
    }

    for (Team *team : league)
    {
        CHECK_MESSAGE(team->get_lose_streak() <= longest_loss_streak.second, "We have a team with a longer lose streak then the function returned!");
    }
}

TEST_CASE("Test num of teams who scored more than they got scored is correct")
{
    size_t counter = 0;
    for (Team *team : league)
    {
        if (team->get_score_diff() > 0)
        {
            counter += 1;
        }
    }

    CHECK_MESSAGE(counter == season.n_positive_diff_teams(), "number of teams with positive score difference doest match!");
}

TEST_CASE("Test top scoring team and top scored team")
{
    Team &team = season.top_scores();
    Team *top_team = nullptr;
    size_t max_score = 0;
    for (Team *team : league)
    {
        if (team->get_scores() > max_score)
        {
            max_score = team->get_scores();
            top_team = team;
        }
    }

    CHECK_MESSAGE(top_team->get_name() == team.get_name(), "top scoring team is worng");
    CHECK_MESSAGE(top_team->get_scores() == team.get_scores(), "top scoring team scores are worng");

    Team &team2 = season.top_scored();
    Team *top_team2 = nullptr;
    size_t max_score2 = 0;
    for (Team *team : league)
    {
        if (team->get_scored() > max_score2)
        {
            max_score2 = team->get_scored();
            top_team2 = team;
        }
    }

    CHECK_MESSAGE(top_team2->get_name() == team2.get_name(), "top scored team is worng");
    CHECK_MESSAGE(top_team2->get_scored() == team2.get_scored(), "top scored team scores are worng");
}

TEST_CASE("Test top team list")
{
    long n_teams = 5;
    std::vector<Team *> teams = season.get_top_teams(n_teams);

    for (size_t i = 0; i < teams.size() - 1; ++i)
    {
        CHECK_MESSAGE(compare_teams_test(teams.at(i), teams.at(i + 1)), "top n teams order is worng!");
    }
}