#include "player.h"
#include "card.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

player::player(std::string name, bool public_cards) : name(name), public_cards(public_cards),
    hand(), tricks_won(), scored_points(0) {
}

int player::is_card_in_hand(const card *c) const {
    for (int i = 0; i < hand.size(); i++) {
        auto& curr_card = hand[i];
        if (curr_card->get_col() == c->get_col() && curr_card->get_val() == c->get_val()) {
            std::cout << "Duplicate card found: " << curr_card->get_card_name() << "." << std::endl;
            return i;
        }
    }
    return -1;
}

bool player::add_card(const card *c) {
    if (is_card_in_hand(c) != -1)
        return false;
    hand.push_back(c);
    return true;
}

bool player::add_cards(std::vector<const card*> cards) {
    bool duplicate = false;
    for (auto c : cards) {
        if (!add_card(c))
            duplicate = true;
    }
    sort_hand();
    return duplicate;
}

bool player::remove_card(const card *c) {
    int i = is_card_in_hand(c);
    if (i != -1) {
        hand.erase(hand.begin() + i);
    }
    return i != -1;
}

std::vector<std::array<const card*, 4>> player::find_fifties() const {
    throw;
}

std::vector<std::array<const card*, 3>> player::find_twenties() const {
    throw;
}

void player::reset_hand() {
    hand.clear();
}

void player::new_hand(std::array<const card*, 6>& _hand) {
    reset_hand();
    hand.insert(hand.begin(), _hand.begin(), _hand.end());
    sort_hand();
}

void player::win_trick(const card* first, const card* second) {
    tricks_won.push_back(first);
    tricks_won.push_back(second);
}

std::string player::print_hand() const {
    std::string hand_text = "";
    for (int i = 0; i < hand.size(); i++) {
        hand_text += hand[i]->get_card_name();
        if (i < hand.size() - 1)
            hand_text += ", ";
    }
    return hand_text;
}

std::string player::print_hand_with_index() const {
    std::string hand_text = "";
    for (int i = 0; i < hand.size(); i++) {
        hand_text += hand[i]->get_card_name() + " [" + std::to_string(i) + "]";
        if (i < hand.size() - 1)
            hand_text += ", ";
    }
    return hand_text;
}

void player::show_hand() const {
    if (!public_cards) {
        std::cout << "Player " << name << " has private hands, show_hand() call ignored." << std::endl;
        return;
    }
    std::cout << name << " hand: " << print_hand() << std::endl;
}

void player::show_hand_with_index() const {
    if (!public_cards) {
        std::cout << "Player " << name << " has private hands, show_hand() call ignored." << std::endl;
        return;
    }
    std::cout << name << " hand: " << print_hand_with_index() << std::endl;
}

bool comp_card_cols(const card *a, const card *b) {
    return a->get_col() > b->get_col() && a->get_val() > b->get_val();
}

void player::sort_hand() {
    std::sort(hand.begin(), hand.end(), comp_card_cols);
}

void player::reset() {
    hand.clear();
    tricks_won.clear();
}