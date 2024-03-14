#include "EnterInstrumentScreen.h"
#include <stdexcept>
#include "FinState.h"
#include "MainMenuScreen.h"


string EnterInstrumentScreen::toString(const FinState& finState)
{
  return
    "Please enter the instrument data in the format:\n"
    "name,currency,issuer\n"
    "For example:\n"
    "ABB,SEK,Asea Brown Boveri\n";
}


string EnterInstrumentScreen::invalidInputResponse()
{
  return "Invalid input.\n";
}


FinState EnterInstrumentScreen::outputState(const FinState& finState, string input)
{
  // TODO: Save newly added instrument to finState
  return finState;
}


std::unique_ptr<Screen> EnterInstrumentScreen::outputScreen(string input)
{
  return std::make_unique<MainMenuScreen>();
}