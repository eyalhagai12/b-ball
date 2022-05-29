#pragma once
#include "Schedule.hpp"

class Season
{
private:
    League league;
    Schedule schedule;

public:
    // constructors and destructor
    Season();
    Season(std::vector<Team *> teams);
    ~Season() = default;
};
