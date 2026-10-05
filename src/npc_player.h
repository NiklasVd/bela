#pragma once

#include "player.h"
#include <string>

class npc_player : public player {
private:
    unsigned int look_depth;

public:
    npc_player(std::string name, unsigned int look_depth);

    bool pick_init_trump(card_col init_trump_col) const override { return false; }
    const card *pick_other_trump() const override { return nullptr; }

    std::vector<std::array<const card *, 4>> pick_fifties() const override { return {}; }
    std::vector<std::array<const card *, 3>> pick_twenties() const override { return {}; }
    const card* pick_attack() const override { throw; }
    const card * pick_defense(const card *attack) const override { throw; }
};