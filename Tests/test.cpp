#include "pch.h"
#include "../Core/Trade.h"
#include <vector>
#include <iostream>

TEST(TestCaseName, TestName) {
  std::vector<int> v = {1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,22};
  auto w = v;
  w[0] = 2;
  EXPECT_TRUE(false) << sizeof(v);
  EXPECT_EQ(v,w);
}