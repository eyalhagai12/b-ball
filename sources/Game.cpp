#include "Game.hpp"
#include <random>

// parameters
const size_t max_skill_bonus = 10;
const size_t max_points = 100;
const size_t home_min = 55;
const size_t guest_min = 50;
const size_t home_mean = 80;
const size_t guest_mean = home_mean - 5;
const size_t standard_deviation = 10;

// ---------------------------------------------------
// cosntructor and destructor
// ---------------------------------------------------
Game::Game(Team &home_team, Team &guest_team) : home_team(home_team), guest_team(guest_team), score(std::vector<int>(2)) {}

// ---------------------------------------------------
// util functions
// ---------------------------------------------------
void corrent_scores(size_t &score, const size_t &min, const size_t &max)
{
    if (score > max)
    {
        score = max;
    }
    else if (score < min)
    {
        score = min;
    }
}

// ---------------------------------------------------
// method implementations
// ---------------------------------------------------
Team &Game::get_guest_team() { return this->guest_team; }

Team &Game::get_home_team() { return this->home_team; }

std::vector<int> Game::get_score() { return this->score; }

// play the game and return the winner
Team &Game::play()
{
    std::random_device rd;                                                     // obtain a random number from hardware
    std::mt19937 gen(rd());                                                    // seed the generator
    std::normal_distribution<> home_team_distr{home_mean, standard_deviation}; // define the mean and standard deviation
    std::normal_distribution<> guest_team_distr{guest_mean, standard_deviation};

    // generate score
    size_t home_score = home_team_distr(gen);
    size_t guest_score = guest_team_distr(gen);

    // check if the score is too high for the assignments requrements
    corrent_scores(home_score, home_min, max_points);
    corrent_scores(guest_score, guest_min, max_points);

    /// add skill bonus
    home_score += max_skill_bonus * home_team.get_skill();
    guest_score += max_skill_bonus * guest_team.get_skill();

    // save scores
    this->score.at(0) = home_score;
    this->score.at(1) = guest_score;

    home_team.add_scores(home_score);
    home_team.add_scored(guest_score);
    guest_team.add_scores(guest_score);
    guest_team.add_scored(home_score);

    // return winner
    if (home_score >= guest_score)
    {
        home_team.add_win();
        guest_team.add_loss();
        return home_team;
    }

    guest_team.add_win();
    home_team.add_loss();
    return guest_team;
}

// ---------------------------------------------------
// operator overloads
// ---------------------------------------------------
std::ostream &operator<<(std::ostream &out, const Game &game)
{
    out << game.home_team.get_name() << " VS " << game.guest_team.get_name()
        << ", Score - "
        << "[" << game.score.at(0) << ", "
        << game.score.at(1) << "]"
        << std::endl;
    return out;
}