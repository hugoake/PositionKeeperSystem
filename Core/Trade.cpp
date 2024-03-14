#include "Trade.h"

Trade::Trade(Instrument instrument, double price, unsigned int quantity)
  : instrument(instrument),
    price(quantity),
    quantity(quantity){}

double Trade::value()
{
  return this->quantity * this->price;
}