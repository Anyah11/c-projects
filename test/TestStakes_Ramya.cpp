#include "Stakes.hpp"
#include <gtest/gtest.h>

// Test Stakes Initialization with
// correct enum value and arguments
TEST(StakesTest, ConstructorTest) {
    //Initialize the Stakes object with enum,
    // bet amount, and probability to win
    Stakes stakes(StakesEnum::LOW, 20, 0.5f);
    // Check if the bet amount is initialized correctly
    EXPECT_EQ(stakes.GetBetAmount(), 20);
}

// Test Stakes Initialization
// with a different enum value (if applicable)
TEST(StakesTest, ConstructorHighTest) {
    Stakes stakes(StakesEnum::HIGH, 100, 0.8f);
    // Check if the bet amount is
    // initialized correctly for HIGH stakes
    EXPECT_EQ(stakes.GetBetAmount(), 100);
}

// Test if the GetBetAmount works for various values
TEST(StakesTest, GetBetAmountTest) {
    Stakes lowStakes(StakesEnum::LOW, 50, 0.3f);
    Stakes highStakes(StakesEnum::HIGH, 200, 0.7f);
    // Test if bet amounts are retrieved correctly
    EXPECT_EQ(lowStakes.GetBetAmount(), 50);
    EXPECT_EQ(highStakes.GetBetAmount(), 200);
}
//  All Tests Passed
