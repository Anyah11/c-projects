/**
 * Copyright 2024 GROUP 34 
 * @author Kelechi Anyanwu <kelechi.anyanwu@uleth.ca>
 * @date Fall 2024
 */

#ifndef STAKES_HPP_
#define STAKES_HPP_

#include <iostream>

/**
 * @enum StakesEnum
 * @brief Enumeration representing different types of stakes.
 */
enum class StakesEnum {
    LOW,    ///< Low stake
    MEDIUM, ///< Medium stake
    HIGH    ///< High stake
};

/**
 * @class Stakes
 * @brief Base class representing stakes.
 */
class Stakes {
 protected:
    StakesEnum stakes_enum;  ///< The type of stake (LOW, MEDIUM, HIGH)
    int BetAmount;           ///< The amount of the bet
    float ProbToWin;         ///< The probability of winning

 public:  // Changed indentation: Indented +1 space
    /**
     * @brief Constructs a Stakes object.
     * @param stakes_enum The type of stake.
     * @param BetAmount The amount of the bet.
     * @param ProbToWin The probability of winning.
     */
    Stakes(StakesEnum stakes_enum, int BetAmount, float ProbToWin);

    /**
     * @brief Virtual default destructor for the Stakes class.
     */
    virtual ~Stakes() {}

    /**
     * @brief Gets the betting amount.
     * @return The amount of the bet.
     */
    virtual int GetBetAmount() const;

    /**
     * @brief Calculates expected winnings based on probability.
     * @param winnings The potential winnings.
     * @return The expected winnings after applying the probability to win.
     */
    virtual float ApplyProb(float winnings) const;
};

/**
 * @class LowStakes
 * @brief Derived class representing low stake type.
 */
class LowStakes : public Stakes {
 public:  // Changed indentation: Indented +1 space
    /**
     * @brief Constructs a LowStakes object.
     */
    LowStakes();

    /**
     * @brief Gets the betting amount for low stakes.
     * @return The amount of the bet for low stakes.
     */
    int GetBetAmount() const override;

    /**
     * @brief Calculates expected winnings for low stakes.
     * @param winnings The potential winnings.
     * @return The expected winnings after applying the probability to win for low stakes.
     */
    float ApplyProb(float winnings) const override;
};

/**
 * @class MediumStakes
 * @brief Derived class representing medium stake type.
 */
class MediumStakes : public Stakes {
 public:  // Changed indentation: Indented +1 space
    /**
     * @brief Constructs a MediumStakes object.
     */
    MediumStakes();

    /**
     * @brief Gets the betting amount for medium stakes.
     * @return The amount of the bet for medium stakes.
     */
    int GetBetAmount() const override;

    /**
     * @brief Calculates expected winnings for medium stakes.
     * @param winnings The potential winnings.
     * @return The expected winnings after applying the probability to win for medium stakes.
     */
    float ApplyProb(float winnings) const override;
};

/**
 * @class HighStakes
 * @brief Derived class representing high stake type.
 */
class HighStakes : public Stakes {
 public:  // Changed indentation: Indented +1 space
    /**
     * @brief Constructs a HighStakes object.
     */
    HighStakes();

    /**
     * @brief Gets the betting amount for high stakes.
     * @return The amount of the bet for high stakes.
     */
    int GetBetAmount() const override;

    /**
     * @brief Calculates expected winnings for high stakes.
     * @param winnings The potential winnings.
     * @return The expected winnings after applying the probability to win for high stakes.
     */
    float ApplyProb(float winnings) const override;
};

#endif  // STAKES_HPP_
