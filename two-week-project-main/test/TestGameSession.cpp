#include "GameSession.hpp"
#include <gtest/gtest.h>
#include <sstream>

//Test Constructor for GameSession
TEST(GameSessionTest, ConstructorTest) {
    Game_session session(1000);  // Initialize with balance 1000
    EXPECT_EQ(session.get_balance(), 1000);  // Check if the balance is correct
    EXPECT_TRUE(session.is_continuing_game());
    // Check if game is continuing by default
}

// Test asking to continue when player inputs 'y'
TEST(GameSessionTest, AskToContinueYesTest) {
    Game_session session(1000);  // Initialize with balance 1000

    // Simulate user input 'y'
    std::istringstream input("y\n");
    std::cin.rdbuf(input.rdbuf());
    // Redirect std::cin to use the simulated input

    bool result = session.ask_to_continue();
    EXPECT_TRUE(result);  // Expect the session to continue when input is 'y'
}

// Test asking to continue when player inputs 'n'
TEST(GameSessionTest, AskToContinueNoTest) {
    Game_session session(1000);  // Initialize with balance 1000

    // Simulate user input 'n'
    std::istringstream input("n\n");
    std::cin.rdbuf(input.rdbuf());
    // Redirect std::cin to use the simulated input

    bool result = session.ask_to_continue();
    EXPECT_FALSE(result);  // Expect the session to stop when input is 'n'
}
