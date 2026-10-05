#include "card.h"
#include <string>

std::string print_card_col(card_col col) {
    switch (col) {
    case clubs:
        return "clubs";
    case spades:
        return "spades";
    case hearts:
        return "hearts";
    case diamonds:
        return "diamonds";
    }
    return "";
}

std::string print_card_col_short(card_col col) {
    switch (col) {
    case clubs:
        return "c";
    case spades:
        return "s";
    case hearts:
        return "h";
    case diamonds:
        return "d";
    }
    return "";
}

std::string print_card_val(card_val val) {
    switch (val) {
    case ace:
        return "ace";
    case king:
        return "king";
    case queen:
        return "queen";
    case jack:
        return "jack";
    case ten:
        return "10";
    case nine:
        return "9";
    case eight:
        return "8";
    case seven:
        return "7";
    }
    return "";
}

std::string print_card_val_short(card_val val) {
    switch (val) {
    case ace:
        return "a";
    case king:
        return "k";
    case queen:
        return "q";
    case jack:
        return "j";
    case ten:
        return "10";
    case nine:
        return "9";
    case eight:
        return "8";
    case seven:
        return "7";
    }
    return "";
}

card::card(card_col col, card_val val) {
    this->col = col;
    this->val = val;
}

card::card(card&& card) {
    col = card.col;
    val = card.val;
}

std::string card::get_card_name() const {
    return print_card_val(val) + "-" + print_card_col(col);
}

std::string card::get_card_name_short() const {
    return print_card_val_short(val) + "-" + print_card_col_short(col);
}

int card::get_worth() const {
    switch (this->val) {
    case ace:
        return 8;
    case king:
        return 7;
    case queen:
        return 6;
    case jack:
        return 5;
    case ten:
        return 4;
    case nine:
        return 3;
    case eight:
        return 2;
    case seven:
        return 1;
    default:
        return -1;
    }
}