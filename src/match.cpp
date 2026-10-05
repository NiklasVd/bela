#include "match.h"
#include "call_runs_stage.h"
#include "game_stage.h"
#include "human_player.h"
#include "npc_player.h"
#include "pick_trump_stage.h"
#include "stage.h"
#include "table.h"
#include <memory>

match::match()
    : _table(nullptr), players(), curr_round_params(), stages(), curr_stage(nullptr) {
}

void match::add_human_player(std::string name) {
    players.push_back(new human_player(name));
}

void match::add_npc_player(std::string name, unsigned int look_depth) {
    players.push_back(new npc_player(name, look_depth));
}

void match::set_stage(stage_mode new_mode) {
    if (curr_stage != nullptr)
        curr_stage->on_exit(_table.get(), players, curr_round_params.get());
    curr_stage = stages.at(new_mode);
    curr_stage->on_enter(_table.get(), players, curr_round_params.get());
    if (curr_stage->transition_to_next() != stage_mode::empty)
        set_stage(curr_stage->transition_to_next());
}

void match::start_match() {
    _table = std::unique_ptr<table>(new table());
    curr_round_params = std::unique_ptr<round_params>(new round_params);
    stages = {
        { stage_mode::pick_trump, new pick_trump_stage() },
        { stage_mode::call_runs, new call_runs_stage() },
        { stage_mode::game, new game_stage() },
        // { stage_mode::points, points_stage() }
    };
    curr_stage = nullptr;
    set_stage(stage_mode::pick_trump);
}