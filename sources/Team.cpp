#include "Team.hpp"

// -----------------------------------------------------
// constructor and destructor
// -----------------------------------------------------
Team::Team(const std::string &name, float skill) : name(name),
                                                   skill(skill),
                                                   wins(0),
                                                   losses(0),
                                                   longest_win_streak(0),
                                                   longest_lose_streak(0),
                                                   w_count(0),
                                                   l_count(0),
                                                   scores(0),
                                                   got_scored(0)
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

void Team::add_scores(size_t score) { this->scores += score; }

void Team::add_scored(size_t score) { this->got_scored += score; }

size_t Team::get_wins() const { return wins; }

size_t Team::get_losses() const { return losses; }

int Team::get_score_diff() const { return (int)(this->scores - this->got_scored); }

size_t Team::get_win_streak() const { return longest_win_streak; }

size_t Team::get_lose_streak() const { return longest_lose_streak; }

size_t Team::get_scores() const { return scores; }

size_t Team::get_scored() const { return got_scored; }

// -----------------------------------------------------
// operator overloads
// -----------------------------------------------------
std::ostream &operator<<(std::ostream &out, const Team &team)
{
    out << "Name: " << team.get_name() << " [wins: " << team.get_wins() << ", losses: " << team.get_losses() << ", score difference: " << team.get_score_diff() << "]" << std::endl;

    return out;
}
