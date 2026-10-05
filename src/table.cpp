#include "table.h"
#include "deck.h"
#include <algorithm>
#include <array>

table::table() : _deck(new deck()), trump(nullptr), burn(nullptr) {
}

std::array<const card*, 6> table::draw_starting_hand() {
    auto drawn_cards = _deck->draw_cards(6);
    std::array<const card*, 6> starting_hand;
    std::copy_n(drawn_cards.begin(), 6, starting_hand.begin());
    return starting_hand;
}

void table::draw_trump() {
    trump = _deck->draw_card();
}

void table::draw_burn() {
    burn = _deck->draw_card();
}

int table::get_card_val(const card* c) const {
    if (c->get_col() == trump->get_col()) {
        switch (c->get_val()) {
        case ace:
            return 11;
        case king:
            return 4;
        case queen:
            return 3;
        case jack:
            return 20;
        case ten:
            return 10;
        case nine:
            return 14;
        case eight:
        case seven:
        default:
            return 0;
        }
    } else {
        switch (c->get_val()) {
        case ace:
            return 11;
        case king:
            return 4;
        case queen:
            return 3;
        case jack:
            return 2;
        case ten:
            return 10;
        case nine:
        case eight:
        case seven:
        default:
            return 0;
        }
    }
}