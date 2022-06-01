#include <iostream>

class Team
{
private:
    float skill;
    const std::string name;
    size_t wins;
    size_t losses;
    size_t longest_win_streak;
    size_t longest_lose_streak;
    size_t w_count;
    size_t l_count;
    size_t scores;
    size_t got_scored;

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
    void add_scores(size_t score);
    void add_scored(size_t score);
    size_t get_wins() const;
    size_t get_losses() const;
    int get_score_diff() const;
    size_t get_win_streak() const;
    size_t get_lose_streak() const;
    size_t get_scores() const;
    size_t get_scored() const;

    // operator overload
    friend std::ostream &operator<<(std::ostream &out, const Team &team);
};
