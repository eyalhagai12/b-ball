#include <iostream>
#include <string>

#include "Season.hpp"

using namespace std;

/**
 * @brief Get the teams from the user
 *
 * @return vector<Team *> with the teams from the user
 */
vector<Team *> get_teams()
{
     vector<Team *> teams;
     string name = "";
     float skill = 0;
     do
     {
          // get team data
          cout << "Enter new team name: ";
          cin.ignore();
          getline(cin, name);
          if (name == "")
          {
               break;
          }

          cout << "Enter new teams skill (0 < value <= 1): ";
          cin >> skill;
          if (skill > 1 || skill <= 0)
          {
               cout << "Invalid skill value!" << endl;
               exit(1);
          }

          // construct team
          Team *new_team = new Team(name, skill);
          teams.push_back(new_team);
     } while (true);

     return teams;
}

/**
 * @brief the main program where we can play the games and see the statistics
 *
 * @param season the Season object that hold all the information about the teams and games
 */
void start_season(Season &season)
{
     bool played = false;
     bool done = false;
     cout << "Welcome, here are the teams: " << endl
          << season.get_league() << endl;
     cout << "Games are in a random shuffeld order, you may do the following actions: " << endl
          << "1. play all games (or all games that are left)" << endl
          << "2. play the next game in the queue" << endl
          << "3. play a a certain number of games (you choose how many of the next games to play)" << endl
          << "4. see how many games are left" << endl;

     do
     {
          int opt;
          cin >> opt;
          switch (opt)
          {
          case 1:
          {
               if (!played)
               {
                    season.play_all_games();
               }
               else
               {
                    season.play_rest();
               }
               done = true;
               break;
          }
          case 2:
          {
               Game &current_game = season.get_schedule().get_current_game();
               season.play_game();
               played = true;
               if (season.get_schedule().get_games_left() <= 0)
               {
                    done = true;
               }
               break;
          }
          case 3:
          {
               size_t games_left = season.get_schedule().get_games_left();
               size_t n_games;
               cout << "Enter how many games you want to play (" << games_left << " games left)" << endl;
               cin >> n_games;
               season.play_games(n_games);
               played = true;
               cout << "Played " << n_games << " games" << endl;

               if (season.get_schedule().get_games_left() <= 0)
               {
                    done = true;
               }
               break;
          }
          case 4:
          {
               cout << "Games left: " << season.get_schedule().get_games_left() << endl;
               break;
          }

          default:
               cout << "Invalid option!" << endl;
               exit(1);
               break;
          }
     } while (!done);

     cout << "All games are done: " << endl
          << season.get_league() << endl;

     cout << "you may now see statistics on all the games:" << endl
          << "1. show top teams (you decide the number of teams)" << endl
          << "2. get the number of teams who scored more than they got scored" << endl
          << "3. show the team with longest win streak" << endl
          << "4. show the team with longest lose streak" << endl
          << "5. get the team that scored the most" << endl
          << "6. get the team that got scored the most" << endl
          << "7. exit" << endl;

     done = false;
     do
     {
          cout << "Enter a command index: ";
          int opt;
          cin >> opt;
          switch (opt)
          {
          case 1:
          {
               long n_teams;
               cout << "Enter number of teams: ";
               cin >> n_teams;
               vector<Team *> top_teams = season.get_top_teams(n_teams);

               for (Team *team : top_teams)
               {
                    cout << (*team);
               }
               break;
          }
          case 2:
          {
               size_t n_teams = season.n_positive_diff_teams();
               cout << n_teams << " teams have scored more than they got scored" << endl;
               break;
          }
          case 3:
          {
               auto longest_win_team = season.longet_win_streak();
               cout << "The team "
                    << "'" << longest_win_team.first->get_name() << "'"
                    << " has a won " << longest_win_team.second << " games in a row, more than any other team!" << endl;
               break;
          }
          case 4:
          {
               auto longest_lose_team = season.longet_loss_streak();
               cout << "The team "
                    << "'" << longest_lose_team.first->get_name() << "'"
                    << " has a lost " << longest_lose_team.second << " games in a row, more than any other team!" << endl;
               break;
          }
          case 5:
          {
               Team &team = season.top_scores();
               cout << "The team "
                    << "'" << team.get_name() << "'"
                    << " has scored " << team.get_scores() << " points, more than any other team!" << endl;
               break;
          }
          case 6:
          {
               Team &team = season.top_scored();
               cout << "The team "
                    << "'" << team.get_name() << "'"
                    << " got scored " << team.get_scored() << " points, more than any other team!" << endl;
               break;
          }
          case 7:
          {
               done = true;
               break;
          }

          default:
               cout << "Invalid option" << endl;
               exit(1);
               break;
          }
          cout << endl;
     } while (!done);

     cout << "Goodbye!" << endl;
}

int main(int argc, char const *argv[])
{
     cout << "Welcome!" << endl
          << "Would you like to create some teams or let the system create teams for you?" << endl
          << "1. create teams (up to 20 teams, the system will complete to 20 if less teams were created)" << endl
          << "2. random teams" << endl;

     int opt;
     cin >> opt;

     switch (opt)
     {
     case 1:
     {
          // get teams from user
          vector<Team *> teams = get_teams();
          if (teams.size() > 20)
          {
               cout << "Too many teams!" << endl;
               exit(1);
          }

          // create game season
          League league(teams);
          Schedule schedule(league);
          Season season(league, schedule);
          start_season(season);
          break;
     }
     case 2:
     {
          // create game season
          League league;
          Schedule schedule(league);
          Season season(league, schedule);
          start_season(season);
          break;
     }
     default:
     {
          cout << "Invalid Input" << endl;
          exit(1);
          break;
     }
     }
}
