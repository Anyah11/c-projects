#ifndef SPINNER_HPP
#define SPINNER_HPP

#include <iostream>
#include <string>
#include "MakeRandomInt.hpp"

/**
 * @class Spinner
 * @brief Abstract base class for spinners in the game.
 * 
 * A spinner represents a game component that generates a random value within a specific range.
 */
class Spinner {
 public:
  /**
   * @brief Virtual destructor for Spinner class.
   * 
   * Ensures proper cleanup for derived classes.
   */
  virtual ~Spinner() = default;

  /**
   * @brief Pure virtual function to spin the spinner.
   * 
   * Derived classes must implement this function to generate a random value.
   * 
   * @return int The randomly generated value from the spinner.
   */
  virtual int spin() = 0;
};

/**
 * @class LowRangeSpinner
 * @brief Spinner that generates a random value between 2 and 5.
 * 
 * This class represents a spinner with a low range of possible outcomes, typically used for lower stakes in the game.
 */
class LowRangeSpinner : public Spinner {
 public:
  /**
   * @brief Spins the low-range spinner.
   * 
   * Generates a random value between 2 and 5 using the MakeRandomInt singleton.
   * 
   * @return int A random integer between 2 and 5.
   */
  int spin() override;
};

/**
 * @class HighRangeSpinner
 * @brief Spinner that generates a random value between 0 and 7.
   * 
 * This class represents a spinner with a high range of possible outcomes, typically used for higher stakes in the game.
 */
class HighRangeSpinner : public Spinner {
 public:
  /**
   * @brief Spins the high-range spinner.
   * 
   * Generates a random value between 0 and 7 using the MakeRandomInt singleton.
   * 
   * @return int A random integer between 0 and 7.
   */
  int spin() override;
};

#endif  // SPINNER_HPP
