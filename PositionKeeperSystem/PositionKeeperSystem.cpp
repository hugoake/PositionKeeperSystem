#include <iostream>
#include "../Core/MainMenuScreen.h"
#include <conio.h>
#include <memory>
#include "../Core/FinState.h"

void clearTerminal()
{
  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

int main()
{
    FinState finState = {}; // TODO: Import from file.
    std::unique_ptr<Screen> screen = std::make_unique<MainMenuScreen>();
    while(screen)
    {
      clearTerminal();
      string input;
      std::cout << screen->toString(finState);
      getline(std::cin,input);
      try {
        finState = screen->outputState(finState, input);
        screen = screen->outputScreen(input);
      }
      catch (...)
      {
        std::cout << screen->invalidInputResponse();
        std::cout << "Press any key to continue.\n";
        _getch();
      }
    }
}