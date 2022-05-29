#include "Season.hpp"

// -----------------------------------------
// constructor and destructor
// -----------------------------------------
Season::Season(League &league, Schedule &schedule) : league(league), schedule(schedule) {}

// -----------------------------------------
// method implementations
// -----------------------------------------
void Season::play_game()
{
    Game &game = schedule.get_current_game();
    Team &winner = game.play();
    schedule.next();
    std::cout << "Played -> " << game << "" << winner.get_name() << " is the winner!! " << std::endl
              << "Next Game -> " << schedule.get_current_game() << std::endl;
}

void Season::play_all_games()
{
    for (Game *game : schedule)
    {
        game->play();
        schedule.next();
    }

    for (Team *team : league)
    {
        std::cout << team->get_name() << " : "
                  << "wins - " << team->get_wins()
                  << ", losses - " << team->get_losses()
                  << " score difference - " << team->get_score_diff() << std::endl;
    }

    std::cout << "\nTop Teams: " << std::endl;
    long top_teams = 5;
    for (Team *team : league.get_top_teams(top_teams))
    {
        std::cout << team->get_name() << std::endl;
    }
}
