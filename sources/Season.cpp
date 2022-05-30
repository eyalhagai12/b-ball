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
}

std::vector<Team *> Season::get_top_teams(long n_teams) const
{
    return league.get_top_teams(n_teams);
}

size_t Season::n_positive_diff_teams() const
{
    size_t counter = 0;
    for (Team *team : league)
    {
        if (team->get_score_diff() > 0)
        {
            counter += 1;
        }
    }

    return counter;
}

std::pair<Team *, size_t> Season::longet_win_streak() const
{
    Team *max = league.get_teams().at(0);
    for (Team *team : league)
    {
        if (team->get_win_streak() > max->get_win_streak())
        {
            max = team;
        }
    }

    return std::pair<Team *, size_t>(max, max->get_win_streak());
}

std::pair<Team *, size_t> Season::longet_loss_streak() const
{
    Team *max = league.get_teams().at(0);
    for (Team *team : league)
    {
        if (team->get_lose_streak() > max->get_lose_streak())
        {
            max = team;
        }
    }

    return std::pair<Team *, size_t>(max, max->get_lose_streak());
}