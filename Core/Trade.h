#pragma once
#include "Instrument.h"
#include <boost/multiprecision/cpp_dec_float.hpp>
//using boost::multiprecision::cpp_dec_float_50;


struct Trade
{
  typedef boost::multiprecision::cpp_dec_float_50 float_type;

  const Instrument instrument;
  const float_type price;
  const unsigned int quantity; 

  Trade(Instrument instrument, float_type price, unsigned int quantity);
  
  float_type value();
};

