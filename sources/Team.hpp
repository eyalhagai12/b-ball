#include <iostream>

class Team
{
private:
    float skill;
    const std::string &name;

public:
    // public attributes 
    size_t wins;
    size_t losses;
    int score_diff;

    // constructor and destructor
    Team(const std::string &name, float skill);
    ~Team() = default;

    // methods
    float get_skill() const;
    std::string get_name() const;
};
