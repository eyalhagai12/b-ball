#include <iostream>
#include <string>

#include "Season.hpp"

using namespace std;

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
               cout << "Played: " << season.get_schedule().get_current_game();
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
