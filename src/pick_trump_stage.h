#pragma once

#include "stage.h"

class pick_trump_stage : public stage {
private:
    unsigned int dealer_index;

public:
    pick_trump_stage();

    stage_mode get_stage_mode() const override {
        return stage_mode::pick_trump;
    }

    void on_enter(table *_table, std::vector<player*> &players, round_params *params) override;
    void on_exit(table *_table, std::vector<player*> &players, round_params *params) override;
};