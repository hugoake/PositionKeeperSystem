#pragma once
#include "Screen.h"
#include "Position.h"
#include <functional>

struct PositionsScreen : Screen
{
  std::function<string(Position)> positionGroupKey
    = [](Position position)->string
    {
      return position.instrument.name;
    }; // TODO: fix so that their types than string can be used.

  PositionsScreen();
  PositionsScreen(std::function<string(Position)> positionGroupKey);

  string toString(const FinState& finState);
  string invalidInputResponse();
  FinState outputState(const FinState& finState, string input);
  std::unique_ptr<Screen> outputScreen(string input);
};

