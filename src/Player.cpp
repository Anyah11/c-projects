#include "Player.hpp"
#include <iostream>

//Constructor for Player class
Player::Player(std::string playerName, float initialBalance) {
    PlayerName = playerName;  // Initialize player's name
    balance = initialBalance; // Set player's initial balance
}

// Method to set the player's name
std::string Player::EnterName(std::string playerName) {
    PlayerName = playerName;  // Assign the player's name
    return PlayerName;        // Return the player's name
}

// Method to display a welcome message
void Player::WelcomeMessage() const {
    std::cout << "Welcome " << PlayerName << "! You have ";
    std::cout << balance << " Zephy." << std::endl;
}

// Method to choose a spinner
std::string Player::ChooseSpinner(std::string Spinner) {
    SelectedSpinner = Spinner;  // Assign the chosen spinner
    return SelectedSpinner;    // Return the selected spinner
}

// Getter for balance
float Player::getBalance() const {
    return balance;  // Return player's current balance
}

// Setter for balance
void Player::setBalance(float new_balance) {
    balance = new_balance;  // Update player's balance
}
