#pragma once

#include "deck.h"
#include <array>
#include <memory>

class table {
private:
    std::unique_ptr<deck> _deck;
    const card *trump, *burn;

public:
    table();
    std::array<const card*, 6> draw_starting_hand();
    void draw_trump();
    void draw_burn();

    deck *get_deck() const {
        return _deck.get();
    }

    const card *get_trump() const {
        return trump;
    }

    const card *get_burn() const {
        return burn;
    }

    int get_card_val(const card* c) const;
};