/***************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Tom Adamcewicz
 ** Date: 3/14/16
 ** Description: This is the ControlRoom class file, it is derived from the Space class
 ** and defines all of its virtual functions.
 ** Input: none
 ** Output: ControlRoom prototype
 ***************************************************************************************/ 

#ifndef CONTROLROOM_HPP
#define CONTROLROOM_HPP

#include "Space.hpp"

class ControlRoom : public Space
{
   
   protected:

   public:

      ControlRoom();

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
 
