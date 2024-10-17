/**
 * @author Kelechi Anyanwu [kelechi.anyanwu@uleth.ca]
 * @date Fall 2024
 */
#include "../include/Stakes.hpp"
#include <gtest/gtest.h>

//Test for LowStakes class
TEST(StakesTest, LowStakesTest) {
    LowStakes lStakes;
    // Check if the bet amount is correctly initialized
    EXPECT_EQ(lStakes.GetBetAmount(), 5);
    // Check if ApplyProb calculates
    // winnings correctly based on probability
    EXPECT_FLOAT_EQ(lStakes.ApplyProb(100), 70);
    // Assuming 70% winning probability
}

// Test for MediumStakes class
TEST(StakesTest, MediumStakesTest) {
    MediumStakes mStakes;

    // Check if the bet amount is correctly initialized
    EXPECT_EQ(mStakes.GetBetAmount(), 25);

    // Check if ApplyProb calculates
    //winnings correctly based on probability
    EXPECT_FLOAT_EQ(mStakes.ApplyProb(100), 50);
    // Assuming 50% winning probability
}

// Test for HighStakes class
TEST(StakesTest, HighStakesTest) {
    HighStakes hStakes;

    // Check if the bet amount is correctly initialized
    EXPECT_EQ(hStakes.GetBetAmount(), 50);

    // Check if ApplyProb calculates
    // winnings correctly based on probability
    EXPECT_FLOAT_EQ(hStakes.ApplyProb(100), 30);
    // Assuming 30% winning probability
}
//All tests Passed
