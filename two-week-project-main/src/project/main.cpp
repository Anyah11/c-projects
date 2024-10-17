#include "Player.hpp"
#include "GameSession.hpp"
#include "BettingOutcome.hpp"
#include "Spinner.hpp"
#include "Stakes.hpp"
#include "GameRules.hpp"
#include <limits>
#include <iostream>
#include <string>
#include <map>


int main() {
    // Step 1: Initialize game rules and payout table
    std::string rules = "\n\nObjective: "
                        "Get as close to 17 as possible without going over.\n"
                        "\n"
                        "Components: \n"
                        "Two spinners:\n"
                        "low spinner (produces numbers 2-5).\n"
                        "high spinner (produces numbers 0-7).\n"
                        "\n"
                        "Currency: Zephy (1 Zephy = $6 CAD).\n"
                        "\n"
                        "Bets: \n"
                        "Low Stakes: 5 Zephy \n"
                        "Medium Stakes: 25 Zephy \n"
                        "High Stakes: 50 Zephy\n";

    // Payout table mapping outcomes to payout multipliers
    std::map<int, float> payout_table = {
        {12, 0.25f},   // Outcome 12 gives a 25% payout
        {13, 0.50f},   // Outcome 13 gives a 50% payout
        {14, 1.00f},   // Outcome 14 gives a 100% payout
        {15, 1.25f},   // Outcome 15 gives a 125% payout
        {16, 1.50f},   // Outcome 16 gives a 150% payout
        {17, 2.00f}    // Outcome 17 gives a 200% payout
    };

    // Create game rules object
    Game_rules game_rules(rules, payout_table);

    // Display game rules and payout table
    game_rules.display_rules();
    game_rules.display_payout();

    //Step 2: Get player's name and balance, then create Player object
    std::string player_name;
    std::cout << "\n\nEnter your name: ";
    std::getline(std::cin, player_name);
    std::cout << std::endl;

    Player player(player_name);
    player.WelcomeMessage();

    // Step 3: Initialize the game session with the player's balance
    Game_session session(static_cast<int>(player.getBalance()));

    // Step 4: Game loop (the player plays until they decide to quit)
            while (session.is_continuing_game()) {
            // Player chooses stakes
            if (player.getBalance() < 5) {
            std::cout << "Insufficient balance to play.\n";
            std::cout << "Please add more Zephy.\n";
            break; // End the game if the balance is too low
            }
            int choice = 0;
            std::cout << "you can the choose the following options: \n";
            std::cout << "\nChooose Option: \n";
            std::cout << "1. Show rules again\n";
            std::cout << "2. Show payout system again\n";
            std::cout << "3. choose stakes & spinner\n";
            std::cout << "4. Exit game \noption: ";
            std::cin >> choice;

            switch (choice) {
            case 1: {
            //show rules
            std::cout << "\nDisplaying Game rules \n";
            game_rules.display_rules();
            break;
            }

            case 2: {
                std::cout << "\nDisplaying Payout: \n";
                game_rules.display_payout();
                break;
            }

            case 3: {
            std::string stake_choice;
            std::cout << "\nChoose your stakes:\n\n1.";
            std::cout << "Low (5 Zephy)\n2.";
            std::cout << "Medium (25 Zephy)\n3.";
            std::cout << "High (50 Zephy)\nChoice: ";
            std::cin >> stake_choice;
            std::cout << std::endl;

            Stakes* selected_stake = nullptr;
            int stake_amount = 0;

            if (stake_choice == "1") {
            stake_amount = 5;
            selected_stake = new LowStakes();
            } else if (stake_choice == "2") {
            stake_amount = 25;
            selected_stake = new MediumStakes();
            } else if (stake_choice == "3") {
            stake_amount = 50;
            selected_stake = new HighStakes();
            } else {
            std::cout << "Invalid choice" << std::endl << std::endl;
            continue;
            }

            if (stake_amount > player.getBalance()) {
            std::cout << "You do not have enough balance to place this bet.\n";
            std::cout<< "Please choose a lower stake.\n";
            delete selected_stake; // Clean up memory
            continue; // Retry stake selection
            }


            Spinner* selected_spinner = nullptr;
            int total_spin_value = 0;
            char continue_spinning = 'y';



            do {
            // Player selects a spinner
            std::string spinner_choice;
            std::cout << "\nChoose a spinner:";
            std::cout << "\n(low(2-5) or high(0-7) or stop): ";
            std::cin >> spinner_choice;

            // Validate spinner choice
            if (spinner_choice == "low") {
            selected_spinner = new LowRangeSpinner();
            } else if (spinner_choice == "high") {
            selected_spinner = new HighRangeSpinner();
            }  else if (spinner_choice == "stop") {
                std::cout << "Stopping... \ncalculating your payout...";
                break;
            } else {
            std::cout << "Invalid spinner choice!\n";
            std::cout << " Please enter 'low' or 'high'." << std::endl;

            // Clear error flags and flush the input buffer
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
            }

            // Spin the spinner and accumulate spin value
            int spin_result = selected_spinner->spin();
            total_spin_value += spin_result;
            std::cout << "\nYou spun: (" << spin_result;
            std::cout << ")\nTotal so far: [" << total_spin_value << "]\n\n";

            // Stop if the total spin value is greater than or equal to 17
            if (total_spin_value >= 17) {
            std::cout << "You reached or exceeded 17!" << std::endl;
            break;  // Exit the loop
            }

            // Ask if the player wants to spin again
            while (true) {
            std::cout << "Do you want to spin again? (y/n): ";
            std::cin >> continue_spinning;
            continue_spinning = std::tolower(continue_spinning);

            // Validate continue_spinning input
            if (continue_spinning == 'y' || continue_spinning == 'n') {
            break;  // Valid input, break out of the inner loop
            } else {
            std::cout << "Invalid input! Please enter 'y'";
            std::cout << " for yes or 'n' for no." << std::endl;

            // Clear error flags and flush the input buffer
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            }
            } while (total_spin_value < 17 && continue_spinning == 'y');

            // Create BettingOutcome object and calculate result
            BettingOutcome outcome(total_spin_value,
            selected_stake->GetBetAmount(),
            player.getBalance(), game_rules, *selected_stake);
            bool is_winner = outcome.check_outcome();
            outcome.update_balance(is_winner);
            player.setBalance(outcome.get_current_balance());

            if (player.getBalance() < 0) {
            std::cout << "Your balance cannot go below zero.";
            std::cout << " Ending game." << std::endl;
            break;
            }

            outcome.display_outcome();

            // Update player's balance after each round
            player.setBalance(outcome.get_current_balance());

            // Ask player if they want to continue playing
            if (!session.ask_to_continue()) {
            std::cout << "Your final balance is: ";
            std:: cout << outcome.get_current_balance();
            std::cout << " Zephy" << std::endl;
            }

            // Clean up memory
            delete selected_stake;
            delete selected_spinner;
            break;
            }
            case 4: {
                std::cout << "Thank you for playing!\n";
                std::cout << "Your final balance is: " << player.getBalance();
                std::cout << " Zephy\n";

                // End the session and display the final balance
                session.exit_game();
                return 0;
            }



            default: {
                std::cout << "Invalid option. Please choose again.\n";
                break;
            }
        }
    }

    return 0;
}

