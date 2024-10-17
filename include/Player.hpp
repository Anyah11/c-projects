#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

/**
 * @author Aayush patel 
 * @class Player
 * @brief A class to represent a player
 * 
 * This class stores player's name, balance, and thier chosen spinner.
 */
class Player {
 private:
    /**
     * @brief Name of player
     */
    std::string PlayerName;
    /**
     * @brief Balance of player
     */
    float balance;
    /**
     * @brief Spinner chosen by player
    */
    std::string SelectedSpinner;

 public:
/**
 * @brief constructor of player class
 * 
 * it sets player's name & gives starting balance
 * 
 * @param PlayerName the player's name
 * @param balance The starting balance which is 50 zephy
 */ 
  Player(std::string PlayerName, float balance = 50);


    /**
     * @brief Lets player enter thier name.
     * 
     * @param PlayerName player's name entered by player.
     * @return returns player's name.
     */
    std::string EnterName(std::string PlayerName);


    /**
     * @brief Shows greeting to player
     * 
     * it says " Welcome" and shows player's balance along with name
     */
    void WelcomeMessage() const;


    /**
     * @brief player chooses the spinner
     * 
     * @param SelectedSpinner The spinner selected by player
     * @return The spinner chosen by player
     */
    std::string ChooseSpinner(std::string SelectedSpinner);


    /**
     * @brief gets current balance of player.
     * @return player's balance
     */

    float getBalance() const;


     /**
     * @brief updates the player's balance
     * 
     * @param balance sets the new balance
     */
    void setBalance(float balance);
};

#endif
