#include "Player.hpp"
#include <gtest/gtest.h>

//Test Player initialization
TEST(PlayerTest, ConstructorTest) {
    Player player("Ramya", 1000);
    // Initialize player with name "Ramya" and balance 1000
    EXPECT_EQ(player.EnterName("Ramya"), "Ramya");
    // Check if the player's name is set correctly
    EXPECT_EQ(player.getBalance(), 1000);
    // Check if the balance is initialized correctly
}

// Test updating player balance (positive update)
TEST(PlayerTest, UpdateBalancePositiveTest) {
    Player player("Ramya", 1000);
    // Initialize player with balance 1000
    player.setBalance(1200);
    // Use correct method to update balance
    EXPECT_EQ(player.getBalance(), 1200);
    // Balance should now be 1200
}

// Test updating player balance (negative update)
TEST(PlayerTest, UpdateBalanceNegativeTest) {
    Player player("Ramya", 1000);
    // Initialize player with balance 1000
    player.setBalance(500);
    // Use correct method to deduct balance
    EXPECT_EQ(player.getBalance(), 500);
    // Balance should now be 500
}

// Test updating player balance to zero
TEST(PlayerTest, UpdateBalanceToZeroTest) {
    Player player("Ramya", 1000);
    // Initialize player with balance 1000
    player.setBalance(0);
    // Use correct method to set balance to zero
    EXPECT_EQ(player.getBalance(), 0);
    // Balance should now be 0
}

// Test initializing player with zero balance
TEST(PlayerTest, ConstructorZeroBalanceTest) {
    Player player("Ramya", 0);
    // Initialize player with balance 0
    EXPECT_EQ(player.EnterName("Ramya"), "Ramya");
    // Check if the name is correct
    EXPECT_EQ(player.getBalance(), 0);
    // Expect balance to be initialized to 0
}

// Test initializing player with negative balance (if allowed)
TEST(PlayerTest, ConstructorNegativeBalanceTest) {
    Player player("Ramya", -500);
    // Initialize player with a negative balance
    EXPECT_EQ(player.getBalance(), -500);
    // Expect balance to be -500 (depending on implementation)
}
// All Test Passed
