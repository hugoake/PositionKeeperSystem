#include "Trade.h"

Trade::Trade(Instrument instrument, Trade::float_type price, unsigned int quantity)
  : instrument(instrument),
    price(quantity),
    quantity(quantity){}

Trade::float_type Trade::value()
{
  return this->quantity * this->price;
}