#include "Game.hpp"

#include <vector>
#include <algorithm>

class League
{
private:
    std::vector<Team *> teams;

public:
    // construstor destructor
    League();
    League(std::vector<Team *> teams);
    League(const League &other);
    League(League &&other) noexcept;
    ~League();

    // methods
    std::vector<Team *> get_top_teams(long n_teams); // get n top teams
    std::vector<Team *> get_teams() const;           // get the teams
    std::vector<Team *>::iterator begin();           // get the start of the iterator
    std::vector<Team *>::iterator end();             // get the end of the iterator

    // operator overloads
    friend std::ostream &operator<<(std::ostream &out, const League &league);
    League &operator=(const League &other);
    League &operator=(League &&other) noexcept;
};
