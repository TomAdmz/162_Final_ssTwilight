/****************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Tom Adamcewicz
 ** Date: 3/14/16
 ** Description: This is the Lab class, it is derived from the Space class and defines
 ** all of its virtual functions.
 ** Input: none
 ** Output: Lab prototype
 ***************************************************************************************/ 


#ifndef LAB_HPP
#define LAB_HPP

#include "Space.hpp"

class Lab : public Space
{

   protected:

   public:

      Lab();

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
 
