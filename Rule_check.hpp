#ifndef RULE_CHECK_HPP
#define RULE_CHECK_HPP

#include "base_widget.hpp"
class Rule_check
{
    protected:
        vector<vector<Number>> grid_v;
    public:
        Rule_check(vector<vector<Number>>);
        bool row_check();
        bool column_check();
        bool square_check();
        bool completion_check();
        void update(vector<vector<Number>> v);
};

#endif // RULE_CHECK_HPP
