#pragma once

#include "card.h"
#include "player.h"
#include <string>

class human_player : public player {
private:
    std::string query_text(std::string text) const;
    bool query_yn(std::string question) const;
    const card* query_card(bool none_also_possible = false) const;


public:
    human_player(std::string name);

    bool pick_init_trump(card_col init_trump_col) const override;
    const card *pick_other_trump() const override;

    std::vector<std::array<const card *, 4>> pick_fifties() const override { return {}; }
    std::vector<std::array<const card *, 3>> pick_twenties() const override { return {}; }

    const card * pick_attack() const override { return nullptr; }
    const card * pick_defense(const card *attack) const override { return nullptr; }
};