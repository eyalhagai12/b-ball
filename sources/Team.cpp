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
float Team::get_skill() const { return this->skill; }

std::string Team::get_name() const { return this->name; }

void Team::add_win() { wins++; }

void Team::add_loss() { losses++; }

void Team::add_to_diff(int diff) { score_diff += diff; }

size_t Team::get_wins() { return wins; }

size_t Team::get_losses() { return losses; }

int Team::get_score_diff() { return score_diff; }