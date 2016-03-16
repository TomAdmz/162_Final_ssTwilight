/***************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Tom Adamcewicz
 ** Date: 3/14/16
 ** Description: This is the Ship class file. It holds all the various objects
 ** derived from the Space class and creates a spaceship out of them.
 ** Input: none
 ** Output: Ship Prototype
 ***************************************************************************************/

#ifndef SHIP_HPP
#define SHIP_HPP

#include "CargoBay.hpp"
#include "EscapePod.hpp"
#include "Lab.hpp"
#include "Bridge.hpp"
#include "ControlRoom.hpp"

class Ship
{

   protected:

      Space* ePod1;
      Space* ePod2;
      Space* ePod3;
      Space* ePod4;
      Space* ePod5;

      Space* cargo;
      Space* bridge1;
      Space* bridge2;
      Space* lab;
      Space* control;

      Space* currentRoom;

   public:

      Ship();

      void setShip();

      Space* getCurrent();
      void setCurrent(Space*);

};

#endif
