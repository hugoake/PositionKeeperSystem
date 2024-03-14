#pragma once
#include <string>
#include <memory>
#include "FinState.h"

using std::string;

struct Screen
{
  virtual string toString(const FinState& finState) = 0;
  virtual string invalidInputResponse() = 0;
  virtual FinState outputState(const FinState& finState, string input) = 0;
  virtual std::unique_ptr<Screen> outputScreen(string input) = 0;
};