#include "EnterInstrumentScreen.h"
#include <stdexcept>
#include "FinState.h"


string EnterInstrumentScreen::toString(const FinState& finState)
{
  return  "What would you like to do?\n"
    "Enter a number followed by enter to select the corresponding action.\n"
    "(1) View EnterInstrument.\n"
    "(2) Make a trade.\n"
    "(3) Enter a new instrument.";
}


string EnterInstrumentScreen::invalidInputResponse()
{
  return "Invalid input.\n";
}


FinState EnterInstrumentScreen::outputState(const FinState& finState, string input)
{
  return finState;
}


std::unique_ptr<Screen> EnterInstrumentScreen::outputScreen(string input)
{
  int int_input = std::stoi(input);
  // Could enforce/verify that std::to_string(int_input) == input
  switch (int_input)
  {
  case 1:
    return std::make_unique<EnterInstrumentScreen>();
    break;
  case 2:
    return std::make_unique<EnterInstrumentScreen>();
    break;
  case 3:
    return std::make_unique<EnterInstrumentScreen>();
    break;
  default:
    throw std::invalid_argument("Argument 'input' is invalid.");
  }
}