#include <iostream>
#include "Season.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    League league;
    Schedule sch(league);
    Season s(league, sch);
    s.play_all_games();
    return 0;
}
