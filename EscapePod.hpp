/***************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Tom Adamcewicz
 ** Date: 3/14/16
 ** Description: This is the EscapePod class file. It's derived from the Space class
 ** it defines all virtual functions and has a data member for podNum which numbers
 ** each escape pod object.
 ** Input: none
 ** Output: EscapePod prototype.
 **************************************************************************************/

#ifndef ESCAPEPOD_HPP
#define ESCAPEPOD_HPP


#include "Space.hpp"

class EscapePod : public Space
{

   protected:

      int podNum;  

   public:

      EscapePod();

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
  
