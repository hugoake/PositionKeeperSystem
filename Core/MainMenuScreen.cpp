#include "MainMenuScreen.h"
#include <stdexcept>
#include "EnterInstrumentScreen.h"
#include "MakeTradeScreen.h"
#include "PositionsScreen.h"


string MainMenuScreen::toString()
{
  return  "What would you like to do?\n"
    "Enter a number followed by enter to select the corresponding action.\n"
    "(1) View positions.\n"
    "(2) Make a trade.\n"
    "(3) Enter a new instrument.\n";
}


string MainMenuScreen::invalidInputResponse()
{
  return "Invalid input.\n";
}


std::unique_ptr<Screen> MainMenuScreen::responseScreen(string input)
{
  int int_input = std::stoi(input);
  // Could enforce/verify that std::to_string(int_input) == input
  switch (int_input)
  {
  case 1:
    return std::make_unique<PositionsScreen>();
    break;
  case 2:
    return std::make_unique<MakeTradeScreen>();
    break;
  case 3:
    return std::make_unique<EnterInstrumentScreen>();
    break;
  default:
    throw std::invalid_argument("Argument 'input' is invalid.");
  }
}