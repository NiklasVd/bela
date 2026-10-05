#include "pick_trump_stage.h"
#include "card.h"
#include "stage.h"
#include <iostream>
#include <ostream>
#include <vector>

pick_trump_stage::pick_trump_stage() : dealer_index(0) {
}

void pick_trump_stage::on_enter(table *_table, std::vector<player*> &players, round_params *params) {
    std::cout << std::endl << "New round:" << std::endl;
    _table->get_deck()->shuffle();
    // Rotate through players to pick next dealer
    params->dealer = (dealer_index + 1) % players.size();
    auto dealer = players[dealer_index];
    // Deal out cards
    for (auto p : players) {
        auto new_hand = _table->draw_starting_hand();
        p->new_hand(new_hand);
        p->show_hand();
    }

    // Choose trump
    // First let player next to dealer decide, then dealer
    _table->draw_trump();
    auto trump_col = _table->get_trump()->get_col();
    std::cout << "Initial trump: " << _table->get_trump()->get_card_name() << "." << std::endl;

    int forehand_index = (dealer_index + 1) % players.size();
    auto forehand = players[forehand_index];
    bool forehand_chose_init_trump = forehand->pick_init_trump(trump_col);
    if (!forehand_chose_init_trump) {
        bool dealer_chose_init_trump = dealer->pick_init_trump(trump_col);
        if (!dealer_chose_init_trump) {
            auto forehand_chose_other_trump = forehand->pick_other_trump();
            if (!forehand_chose_other_trump) {
                auto dealer_chose_other_trump = dealer->pick_other_trump();
                if (!dealer_chose_other_trump) {
                    transition_to = stage_mode::pick_trump;
                    return;
                } else {
                    params->trump_chooser = dealer_index;
                    trump_col = dealer_chose_other_trump->get_col();
                    std::cout << "Dealer chose trump " << print_card_col(trump_col) << "." << std::endl;
                }
            } else {
                params->trump_chooser = forehand_index;
                trump_col = forehand_chose_other_trump->get_col();
                std::cout << "Forehand chose trump " << print_card_col(trump_col) << "." << std::endl;
            }
        } else {
            std::cout << "Dealer chose initial trump." << std::endl;
        }
    } else {
        std::cout << "Forehand chose initial trump." << std::endl;
    }

    params->trump_col = trump_col;
    // Either first player or dealer chose trump, continue
    for (auto p : players) {
        auto extra_cards = _table->get_deck()->draw_cards(3);
        p->add_cards(extra_cards);
        p->show_hand();
    }

    // reveal burn card
    _table->draw_burn();
    std::cout << "Burn card: " << _table->get_burn()->get_card_name() << "." << std::endl;

    // next stage: look for runs and continue
    transition_to = stage_mode::call_runs;
}

void pick_trump_stage::on_exit(table *_table, std::vector<player*> &players, round_params *params) {
}