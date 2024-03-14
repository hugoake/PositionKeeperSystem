#pragma once
#include "Screen.h"

struct EnterInstrumentScreen : Screen
{
  string toString(const FinState& finState);
  string invalidInputResponse();
  FinState outputState(const FinState& finState, string input);
  std::unique_ptr<Screen> outputScreen(string input);
};

