/**
 * @author Aayush patel
 * @date 2024-10-05
 */

#include <gtest/gtest.h>
#include "Player.hpp"

//Test to check the constructor
TEST(PlayerTest, Constructor) {
    // Creating a player object with name "Aayush" and balance 100
    Player p("Aayush", 100.0);

    // Check if the balance is correct
    EXPECT_EQ(p.getBalance(), 100.0);

    // Check if the name is correctly set
    EXPECT_EQ(p.EnterName("Aayush"), "Aayush");
}

// Test to check balance setting and getting
TEST(PlayerTest, BalanceGetterSetter) {
    // Creating a player with default balance
    Player p("Aayush", 50.0);

    // Check if the default balance is correct
    EXPECT_EQ(p.getBalance(), 50.0);

    // setting a new balance
    p.setBalance(75.0);

    // Checking if the balance was updated
    EXPECT_EQ(p.getBalance(), 75.0);
}

// Test to check spinner selection
TEST(PlayerTest, ChooseSpinner) {
    // Creating a player
    Player p("Aayush", 50.0);

    // Test selecting spinner A
    EXPECT_EQ(p.ChooseSpinner("SpinnerA"), "SpinnerA");

    // Test selecting spinner B
    EXPECT_EQ(p.ChooseSpinner("SpinnerB"), "SpinnerB");
}

// Test for the welcome message
TEST(PlayerTest, WelcomeMessage) {
    Player p("Aayush", 100.0);
    p.WelcomeMessage();  // No need to test the output, just make sure it runs
}
// All tests Passed
