#include "human_player.h"
#include "card.h"
#include "player.h"
#include <iostream>
#include <ostream>
#include <string>

human_player::human_player(std::string name) : player(name, true) {
}

std::string human_player::query_text(std::string text) const {
    std::cout << get_name() << ": " << text << "> ";

    std::string answer = "";
    std::getline(std::cin, answer);
    return answer;
}

bool human_player::query_yn(std::string question) const {
    auto answer = query_text(question + " (type y/n)");
    if (answer == "y") return true;
    else if (answer == "n") return false;
    else {
        std::cout << "Invalid answer -- type y/n only." << std::endl;
        return query_yn(question);
    }
}

const card* human_player::query_card(bool none_also_possible) const {
    show_hand_with_index();
    auto index_str = query_text("Choose card index from hand");
    if (index_str == "" && none_also_possible) // No card chosen
        return nullptr;

    int index = std::stoi(index_str);
    if (index < 0 || index > get_hand().size()) {
        std::cout << "Invalid index -- must be between 0 and " << std::to_string(get_hand().size()) << std::endl;
        return query_card();
    }
    return get_hand()[index];
}

bool human_player::pick_init_trump(card_col init_trump_col) const {
    return query_yn("Pick initial trump " + print_card_col(init_trump_col) + "?");
}

const card *human_player::pick_other_trump() const {
    return query_card(true);
}