#include "PositionsScreen.h"
#include <stdexcept>
#include <VariadicTable.h>
#include <sstream>
#include "FinState.h"
#include "MainMenuScreen.h"


PositionsScreen::PositionsScreen(){};

PositionsScreen::PositionsScreen(std::function<string(Position)> positionGroupKey)
  : positionGroupKey(positionGroupKey) {};


string PositionsScreen::toString(const FinState& finState)
{
  VariadicTable<string, string, string, string> position_table
    = {{"Name", "Currency", "Issuer", "Value"}};
  for( auto pos : finState)
  {
    position_table.addRow(pos.instrument.name, pos.instrument.currency, pos.instrument.issuer, pos.value.str(2, std::ios::fixed));
  }
  std::ostringstream stream;
  position_table.print(stream);
  return  
    stream.str() + 
    "What would you like to do?\n"
    "Enter a number followed by enter to select the corresponding action.\n"
    "(1) Group positions by name.\n"
    "(2) Group positions by issuer.\n"
    "(3) Go back to main menu.\n";
}


string PositionsScreen::invalidInputResponse()
{
  return "Invalid input.\n";
}


FinState PositionsScreen::outputState(const FinState& finState, string input)
{
  auto positions = finState;

  std::sort(positions.begin(), positions.end(), 
      [this](Position pos1, Position pos2)->bool
            {
              return positionGroupKey(pos1) < positionGroupKey(pos2);
            });
  return positions;
}


std::unique_ptr<Screen> PositionsScreen::outputScreen(string input)
{
  int int_input = std::stoi(input);
  // Could enforce/verify that std::to_string(int_input) == input
  switch (int_input)
  {
  case 1:
    return std::make_unique<PositionsScreen>(
      [](Position position) -> std::string{ return position.instrument.name; });
    break;
  case 2:
    return std::make_unique<PositionsScreen>(
      [](Position position) -> std::string { return position.instrument.issuer; });
    break;
  case 3:
    return std::make_unique<MainMenuScreen>();
    break;
  default:
    throw std::invalid_argument("Argument 'input' is invalid.");
  }
}