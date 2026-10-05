#pragma once

#include "player.h"
#include "table.h"
#include <vector>

struct round_params {
    unsigned int dealer {0};
    unsigned int trump_chooser {0};
    card_col trump_col {card_col::clubs};
};

enum stage_mode {
    pick_trump,
    call_runs,
    game,
    points,
    empty
};

class stage {
protected:
    stage_mode transition_to { stage_mode::empty };

public:
    stage() {}
    virtual stage_mode get_stage_mode() const = 0;

    stage_mode transition_to_next() const {
        return transition_to;
    }

    virtual void on_enter(table *_table, std::vector<player*> &players, round_params *params) = 0;
    virtual void on_exit(table *_table, std::vector<player*> &players, round_params *params) = 0;
};