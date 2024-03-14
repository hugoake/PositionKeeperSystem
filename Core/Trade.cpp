#include "Trade.h"

Trade::Trade(
  Instrument instrument,
  float_type price,
  unsigned int quantity,
  std::string acquirer,
  std::string counterparty,
  std::string marketplace)
  : instrument(instrument),
    price(price),
    quantity(quantity),
    time(std::chrono::high_resolution_clock::now()),
    acquirer(acquirer),
    counterparty(counterparty),
    marketplace(marketplace) {}


Trade::Trade(
  Instrument instrument,
  std::string price,
  unsigned int quantity,
  std::string acquirer,
  std::string counterparty,
  std::string marketplace)
  : instrument(instrument),
    price(float_type(price)), // <-- Runtime error if price cannot be parsed.
    quantity(quantity),
    time(std::chrono::high_resolution_clock::now()),
    acquirer(acquirer),
    counterparty(counterparty),
    marketplace(marketplace) {}


Trade::float_type Trade::value()
{
  return this->quantity * this->price;
}