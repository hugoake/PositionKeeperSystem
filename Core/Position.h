#pragma once
#include "Instrument.h"
#include "Trade.h"
#include <vector>
#include <string>

struct Position
{
  Instrument instrument;
  Trade::float_type value;

  Position(Instrument instrument, Trade::float_type value);
  Position(Instrument instrument, std::string value);
  Position(Trade trade);

  bool operator==(Position const&) const = default;

  Position& addTrade(Trade trade);
};

std::vector<Position> toPositions(const std::vector<Trade>& trades);