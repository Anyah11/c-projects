#include "GameRules.hpp"
#include <iostream>

//Constructor implementation
Game_rules::Game_rules(const std::string& rules,
const std::map<int, float>& payout)
    : rules_text(rules), payout_table(payout) {}

// Method to display the game rules
void Game_rules::display_rules() const {
    std::cout << "Game Rules: " << std::endl;
    std::cout << rules_text << std::endl;
}

// Method to display the payout table
void Game_rules::display_payout() const {
    std::cout << "Payout Table: " <<
    std::endl;
    std::cout << "Player's Total |"
    "Payout (%) | If bet 20 Zephy, receives"
    << std::endl;
    std::cout << "------------------------"
    "--------------------------------" <<
    std::endl;
    for (const auto& entry : payout_table) {
    int total = entry.first;
    float payout = entry.second;
    std::cout << "Player's Total: " << total
    << " - Payout: " << payout * 100 << "%" << std::endl;
}
}

// // Loop through the payout table and print the basic output
// for (const auto& [total, payout] : payout_table) {
//     std::cout << "Player's Total: " << total <<
//     "- Payout: " << payout * 100 << "%" << std::endl;}
// }
