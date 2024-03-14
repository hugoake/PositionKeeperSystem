#pragma once
#include <string>

struct Instrument
{
  std::string name;
  std::string currency;
  std::string issuer;

  Instrument(std::string name, std::string currency, std::string issuer);

  bool operator==(Instrument const&) const = default;
};

