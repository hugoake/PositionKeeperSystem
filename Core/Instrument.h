#pragma once
#include <string>

struct Instrument
{
  const std::string name;
  const std::string currency;
  const std::string issuer;

  Instrument(std::string name, std::string currency, std::string issuer);

  bool operator==(Instrument const&) const = default;
};

