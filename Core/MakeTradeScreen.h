#pragma once
#include "Screen.h"

struct MakeTradeScreen : Screen
{
  string toString();
  string invalidInputResponse();
  std::unique_ptr<Screen> responseScreen(string input);
};

