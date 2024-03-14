#include "Screen.h"


string HomeScreen::toString()
{
  return "";
}


bool HomeScreen::validInput(string input)
{
  return true;
}


string HomeScreen::invalidInputResponse()
{
  return "invalid\n";
}


std::unique_ptr<Screen> HomeScreen::responseScreen()
{
  return std::make_unique<HomeScreen>();
}