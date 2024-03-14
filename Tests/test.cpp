#include "pch.h"
#include "../Core/Trade.h"
#include "../Core/Instrument.h"
#include "../Core/Position.h"
#include <vector>
#include <iostream>

const Instrument TEST_INSTRUMENT("ABB", "SEK", "Asea Brown Boveri");

TEST(Instrument, Equality)
{
  EXPECT_EQ( 
    Instrument("ABB", "SEK", "Asea Brown Boveri"),
    Instrument("ABB", "SEK", "Asea Brown Boveri"));
}

TEST(Trade, Equality)
{
  EXPECT_EQ(
    Trade(TEST_INSTRUMENT, "1.1", 1),
    Trade(TEST_INSTRUMENT, "1.1", 1));
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
    Trade(TEST_INSTRUMENT, "1.1", 3).value(),
    Trade(TEST_INSTRUMENT, "3.3", 1).value());
}

TEST(Position, Initialization1)
{
  EXPECT_EQ(
    Position(TEST_INSTRUMENT, "3.3"),
    Position(Trade(TEST_INSTRUMENT, "1.1", 3)));
}