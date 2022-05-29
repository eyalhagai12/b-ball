#include "Game.hpp"

#include <vector>

class League
{
private:
    std::vector<Team *> teams;

public:
    // construstor destructor
    League();
    League(std::vector<Team *> teams);
    ~League();

    // methods
    std::vector<Team *> get_teams() const;                   // get the teams

    // operator overloads
    friend std::ostream &operator<<(std::ostream &out, const League &league);
};
