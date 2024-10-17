// Copyright 2024 GROUP 34
/**
 * @author Kelechi Anyanwu <kelechi.anyanwu@uleth.ca>
 * @date Fall 2024 
 */
#include "../include/Stakes.hpp"
#include <iostream>


// Base class constructor implementation
/**
 * @brief Constructor for Stakes class.
 * @param stakes_enum The type of stake (LOW, MEDIUM, HIGH).
 * @param BetAmount The betting amount.
 * @param ProbToWin The probability of winning.
 */
Stakes::Stakes(StakesEnum stakes_enum, int BetAmount, float ProbToWin) :
stakes_enum(stakes_enum), BetAmount(BetAmount), ProbToWin(ProbToWin) {}

/**
 * @brief Gets the bet amount.
 * @return The amount of the bet.
 */
int Stakes::GetBetAmount() const {
    return BetAmount;  // Return the bet amount
}

/**
 * @brief Applies the probability to the winnings.
 * @param winnings The potential winnings.
 * @return The adjusted winnings based on probability.
 */
float Stakes::ApplyProb(float winnings) const {
    return winnings * ProbToWin;  // Adjust winnings based on the probability
}

// LowStakes constructor implementation
/**
 * @brief Constructor for LowStakes class.
 * Initializes base class with low stake values.
 */
LowStakes::LowStakes()
    : Stakes(StakesEnum::LOW, 5, 0.70f) {}

/**
 * @brief Gets the bet amount for low stakes.
 * @return The bet amount specific to LowStakes.
 */
int LowStakes::GetBetAmount() const {
    return BetAmount;  // Returns the bet amount specific to LowStakes
}

/**
 * @brief Applies probability to the winnings for low stakes.
 * @param winnings The potential winnings.
 * @return The adjusted winnings based on probability for low stakes.
 */
float LowStakes::ApplyProb(float winnings) const {
    return Stakes::ApplyProb(winnings);  // Call base class implementation
}

// MediumStakes constructor implementation
/**
 * @brief Constructor for MediumStakes class.
 * Initializes base class with medium stake values.
 */
MediumStakes::MediumStakes() : Stakes(StakesEnum::MEDIUM, 25, 0.50f) {}

/**
 * @brief Gets the bet amount for medium stakes.
 * @return The bet amount specific to MediumStakes.
 */
int MediumStakes::GetBetAmount() const {
    return BetAmount;
}

/**
 * @brief Applies probability to the winnings for medium stakes.
 * @param winnings The potential winnings.
 * @return The adjusted winnings based on probability for medium stakes.
 */
float MediumStakes::ApplyProb(float winnings) const {
    return Stakes::ApplyProb(winnings);
}

// HighStakes constructor implementation
/**
 * @brief Constructor for HighStakes class.
 * Initializes base class with high stake values.
 */
HighStakes::HighStakes()
    : Stakes(StakesEnum::HIGH, 50, 0.30f) {}

/**
 * @brief Gets the bet amount for high stakes.
 * @return The bet amount specific to HighStakes.
 */
int HighStakes::GetBetAmount() const {
    return BetAmount;
}

/**
 * @brief Applies probability to the winnings for high stakes.
 * @param winnings The potential winnings.
 * @return The adjusted winnings based on probability for high stakes.
 */
float HighStakes::ApplyProb(float winnings) const {
    return Stakes::ApplyProb(winnings);
}
