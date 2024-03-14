#include "Position.h"
#include <vector>
#include <stdexcept>


Position::Position(Instrument instrument, Trade::float_type value)
  : instrument(instrument),
    value(value) {}


Position::Position(Instrument instrument, std::string value)
  : instrument(instrument),
    value(Trade::float_type(value)) // <-- Causes runtime error if value cannot be parsed.
    {}


Position::Position(Trade trade)
  : instrument(trade.instrument),
    value(trade.value()) {}


Position& Position::addTrade(Trade trade)
{
  if (trade.instrument == this->instrument)
  {
    this->value += trade.value();
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
    bool instrument_has_occurred = false;
    for(auto& position : positions)
    {
      if(trade.instrument == position.instrument)
      {
        position.addTrade(trade);
        instrument_has_occurred = true;
      }
    }
    if(!instrument_has_occurred)
    {
      positions.emplace_back(trade);
    }
  }
  return positions;
}
