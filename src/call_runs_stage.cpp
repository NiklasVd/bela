#include "call_runs_stage.h"
#include "stage.h"

call_runs_stage::call_runs_stage() {
}

void call_runs_stage::on_enter(table *_table, std::vector<player*> &players, round_params *params) {
    transition_to = stage_mode::game;
}

void call_runs_stage::on_exit(table *_table, std::vector<player*> &players, round_params *params) {
}