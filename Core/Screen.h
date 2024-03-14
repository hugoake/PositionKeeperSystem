#pragma once
#include <string>
#include <memory>

using std::string;



class Screen
{
public:
  virtual string toString() = 0;
  virtual bool validInput(string input) = 0;
  virtual string invalidInputResponse() = 0;
  virtual std::unique_ptr<Screen> responseScreen() = 0;
};

class HomeScreen : public Screen
{
public:
  string toString();
  bool validInput(string input);
  string invalidInputResponse();
  std::unique_ptr<Screen> responseScreen();
};

