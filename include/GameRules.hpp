/**
 * @author Kamesh Patel
 * @class Game_rules 
 * @brief The Game_rules class encapsulates the rules and payout structure for a game.
 * 
 * This class stores the game's rules as a text string and maintains a payout table, 
 * which maps player outcomes (totals) to their respective payout percentages.
 * The class provides methods to display the game rules and the payout table for players.
 */

#ifndef GAME_RULES_H
#define GAME_RULES_H

#include <string>
#include <map>

/**
 * @brief Class that represents the game rules and payout structure.
 */
class Game_rules {
 private:
    std::string rules_text;
//  protected:

 public:
    //     std::map<int, float> payout_table;
    // Did public because of the BettingOutcome class error
    // @date :- 08-10-2024 Ramya Patel
    /**
     * @brief map for payout table
     */
     std::map<int, float> payout_table;
     /**
     * @brief Constructor to initialize the game rules and payout table.ss
     * 
     * @param rules The rules of the game as a string.
     * @param payout A map where the key is the player's total, and the value is the payout percentage.
     */
    Game_rules(const std::string& rules, const std::map<int, float>& payout);

    /**
     * @brief Displays the game rules.
     * 
     * Outputs the game's rules to the console.
     */
    void display_rules() const;

    /**
     * @brief Displays the payout table.
     * 
     * Outputs the payout table to the console, including player totals, payout percentages, 
     * and an example payout for a 20 Zephy bet.
     */
    void display_payout() const;
};

#endif // GAME_RULES_H

