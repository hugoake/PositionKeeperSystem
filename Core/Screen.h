#pragma once
#include <string>
#include <memory>

using std::string;

class Screen
{
public:
  virtual string toString() = 0;
  virtual string invalidInputResponse() = 0;
  virtual std::unique_ptr<Screen> responseScreen(string input) = 0;
};