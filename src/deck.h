#pragma once

#include "card.h"
#include <array>
#include <vector>

const unsigned int BELA_DECK_SIZE = 32;

class deck {
private:
    // Instances of all playing cards
    std::array<card, BELA_DECK_SIZE> cards;
    // Actual positions of all cards in the deck
    std::vector<unsigned int> shuffled_cards;

public:
    deck();

    void reset();
    void shuffle();
    
    const card* get_card(unsigned int i) const {
        return &cards[shuffled_cards[i]];
    }

    const card* get_topmost_card() const {
        return get_card(0);
    }

    const card* draw_card();
    std::vector<const card*> draw_cards(unsigned int count);
};