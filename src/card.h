#pragma once

#include <string>
enum card_col : int {
  clubs = 0,
  spades = 1,
  hearts = 2,
  diamonds = 3
};

std::string print_card_col(card_col col);
std::string print_card_col_short(card_col col);

enum card_val : int {
    ace = 7,
    king = 6,
    queen = 5,
    jack = 4,
    ten = 3,
    nine = 2,
    eight = 1,
    seven = 0
};

std::string print_card_val(card_val val);
std::string print_card_val_short(card_val val);

class card {
private:
    card_col col;
    card_val val;

public:
    card(card_col col, card_val val);
    card(card&& card);

    std::string get_card_name() const;
    std::string get_card_name_short() const;

    int get_worth() const;

    card_col get_col() const {
        return col;
    }
    
    card_val get_val() const {
        return val;
    }
};