#include "Team.hpp"

// -----------------------------------------------------
// constructor and destructor
// -----------------------------------------------------
Team::Team(const std::string &name, float skill) : name(name),
                                                   skill(skill),
                                                   wins(0),
                                                   losses(0),
                                                   score_diff(0),
                                                   longest_win_streak(0),
                                                   longest_lose_streak(0),
                                                   w_count(0),
                                                   l_count(0)
{
}

// -----------------------------------------------------
// method implementations
// -----------------------------------------------------
float Team::get_skill() const { return this->skill; }

std::string Team::get_name() const { return this->name; }

void Team::add_win()
{
    wins++;
    w_count++;
    l_count = 0;
    if (w_count > longest_win_streak)
    {
        longest_win_streak = w_count;
    }
}

void Team::add_loss()
{
    losses++;
    l_count++;
    w_count = 0;
    if (l_count > longest_lose_streak)
    {
        longest_lose_streak = l_count;
    }
}

void Team::add_to_diff(int diff) { score_diff += diff; }

size_t Team::get_wins() { return wins; }

size_t Team::get_losses() { return losses; }

int Team::get_score_diff() { return score_diff; }

size_t Team::get_win_streak() { return longest_win_streak; }

size_t Team::get_lose_streak() { return longest_lose_streak; }