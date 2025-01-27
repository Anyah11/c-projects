/**
* @author L. Nicole Wilson [n.wilson@uleth.ca]
* @date 2023-09
*/

#include "gtest/gtest.h"
#include "MakeRandomInt.hpp"

TEST(TestMakeRandomInt, canBeOnlyOneTest) {
  MakeRandomInt* makeOne
    = MakeRandomInt::getInstance();
  MakeRandomInt* makeTwo
    = MakeRandomInt::getInstance();

  EXPECT_TRUE(makeOne == makeTwo);
}

TEST(TestMakeRandomInt, getValueTest) {
  MakeRandomInt* makeRand
    = MakeRandomInt::getInstance();

  int result = makeRand->getValue(8);
  EXPECT_TRUE(0 <= result && result < 8);

  delete makeRand;
}
