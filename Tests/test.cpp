#include "pch.h"
#include "../Core/Trade.h"
#include "../Core/Instrument.h"
#include "../Core/Position.h"
#include "../Core/PositionsScreen.h"
#include <vector>
#include <iostream>


const Instrument TEST_INSTRUMENT("ABB", "SEK", "Asea Brown Boveri");

Trade testTrade(std::string price, unsigned int quantity)
{
  return Trade(TEST_INSTRUMENT, price, quantity, "Equity Desk", "Deutsche Bank", "OMX");
}

TEST(Instrument, Equality)
{
  EXPECT_EQ( 
    Instrument("ABB", "SEK", "Asea Brown Boveri"),
    Instrument("ABB", "SEK", "Asea Brown Boveri"));
}

TEST(Trade, NotEquality)
{
  EXPECT_FALSE(testTrade("1.1", 1) == testTrade("1.1", 1));
}

TEST(Position, Equality)
{
  EXPECT_EQ(
    Position(TEST_INSTRUMENT, "1.1"),
    Position(TEST_INSTRUMENT, "1.1"));
}

TEST(Trade, NoBase10RoundingError)
{
  EXPECT_EQ(
    testTrade("1.1", 3).value(),
    testTrade("3.3", 1).value());
}

TEST(Trade, HighResTime)
{
  auto trade1 = testTrade("1.1", 3);
  auto trade2 = testTrade("1.1", 3);
  EXPECT_GE(trade2.time, trade1.time);
  EXPECT_FALSE(trade1.time == trade2.time);
}

TEST(PositionsScreen, outputScreen)
{
  PositionsScreen screen = {};
  EXPECT_NE(screen.outputScreen("1"), nullptr);
}

