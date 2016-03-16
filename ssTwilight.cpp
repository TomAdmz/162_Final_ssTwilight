/***************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Tom Adamcewicz
 ** Date: 3/15/16
 ** Description: This is the main file for the ssTwilight game, it creates a new game
 ** runs the game and then thanks the user for playing.
 ** Input: none
 ** Output: ssTwilight game
 ***************************************************************************************/

#include "Game.hpp"
#include <iostream>

int main ()
{
   Game newG;

   newG.playGame();

   std::cout << "***Thanks for playing!***" << std::endl;

   return 0;
}
