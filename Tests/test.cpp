#include "pch.h"
#include "../Core/Trade.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(Trade::Trade(1).price, Trade::Trade(1).price+1);
  EXPECT_TRUE(true);
}