#include "BettingOutcome.hpp"
#include <gtest/gtest.h>

//Test Constructor for BettingOutcome
TEST(BettingOutcomeTest, ConstructorTest) {
    Game_rules gameRules("Sample Rules", {{10, 2.0}, {15, 1.5}});
    Stakes stakes(StakesEnum::LOW, 100, 0.5f); // Initialize with LOW stakes
    BettingOutcome bettingOutcome(12, 100, 1000.0f, gameRules, stakes);
    EXPECT_EQ(bettingOutcome.get_current_balance(), 1000.0f);
    // Ensure balance is initialized correctly
    EXPECT_NO_THROW(bettingOutcome.check_outcome());
    // Check outcome doesn't throw an exception
}

// Test check_outcome for valid spin number (win scenario)
TEST(BettingOutcomeTest, CheckOutcomeWinTest) {
    Game_rules gameRules("Sample Rules", {{10, 2.0}, {15, 1.5}});
    Stakes stakes(StakesEnum::LOW, 100, 0.5f);
    // Initialize with LOW stakes
    BettingOutcome bettingOutcome(12, 100, 1000.0f, gameRules, stakes);
    // total_spin_number is between 10 and 17
    //so it should return true
    EXPECT_TRUE(bettingOutcome.check_outcome());
}

// Test check_outcome for invalid spin number (lose scenario)
TEST(BettingOutcomeTest, CheckOutcomeLoseTest) {
    Game_rules gameRules("Sample Rules", {{10, 2.0}, {15, 1.5}});
    Stakes stakes(StakesEnum::LOW, 100, 0.5f);
    // Initialize with LOW stakes
    BettingOutcome bettingOutcome(8, 100, 1000.0f, gameRules, stakes);
    // total_spin_number is less than 10, so it should return false
    EXPECT_FALSE(bettingOutcome.check_outcome());
}
// Test update_balance when the player wins
TEST(BettingOutcomeTest, UpdateBalanceWinnerTest) {
    Game_rules gameRules("Sample Rules", {{12, 2.0}});
    Stakes stakes(StakesEnum::LOW, 100, 0.5f);
    // Corrected stakes initialization with LOW
    BettingOutcome bettingOutcome(12, 100, 1000.0f, gameRules, stakes);
    // Corrected typo
    bettingOutcome.update_balance(true);
    // Simulate a win
    EXPECT_FLOAT_EQ(bettingOutcome.get_current_balance(), 1200.0f);
    // Balance should be 1200 (1000 + 100 * 2.0)
}

// Test update_balance when the player loses
TEST(BettingOutcomeTest, UpdateBalanceLoserTest) {
    Game_rules gameRules("Sample Rules", {{12, 2.0}});
    Stakes stakes(StakesEnum::LOW, 100, 0.5f);
    // Initialize with LOW stakes
    BettingOutcome bettingOutcome(12, 100, 1000.0f, gameRules, stakes);
    bettingOutcome.update_balance(false);
    // Simulate a loss
    EXPECT_FLOAT_EQ(bettingOutcome.get_current_balance(), 900.0f);
    // Balance should be 900 (1000 - 100)
}

// Test display_outcome for a win
TEST(BettingOutcomeTest, DisplayOutcomeWinTest) {
    Game_rules gameRules("Sample Rules", {{12, 2.0}});
    Stakes stakes(StakesEnum::LOW, 100, 0.5f);
    // Initialize with LOW stakes
    BettingOutcome bettingOutcome(12, 100, 1000.0f, gameRules, stakes);

    // Capture output to verify the display
    testing::internal::CaptureStdout();
    bettingOutcome.display_outcome();
    std::string output = testing::internal::GetCapturedStdout();

    // Check if the correct message is printed for a win
    EXPECT_NE(output.find("Congratulations! You won! :)"), std::string::npos);
    EXPECT_NE(output.find("Your current balance is: 1000 Zephy.")
    , std::string::npos);
}

// Test display_outcome for a loss
TEST(BettingOutcomeTest, DisplayOutcomeLoseTest) {
    Game_rules gameRules("Sample Rules", {{12, 2.0}});
    Stakes stakes(StakesEnum::LOW, 100, 0.5f);
    // Initialize with LOW stakes
    BettingOutcome bettingOutcome(8, 100, 1000.0f, gameRules, stakes);
    // Set spin number < 10 to lose

    // Capture output to verify the display
    testing::internal::CaptureStdout();
    bettingOutcome.display_outcome();
    std::string output = testing::internal::GetCapturedStdout();

    // Check if the correct message is printed for a loss
    EXPECT_NE(output.find("Sorry, you lost :("),
    std::string::npos);
    EXPECT_NE(output.find("Your current balance is: 1000 Zephy."),
    std::string::npos);
}
// All Tests Passed
