#pragma once
#include "Instrument.h"
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <string>
#include <chrono>


struct Trade
{
  typedef boost::multiprecision::cpp_dec_float_50 float_type;

  const Instrument instrument;
  const float_type price;
  const unsigned int quantity;
  const std::chrono::time_point<std::chrono::high_resolution_clock> time;
  const std::string acquirer;
  const std::string counterparty;
  const std::string marketplace;


  Trade(Instrument instrument,
        float_type price,
        unsigned int quantity,
        std::string acquirer,
        std::string counterparty,
        std::string marketplace);
  Trade(Instrument instrument,
        std::string price,
        unsigned int quantity,
        std::string acquirer,
        std::string counterparty,
        std::string marketplace);

  bool operator==(Trade const&) const = default;

  float_type value();
};

