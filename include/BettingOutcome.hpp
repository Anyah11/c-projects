#ifndef BETTING_OUTCOME_HPP_
#define BETTING_OUTCOME_HPP_

#include "Stakes.hpp"
#include "GameRules.hpp"

/**
 * @author Aayush patel
 * @class BettingOutcome
 * @brief Manages the outcome of a player's betting in the game.
 *
 * This class tracks the number of spins, the bet amount, and the player's
 * balance. It provides methods to check whether the player won or lost,
 * update the player's balance, and display the final outcome of the game.
 */
class BettingOutcome {
 private:
    /** 
     * @brief Total number of spins in the game.
     */
    int total_spin_number;


/** 
     * @brief player's current balance.
     */
    float current_balance;
    /** 
     * @brief Reference to game rules for payout calculations.
     */
    const Game_rules& game_rules;

    /** 
     * @brief Reference to stakes for bet amount and winning probability.
     */
    const Stakes& stakes;

 public:
 /** 
     * @brief bet amount placed by the player.
     */
     int bet_amount;
    /**
     * @brief Constructor for the BettingOutcome class.
     *
     * Initializes the number of spins, bet amount, player's balance, and requires
     * game rules and stakes to calculate the outcome.
     * 
     * @param total_spin_number The total number of spins in the game.
     * @param bet_amount The amount the player bet.
     * @param current_balance The player's current balance.
     * @param game_rules Reference to the game rules for payout calculation.
     * @param stakes Reference to the stakes for bet amount and winning probability.
     */
BettingOutcome(int total_spin_number, int bet_amount, float current_balance,
               const Game_rules& game_rules, const Stakes& stakes);

    /**
     * @brief Method to check the outcome of the player's bet.
     *
     * Determines if the player won the bet based on the game's rules.
     * 
     * @return true if the player won, otherwise false.
     */
    bool check_outcome() const;

    /**
     * @brief Updates the player's balance.
     *
     * If player won, their balance is updated accordingly.
     * 
     * @param is_winner Whether the player won the bet.
     */
    void update_balance(bool is_winner);

    /**
     * @brief Displays outcome of player's bet.
     *
     * Shows whether player won or lost and their updated balance.
     */
    void display_outcome() const;
    /**
     * @brief Gets the current balance after the betting round.
     * @return The updated player balance as a float.
     */
    float get_current_balance() const {
        return current_balance;
    }
};

#endif
