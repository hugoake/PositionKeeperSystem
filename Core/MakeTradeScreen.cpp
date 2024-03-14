#include "MakeTradeScreen.h"

#include <iostream>
#include <stdexcept>
#include "FinState.h"
#include "MainMenuScreen.h"


string MakeTradeScreen::toString(const FinState& finState)
{
  return
    "Please enter the trade data in the format:\n"
    "intrument_name,currency,issuer,price,quantity,acquirer,counterparty,marketplace\n"
    "For example:\n"
    "ABB,SEK,Asea Brown Boveri,97.00,4,Equity Desk,Deutsche Bank,OMX\n";
}


string MakeTradeScreen::invalidInputResponse()
{
  return "Invalid input.\n";
}


FinState MakeTradeScreen::outputState(const FinState& finState, string input)
{
  auto positions = finState;

  string name, currency, issuer, price, quantity, acquirer, counterparty, marketplace;
  std::stringstream stream(input);

  getline(stream, name, ',');
  if(name == "test1")
  {
    addTrade(positions, Trade(Instrument("ABB", "SEK", "Asea Brown Boveri"),
      "97.00", 4, "Equity Desk", "Deutsche Bank", "OMX"));
    return positions;
  }
  getline(stream, currency, ',');
  getline(stream, issuer, ',');
  getline(stream, price, ',');
  getline(stream, quantity, ',');
  getline(stream, acquirer, ',');
  getline(stream, counterparty, ',');
  getline(stream, marketplace, ',');
  Trade trade(Instrument(name, currency,issuer), price, std::stoul(quantity), acquirer, counterparty, marketplace);
  addTrade(positions, trade);
  return positions;
}


std::unique_ptr<Screen> MakeTradeScreen::outputScreen(string input)
{
  return std::make_unique<MainMenuScreen>();
}