/**
 * @author Kamesh Patel
 * @class Game_session 
 * @brief Manages the lifecycle of a game session for a player.
 * 
 * The Game_session class tracks the player's current balance, handles the decision to 
 * continue or exit the game, and displays the player's final balance when the session ends.
 */

#ifndef GAME_SESSION_H
#define GAME_SESSION_H

/**
 * @brief Class that represents a player's game session.
 */
class Game_session {
 private:
    bool is_continuing;
    /**
     * @brief Stores the player's current balance in the session.
     */
    float current_balance;

 public:
    /**
     * @brief Constructor to initialize the game session with a starting balance.
     * 
     * @param balance The player's initial balance.
     */
    Game_session(int balance);

    /**
     * @brief Asks the player if they want to continue playing the game.
     * 
     * @return `true` if the player chooses to continue, otherwise `false`.
     */
    bool ask_to_continue();

    /**
     * @brief Exits the game session.
     * 
     * Ends the session by stopping the game and preventing further continuation.
     */
    void exit_game();

    /**
     * @brief Displays the player's final balance.
     * 
     * Outputs the player's balance at the end of the game session to the console.
     */
    void display_final_balance() const;
    /**
     * @brief Returns the player's current balance in the game session.
     * @return The player's current balance.
     */
        int get_balance() const {
        return current_balance;
    }
    /**
     * @brief Checks if the game session is still ongoing.
     * @return True if the game session is continuing, false otherwise.
     */
    bool is_continuing_game() const {
        return is_continuing;
    }
};

#endif // GAME_SESSION_H
