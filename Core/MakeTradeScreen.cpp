#include "MakeTradeScreen.h"
#include <stdexcept>


string MakeTradeScreen::toString()
{
  return  "What would you like to do?\n"
    "Enter a number followed by enter to select the corresponding action.\n"
    "(1) View MakeTrade.\n"
    "(2) Make a trade.\n"
    "(3) Enter a new instrument.";
}


string MakeTradeScreen::invalidInputResponse()
{
  return "Invalid input.\n";
}


std::unique_ptr<Screen> MakeTradeScreen::responseScreen(string input)
{
  int int_input = std::stoi(input);
  // Could enforce/verify that std::to_string(int_input) == input
  switch (int_input)
  {
  case 1:
    return std::make_unique<MakeTradeScreen>();
    break;
  case 2:
    return std::make_unique<MakeTradeScreen>();
    break;
  default:
    throw std::invalid_argument("Argument 'input' is invalid.");
  }
}