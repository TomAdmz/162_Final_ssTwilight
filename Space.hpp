/***************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Tom Adamcewicz
 ** Date: 3/14/16
 ** Description: This is the Space parent class. It defines all the virtual functions
 ** for the classes derived from it. It has data members for 4 pointers to other spaces
 ** a string for type a pointer to a SpaceMarine for player and an int for checked
 ** if a Space has been checked. 
 ** Input: none
 ** Output: Space prototype
 ***************************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "SpaceMarine.hpp"
#include <string>

class Space
{
   protected:
      
      Space* nextSpace;
      Space* lastSpace;
      Space* leftSpace;
      Space* rightSpace;

      std::string type;

      SpaceMarine* player;

      int checked;

   public:

      Space();
   
      virtual void setPlayer(SpaceMarine*) = 0;

      virtual void enterSpace() = 0;
      virtual void leaveSpace() = 0;

      virtual void setPtrs(Space*, Space*, Space*, Space*) = 0;
      virtual void setPodNum(int) = 0;
      virtual void setBridgeType(std::string) = 0; 

      virtual std::string getType() = 0;
      virtual std::string getNext() = 0;
      virtual std::string getLast() = 0;
      virtual std::string getLeft() = 0;
      virtual std::string getRight() = 0;

      virtual Space* nextPtr() = 0;
      virtual Space* lastPtr() = 0;
      virtual Space* leftPtr() = 0;
      virtual Space* rightPtr() = 0;

      virtual void observeSpace() = 0;

      virtual void specialInteract() = 0;

};

#endif
