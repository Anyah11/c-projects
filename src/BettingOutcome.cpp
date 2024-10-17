#include "BettingOutcome.hpp"
#include <iostream>

//Constructor for the BettingOutcome class
BettingOutcome::BettingOutcome(int total_spins, int bet, float balance,
                               const Game_rules& rules, const Stakes& st)
    : total_spin_number(total_spins), bet_amount(bet),
      current_balance(balance), game_rules(rules), stakes(st) {}

// Method to check the outcome of the player's bet
bool BettingOutcome::check_outcome() const {
    // condition for spin number to be under 17
    return total_spin_number >= 10 && total_spin_number <= 17;
}

// Method to update the player's balance if they win or lose
void BettingOutcome::update_balance(bool is_winner) {
    if (is_winner) {
        //from game rules we use payout structure
        float payout_multiplier = game_rules.payout_table.at(total_spin_number);
        current_balance += bet_amount * payout_multiplier;
    } else {
        // Deduct the bet amount if the player loses
        current_balance -= bet_amount;
    }
}

// Method to display the final outcome
void BettingOutcome::display_outcome() const {
    std::cout << "Final Outcome: " << std::endl << std::endl;
    if (check_outcome()) {
        std::cout << "Congratulations! You won! :) " << std::endl;
    } else {
        std::cout << "Sorry, you lost :( " << std::endl;
    }
    std::cout << "Your current balance is: " << current_balance
              << " Zephy." << std::endl;
}
