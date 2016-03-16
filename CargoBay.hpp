/***************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Tom Adamcewicz
 ** Date: 3/14/16
 ** Description: This is the CargoBay class file. It defines all of the Space virtual
 ** functions and creates a CargoBay space.
 ** Input: none
 ** Output: CargoBay prototype
 ***************************************************************************************/

#ifndef CARGOBAY_HPP
#define CARGOBAY_HPP

#include "Space.hpp"

class CargoBay : public Space
{

   protected:

   public:

      CargoBay();

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
