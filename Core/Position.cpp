#include "Position.h"
#include <vector>
#include <stdexcept>

Position::Position(Instrument instrument, int quantity) : instrument(instrument), quantity(quantity) {}

Position::Position(Trade trade) : instrument(trade.instrument), quantity(trade.quantity) {}

Position& Position::addTrade(Trade trade)
{
  if (trade.instrument == this->instrument)
  {
    this->quantity += trade.quantity;
  }
  else
  {
    throw std::invalid_argument("The trade's instrument must equal the position's instrument.");
  }
}

// Collapses a vector of trades into a vector of positions with distinct instruments.
std::vector<Position> toPositions(const std::vector<Trade>& trades)
{
  std::vector<Position> positions = {};
  for(auto trade : trades)
  {
    bool instrument_has_occured = false;
    for(auto& position : positions)
    {
      if(trade.instrument == position.instrument)
      {
        position.addTrade(trade);
        instrument_has_occured = true;
      }
    }
    if(!instrument_has_occured)
    {
      positions.emplace_back(trade);
    }
  }
  return positions;
}
