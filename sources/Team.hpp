#include <iostream>

class Team
{
private:
    float skill;
    const std::string name;
    size_t wins;
    size_t losses;
    int score_diff;
    size_t longest_win_streak;
    size_t longest_lose_streak;
    size_t w_count;
    size_t l_count;

public:
    // public attributes

    // constructor and destructor
    Team(const std::string &name, float skill);
    ~Team() = default;

    // methods
    float get_skill() const;
    std::string get_name() const;
    void add_win();
    void add_loss();
    void add_to_diff(int diff);
    size_t get_wins();
    size_t get_losses();
    int get_score_diff();
    size_t get_win_streak();
    size_t get_lose_streak();
};
