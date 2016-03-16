/***************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Tom Adamcewicz
 ** Date: 3/14/16
 ** Description: This is the Ship class file. It holds all the various objects
 ** derived from the Space class and creates a spaceship out of them.
 ** Input: none
 ** Output: Ship object.
 ***************************************************************************************/

#include "Ship.hpp"
#include <cstdlib>

/********************************************************************
 ** Function: Ship()
 ** Description: This is the default constructor. It sets all of the
 ** Space* pointers to point to the appropriate objects and then
 ** sets the current pointer to the first escape pod.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/ 
Ship::Ship()
{
   ePod1 = new EscapePod;
   ePod2 = new EscapePod;
   ePod3 = new EscapePod;
   ePod4 = new EscapePod;
   ePod5 = new EscapePod;

   cargo = new CargoBay;
   bridge1 = new Bridge;
   bridge2 = new Bridge;
   lab = new Lab;
   control = new ControlRoom;

   currentRoom = ePod1;
}

/********************************************************************
 ** Function: setShip()
 ** Description: This function sets the pointers for each room in the
 ** ship in order to connect all the rooms together. It also sets
 ** the names of the two bridges and 5 escape pods.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 ********************************************************************/
void Ship::setShip()
{
   ePod1->setPtrs(cargo, NULL, NULL, NULL);
   cargo->setPtrs(bridge1, ePod1, NULL, NULL);
   bridge1->setPtrs(lab, cargo, ePod2, ePod3);
   bridge1->setBridgeType("South Bridge");
   lab->setPtrs(bridge2, bridge1, NULL, NULL);
   bridge2->setPtrs(control, lab, ePod4, ePod5);
   bridge2->setBridgeType("North Bridge");
   control->setPtrs(NULL, bridge2, NULL, NULL);

   ePod2->setPtrs(NULL, bridge1, NULL, NULL);
   ePod2->setPodNum(2);
   ePod3->setPtrs(NULL, bridge1, NULL, NULL);
   ePod3->setPodNum(3);
   ePod4->setPtrs(NULL, bridge2, NULL, NULL);
   ePod4->setPodNum(4);
   ePod5->setPtrs(NULL, bridge2, NULL, NULL);
   ePod5->setPodNum(5);

}


/********************************************************************
 ** Function: getCurrent()
 ** Description: returns the current Space that the player is in.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 ********************************************************************/ 
Space* Ship::getCurrent()
{
   return currentRoom;
}


/********************************************************************
 ** Function: setCurrent()
 ** Description: sets the current space where the player is.
 ** Parameters: a Space* for the new current room.
 ** Pre-Conditions: none
 ** Post-Conditions: none
 ********************************************************************/
void Ship::setCurrent(Space* nextRoom)
{
   currentRoom = nextRoom;
}
