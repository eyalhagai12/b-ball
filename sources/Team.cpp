#include "Team.hpp"

// -----------------------------------------------------
// constructor and destructor
// -----------------------------------------------------
Team::Team(const std::string &name, float skill) : name(name),
                                                   skill(skill),
                                                   wins(0),
                                                   losses(0),
                                                   score_diff(0)
{
}

// -----------------------------------------------------
// method implementations
// -----------------------------------------------------
float Team::get_skill() const
{
    return this->skill;
}

std::string Team::get_name() const
{
    return this->name;
}