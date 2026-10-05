#pragma once

#include "stage.h"

class call_runs_stage : public stage {
public:
    call_runs_stage();

    stage_mode get_stage_mode() const override {
        return stage_mode::call_runs;
    }

    void on_enter(table *_table, std::vector<player*> &players, round_params *params) override;
    void on_exit(table *_table, std::vector<player*> &players, round_params *params) override;
};