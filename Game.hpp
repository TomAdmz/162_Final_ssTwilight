/***************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Tom Adamcewicz
 ** Date: 3/14/16
 ** Description: This is the Game class header file. It has data members for a ship
 ** and a pointer to a SpaceMarine player, also an int for moves. This class runs the
 ** game and has the player interact with the various objects on the ship. 
 ** Input: User menu options
 ** Output: the ssTwilight game
 ***************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Ship.hpp"
#include "SpaceMarine.hpp"


class Game
{

   private:

      Ship ship;
      SpaceMarine* player;
      
      int moves;

   public:

      Game();

      void gameIntro();
      void playGame();
      void wonGame();

};

#endif 
