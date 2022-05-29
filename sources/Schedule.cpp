#include "Schedule.hpp"

//------------------------------------------------------
// constructor and destructor
//------------------------------------------------------
Schedule::Schedule(League &league) : league(league), idx(0)
{
    std::vector<Team *> teams = this->league.get_teams();

    for (size_t i = 0; i < teams.size(); ++i)
    {
        for (size_t j = 0; j < teams.size(); ++j)
        {
            if (i != j)
            {
                Game *game = new Game(*teams.at(i), *teams.at(j));
                this->games.push_back(game);
            }
        }
    }
}

Schedule::~Schedule()
{
    for (Game *game : this->games)
    {
        delete game;
    }
}

//------------------------------------------------------
// friend functions
//------------------------------------------------------
std::ostream &operator<<(std::ostream &out, const Schedule &schedule)
{
    for (Game *game : schedule.games)
    {
        out << "Game: " << game->get_home_team().get_name() << " VS " << game->get_guest_team().get_name() << std::endl;
    }
    return out;
}