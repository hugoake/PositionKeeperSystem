// PositionKeeperSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
      std::cin >> input;
      try {
        finState = screen->outputState(finState, input);
        screen = screen->outputScreen(input);
        std::cout << finState.size();
        std::cout << screen;
      }
      catch (...)
      {
        std::cout << screen->invalidInputResponse();
        std::cout << "Press any key to continue.\n";
        _getch();
      }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
