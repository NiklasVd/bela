#include "deck.h"
#include <cstdlib>
#include <ctime>
#include <utility>
#include <vector>

deck::deck() : cards({{
        card(card_col::clubs, card_val::seven),
        card(card_col::clubs, card_val::eight),
        card(card_col::clubs, card_val::nine),
        card(card_col::clubs, card_val::ten),
        card(card_col::clubs, card_val::jack),
        card(card_col::clubs, card_val::queen),
        card(card_col::clubs, card_val::king),
        card(card_col::clubs, card_val::ace),

        card(card_col::spades, card_val::seven),
        card(card_col::spades, card_val::eight),
        card(card_col::spades, card_val::nine),
        card(card_col::spades, card_val::ten),
        card(card_col::spades, card_val::jack),
        card(card_col::spades, card_val::queen),
        card(card_col::spades, card_val::king),
        card(card_col::spades, card_val::ace),

        card(card_col::hearts, card_val::seven),
        card(card_col::hearts, card_val::eight),
        card(card_col::hearts, card_val::nine),
        card(card_col::hearts, card_val::ten),
        card(card_col::hearts, card_val::jack),
        card(card_col::hearts, card_val::queen),
        card(card_col::hearts, card_val::king),
        card(card_col::hearts, card_val::ace),

        card(card_col::diamonds, card_val::seven),
        card(card_col::diamonds, card_val::eight),
        card(card_col::diamonds, card_val::nine),
        card(card_col::diamonds, card_val::ten),
        card(card_col::diamonds, card_val::jack),
        card(card_col::diamonds, card_val::queen),
        card(card_col::diamonds, card_val::king),
        card(card_col::diamonds, card_val::ace)
    }}), shuffled_cards() {
    shuffle();
}

void deck::reset() {
    // Repopulate shuffled deck with all cards (after restarting game, as
    // cards will have been drawn, so shuffled_cards.size() < 32)
    shuffled_cards = {{
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
        31
    }};
}

void deck::shuffle() {
    reset();
    srand(time(0));
    // Swap places of card indices randomly to shuffle.
    for (int i = 0; i < 32; i++) {
        int new_idx = rand() % 31;
        std::swap(shuffled_cards[i], shuffled_cards[new_idx]);
    }
}

const card* deck::draw_card() {
    auto c = &cards[shuffled_cards.back()];
    shuffled_cards.pop_back();
    return c;
}

std::vector<const card*> deck::draw_cards(unsigned int count) {
    if (shuffled_cards.size() < count)
        return {};
    std::vector<const card*> drawn_cards;
    for (int i = 0; i < count; i++) {
        drawn_cards.push_back(draw_card());
    }
    return drawn_cards;
}