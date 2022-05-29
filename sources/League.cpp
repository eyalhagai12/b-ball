#include "League.hpp"

#include <iostream>
#include <string>

#define num_of_teams 20

// -------------------------------------------------
// construtors and destructor
// -------------------------------------------------
League::League() : teams(std::vector<Team *>())
{
    for (size_t i = 0; i < num_of_teams; ++i)
    {
        std::string new_name = "Team " + std::to_string(i);
        Team *new_team = new Team(new_name, 0.5);
        teams.push_back(new_team);
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
// method implementaitons
// -------------------------------------------------
std::vector<Team *> League::get_teams() const
{
    return this->teams;
}

// -------------------------------------------------
// friend functions
// -------------------------------------------------
std::ostream &operator<<(std::ostream &out, const League &league)
{
    for (Team *team : league.teams)
    {
        out << team->get_name() << " ["
            << "Wins - " << team->wins << ", Losses - " << team->losses << "]" << std::endl;
    }

    return out;
}