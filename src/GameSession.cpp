#include "GameSession.hpp"
#include "BettingOutcome.hpp"
#include <iostream>

//Constructor to initialize the game session with a starting balance
Game_session::Game_session(int balance)
    : current_balance(balance), is_continuing(true) {}

// Asks the player if they want to continue playing the game
bool Game_session::ask_to_continue() {
    char choice;
    std::cout << "Do you want to continue playing? (y/n): ";
    std::cin >> choice;

    // If the player chooses 'y', they will continue playing
    if (choice == 'y' || choice == 'Y') {
        is_continuing = true;
    } else if (choice == 'n' || choice == 'N') {
        is_continuing = false;
        exit_game();  // Call exit_game when they choose to stop
    } else {
        std::cout << "Invalid choice. Please enter 'y' or 'n'." << std::endl;
        return ask_to_continue();  // Recursively ask for valid input
    }
    return is_continuing;
}

// Exits the game session
void Game_session::exit_game() {
    std::cout << "Exiting the game..." << std::endl;
    is_continuing = false;  // Set is_continuing to false
}

// Displays the player's final balance
void Game_session::display_final_balance() const {
    std::cout << "Your final balance is: "
    << this->current_balance << " Zephy" << std::endl;
}
