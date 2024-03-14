#pragma once
#include "Screen.h"

struct MainMenuScreen : Screen
{
  string toString();
  string invalidInputResponse();
  std::unique_ptr<Screen> responseScreen(string input);
};

