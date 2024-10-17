#include "Spinner.hpp"
#include "MakeRandomInt.hpp"

// Implementation of LowRangeSpinner
int LowRangeSpinner::spin() {
  // generate a number between 2 and 5
  MakeRandomInt* randomGenerator = MakeRandomInt::getInstance();
  return 2 + randomGenerator->getValue(4);
}

// Implementation of HighRangeSpinner
int HighRangeSpinner::spin() {
  // generate a number between 0 and 7
  MakeRandomInt* randomGenerator = MakeRandomInt::getInstance();
  return randomGenerator->getValue(8);
}
