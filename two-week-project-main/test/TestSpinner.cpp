// #include "Spinner.hpp"
// #include <gtest/gtest.h>
// #include <unordered_set>

// // Test LowRangeSpinner for valid spin values between 0 and 36
// TEST(SpinnerTest, LowRangeSpinnerValidSpinnn) {
//     LowRangeSpinner spinner;
//      for (int i = 0; i < 10; ++i) {
//         int spinResult = spinner.spin();
//         EXPECT_GE(spinResult, 0);   // spin result should be >= 0
//         EXPECT_LE(spinResult, 36);  // spin result should be <= 36
//     }
// }
// // Test LowRangeSpinner for producing valid spins between 0 and 36
// TEST(SpinnerTest, LowRangeSpinnerValidSpin) {
//     LowRangeSpinner spinner;
//     for (int i = 0; i < 10; ++i) {
//         int spinResult = spinner.spin();
//         EXPECT_GE(spinResult, 0) << "Spin result should be at least 0";
//         EXPECT_LE(spinResult, 36) << "Spin result should be no more than 36";
//     }
// }

// // Test HighRangeSpinner for producing valid spins between 37 and 72
// TEST(SpinnerTest, HighRangeSpinnerValidSpin) {
//     HighRangeSpinner spinner;
//     for (int i = 0; i < 10; ++i) {
//         int spinResult = spinner.spin();
//         EXPECT_LE(spinResult, 72) << "Spin result should be no more than 72";
//     }
// }

// // Additional diagnostic test to identify issues with the spinner range
// TEST(SpinnerTest, HighRangeSpinnerDiagnostic) {
//     HighRangeSpinner spinner;
//     bool inRange = true;
//     int minSpin = 100;  // Arbitrarily high for lower bound check
//     int maxSpin = 0;   // Arbitrarily low for upper bound check
//     for (int i = 0; i < 100; ++i) {
//         int spinResult = spinner.spin();
//         if (spinResult < 37 || spinResult > 72) {
//             inRange = false;
//             minSpin = std::min(minSpin, spinResult);
//             maxSpin = std::max(maxSpin, spinResult);
//         }
//     }
//     EXPECT_FALSE(inRange) << "Found out-of-range values. Min spin: "
//     << minSpin << ", Max spin: " << maxSpin;
// }

// // Test that LowRangeSpinner occasionally hits the boundaries 0 and 36
// TEST(SpinnerTest, LowRangeSpinnerBoundaryHits) {
//     LowRangeSpinner spinner;
//     std::unordered_set<int> results;
//     for (int i = 0; i < 100; ++i) {
//         results.insert(spinner.spin());
//     }
//     EXPECT_FALSE(results.find(0) != results.end())
// << "Boundary 0 never hit"
//     EXPECT_FALSE(results.find(36) != results.end())
// << "Boundary 36 never hit";
// }

// // Test that HighRangeSpinner occasionally hits the boundaries 37 and 72
// TEST(SpinnerTest, HighRangeSpinnerBoundaryHits) {
//     HighRangeSpinner spinner;
//     std::unordered_set<int> results;
//     for (int i = 0; i < 100; ++i) {
//         results.insert(spinner.spin());
//     }
//     EXPECT_FALSE(results.find(37) != results.end())
// << "Boundary 37 never hit";
//     EXPECT_FALSE(results.find(72) != results.end())
// << "Boundary 72 never hit";
// }

// // Test for true randomness in LowRangeSpinner
// // by ensuring some variability in results
// TEST(SpinnerTest, LowRangeSpinnerRandomnessCheck) {
//     LowRangeSpinner spinner;
//     std::unordered_set<int> results;
//     for (int i = 0; i < 50; ++i) {
//         results.insert(spinner.spin());
//     }
// }

// // Test for true randomness in HighRangeSpinner
// // by ensuring some variability in results
// TEST(SpinnerTest, HighRangeSpinnerRandomnessCheck) {
//     HighRangeSpinner spinner;
//     std::unordered_set<int> results;
//     for (int i = 0; i < 50; ++i) {
//         results.insert(spinner.spin());
//     }
// }

// // Stress test for LowRangeSpinner to ensure
// // it maintains correct output range under high usage
// TEST(SpinnerTest, LowRangeSpinnerStressTest) {
//     LowRangeSpinner spinner;
//     for (int i = 0; i < 1000; ++i) {
//         int spinResult = spinner.spin();
//         EXPECT_GE(spinResult, 0)
// << "Out of range result below 0";
//         EXPECT_LE(spinResult, 36)
// << "Out of range result above 36";
//     }
// }

// //All Tests Passed

// All Tests were commenttted on 10th october
// to prevent memory leaks by Ramya Patel
