#pragma once
#include "Instrument.h"
#include "Trade.h"
#include <vector>


struct Position
{
  const Instrument instrument;
  int quantity;

  Position(Instrument instrument, int quantity);
  Position(Trade trade);

  Position& addTrade(Trade trade);
};

std::vector<Position> toPositions(const std::vector<Trade>& trades);