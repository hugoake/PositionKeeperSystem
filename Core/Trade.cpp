#include "Trade.h"

Trade::Trade(Instrument instrument, Trade::float_type price, unsigned int quantity)
  : instrument(instrument),
    price(price),
    quantity(quantity){}

Trade::Trade(Instrument instrument, std::string price, unsigned int quantity)
  : instrument(instrument),
    price(float_type(price)), // <-- Runtime error if price cannot be parsed.
    quantity(quantity) {}

Trade::float_type Trade::value()
{
  return this->quantity * this->price;
}