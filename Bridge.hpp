/***************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Tom Adamcewicz
 ** Date: 3/14/16
 ** Description: This is the Bridge class file, it is derived from the Space class
 ** and inherits all of its functions. It also has a data member bool called wonFight
 ** which returns true after the player defeats the alien.
 ** Input: none
 ** Output: Bridge prototype
 ***************************************************************************************/

#ifndef BRIDGE_HPP
#define BRIDGE_HPP

#include "Space.hpp"

class Bridge : public Space
{

   protected:

      bool wonFight;

   public:

      Bridge();

      void setPlayer(SpaceMarine*);

      void enterSpace();
      void leaveSpace();
      void setPtrs(Space*, Space*, Space*, Space*);
      void setPodNum(int);
      void setBridgeType(std::string);

      std::string getType();
      std::string getNext();
      std::string getLast();
      std::string getLeft();
      std::string getRight();

      Space* nextPtr();
      Space* lastPtr();
      Space* leftPtr();
      Space* rightPtr();

      void observeSpace();

      void specialInteract();

};

#endif

