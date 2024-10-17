#include "GameRules.hpp"
#include <gtest/gtest.h>

//Test Constructor for GameRules
TEST(GameRulesTest, ConstructorTest) {
    std::map<int, float> payout = {{10, 2.0}, {15, 1.5}};
    Game_rules gameRules("Sample Rules", payout);
    EXPECT_NO_THROW(gameRules.display_rules());
    // Check that display_rules does not throw
    EXPECT_NO_THROW(gameRules.display_payout());
    // Check that display_payout does not throw
}

// Test display_payout for correctness
TEST(GameRulesTest, DisplayPayoutTest) {
    std::map<int, float> payout = {{10, 2.0}, {15, 1.5}};
    Game_rules gameRules("Sample Rules", payout);

    // Capture the output of display_payout
    testing::internal::CaptureStdout();
    gameRules.display_payout();
    std::string output = testing::internal::GetCapturedStdout();

    // Check if the expected payouts are displayed
    EXPECT_NE(output.find("Player's Total: 10"), std::string::npos);
    // Ensure total 10 is listed
    EXPECT_NE(output.find("Payout: 200%"), std::string::npos);
    // Ensure payout of 2.0 (200%) is listed
    EXPECT_NE(output.find("Player's Total: 15"), std::string::npos);
    // Ensure total 15 is listed
    EXPECT_NE(output.find("Payout: 150%"), std::string::npos);
    // Ensure payout of 1.5 (150%) is listed
}

// Test display_rules for correctness
TEST(GameRulesTest, DisplayRulesTest) {
    std::map<int, float> payout = {{10, 2.0}, {15, 1.5}};
    Game_rules gameRules("Sample Rules", payout);
    // Capture the output of display_rules
    testing::internal::CaptureStdout();
    gameRules.display_rules();
    std::string output = testing::internal::GetCapturedStdout();
    // Check if the rules text is displayed correctly
    EXPECT_NE(output.find("Sample Rules"), std::string::npos);
    // Ensure rules are displayed
}
// All Tests Passed
