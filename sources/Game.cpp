#include "Game.hpp"
#include <random>
#define max_skill_bonus 10
#define max_points 100
#define home_min 55
#define guest_min 50

// ---------------------------------------------------
// cosntructor and destructor
// ---------------------------------------------------
Game::Game(Team &home_team, Team &guest_team) : home_team(home_team), guest_team(guest_team), score(std::vector<int>(2)) {}

// ---------------------------------------------------
// method implementations
// ---------------------------------------------------
Team &Game::get_guest_team() { return this->guest_team; }

Team &Game::get_home_team() { return this->home_team; }

// play the game and return the winner
Team &Game::play()
{
    std::random_device rd;                             // obtain a random number from hardware
    std::mt19937 gen(rd());                            // seed the generator
    std::normal_distribution<> home_team_distr{80, 5}; // define the mean and standard deviation
    std::normal_distribution<> guest_team_distr{75, 5};

    // generate score
    int home_score = home_team_distr(gen);
    int guest_score = guest_team_distr(gen);

    // check if the score is too high for the assignments requrements
    if (home_score > max_points)
    {
        home_score = max_points;
    }
    else if (home_score < home_min)
    {
        home_score = home_min;
    }
    if (home_score > max_points)
    {
        home_score = max_points;
    }
    else if (home_score < guest_min)
    {
        home_score = guest_min;
    }

    /// add skill bonus
    home_score += max_skill_bonus * home_team.get_skill();
    guest_score += max_skill_bonus * guest_team.get_skill();

    // save scores
    this->score.at(0) = home_score;
    this->score.at(1) = guest_score;

    // return winner
    if (home_score >= guest_score)
    {
        home_team.wins++;
        guest_team.losses++;
        home_team.score_diff = home_score - guest_score;
        guest_team.score_diff = home_score - guest_score;
        return home_team;
    }

    guest_team.wins++;
    home_team.losses++;
    home_team.score_diff = guest_score - home_score;
    guest_team.score_diff = guest_score - home_score;
    return guest_team;
}