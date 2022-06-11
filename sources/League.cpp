#include "League.hpp"

#include <iostream>
#include <iomanip>
#include <string>

const size_t num_of_teams = 20;

// -------------------------------------------------
// construtors and destructor
// -------------------------------------------------
League::League()
{
    for (size_t i = 0; i < num_of_teams; ++i)
    {
        std::string new_name = "Team " + std::to_string(i + 1);
        // srand(time(NULL));`
        float skill = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        Team *new_team = new Team(new_name, skill);
        teams.push_back(new_team);
    }
}

League::League(std::vector<Team *> &teams) : teams(teams)
{
    for (size_t i = this->teams.size(); i < num_of_teams; ++i)
    {
        std::string new_name = "Team " + std::to_string(i + 1);
        float skill = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        Team *new_team = new Team(new_name, skill);
        this->teams.push_back(new_team);
    }
}

League::~League()
{
    for (Team *team : this->teams)
    {
        delete team;
    }
}

// -------------------------------------------------
// utility functions
// -------------------------------------------------
bool compare_teams(Team *team1, Team *team2)
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

// -------------------------------------------------
// method implementaitons
// -------------------------------------------------
std::vector<Team *> League::get_teams() const
{
    return this->teams;
}

std::vector<Team *> League::get_top_teams(long n_teams)
{
    std::sort(this->teams.begin(), this->teams.end(), compare_teams);
    std::vector<Team *> top_teams;
    top_teams.assign(this->teams.begin(), this->teams.begin() + n_teams);
    return top_teams;
}

std::vector<Team *>::iterator League::begin() { return this->teams.begin(); }
std::vector<Team *>::iterator League::end() { return this->teams.end(); }

// -------------------------------------------------
// operator overloads
// -------------------------------------------------
std::ostream &operator<<(std::ostream &out, const League &league)
{
    for (Team *team : league.teams)
    {
        out << team->get_name() << ", Skill - " << std::fixed << std::setprecision(2) << team->get_skill() << " ["
            << "Wins - " << team->get_wins() << ", Losses - " << team->get_losses() << "]" << std::endl;
    }

    return out;
}
