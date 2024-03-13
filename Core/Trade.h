#pragma once
#include "Instrument.h"

struct Trade
{
  const Instrument instrument;
  const int quantity;

  Trade(Instrument instrument, int price);
};

