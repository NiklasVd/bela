#pragma once

#include "stage.h"

class game_stage : public stage {
public:
    game_stage() {}
    
    stage_mode get_stage_mode() const override {
        return stage_mode::game;
    }

    void on_enter(table *_table, std::vector<player*> &players, round_params *params) override;
    void on_exit(table *_table, std::vector<player*> &players, round_params *params) override;
};