#pragma once

#include "card.h"
#include <array>
#include <string>
#include <vector>

class player {
private:
    std::string name;
    bool public_cards;
    std::vector<const card*> hand;
    std::vector<const card*> tricks_won;
    unsigned int scored_points; // split up into categories (runs, belas, etc.)?

protected:
    player(std::string name, bool public_cards);
    // player(player&& p);

public:
    std::string get_name() const {
        return name;
    }

    virtual bool pick_init_trump(card_col init_trump_col) const = 0;
    virtual const card *pick_other_trump() const = 0;

    virtual std::vector<std::array<const card*, 4>> pick_fifties() const = 0;
    virtual std::vector<std::array<const card*, 3>> pick_twenties() const = 0;
    virtual const card* pick_attack() const = 0;
    virtual const card* pick_defense(const card* attack) const = 0;

    std::vector<std::array<const card*, 4>> find_fifties() const;
    std::vector<std::array<const card*, 3>> find_twenties() const;

    int is_card_in_hand(const card *c) const;
    bool add_card(const card *c);
    bool add_cards(std::vector<const card*> cards);
    bool remove_card(const card *c);

    void reset_hand();
    void new_hand(std::array<const card*, 6>& _hand);

    void win_trick(const card* first, const card* second);
    std::string print_hand() const;
    std::string print_hand_with_index() const;
    void show_hand() const;
    void show_hand_with_index() const;
    void sort_hand();

    const std::vector<const card*> get_hand() const {
        return hand;
    }

    void reset();
};