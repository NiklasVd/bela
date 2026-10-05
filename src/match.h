#pragma once

#include "player.h"
#include "stage.h"
#include "table.h"
#include <map>
#include <memory>
#include <string>
#include <vector>

class match {
private:
    std::unique_ptr<table> _table;
    std::vector<player*> players;
    std::unique_ptr<round_params> curr_round_params;
    
    std::map<stage_mode, stage*> stages;
    stage *curr_stage;

    void set_stage(stage_mode new_mode);

public:
    match();

    void add_human_player(std::string name);
    void add_npc_player(std::string name, unsigned int look_depth);

    void start_match();
};