#pragma once
#include "Screen.h"

struct EnterInstrumentScreen : Screen
{
  string toString();
  string invalidInputResponse();
  std::unique_ptr<Screen> responseScreen(string input);
};

