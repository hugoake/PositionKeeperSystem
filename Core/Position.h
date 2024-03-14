#pragma once
#include "Instrument.h"
#include "Trade.h"
#include <vector>


struct Position
{
  const Instrument instrument;
  Trade::float_type value;

  Position(Instrument instrument, Trade::float_type value);
  Position(Trade trade);

  Position& addTrade(Trade trade);
};

std::vector<Position> toPositions(const std::vector<Trade>& trades);