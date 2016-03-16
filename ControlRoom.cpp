/***************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Tom Adamcewicz
 ** Date: 3/14/16
 ** Description: This is the ControlRoom class file, it is derived from the Space class
 ** and defines all of its virtual functions.
 ** Input: none
 ** Output: ControlRoom object
 ***************************************************************************************/

#include "ControlRoom.hpp"
#include <iostream>


/********************************************************************
 ** Function: ControlRoom()
 ** Description: this sets all pointers to NULL, type to Control Room
 ** and checked to 0.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
ControlRoom::ControlRoom()
{
   nextSpace = NULL;
   lastSpace = NULL;
   leftSpace = NULL;
   rightSpace = NULL;
  
   player = NULL; 
   type = "Control Room";
   checked = 0;
}


/********************************************************************
 ** Function: setPlayer()
 ** Description: sets the player in the space.
 ** Parameters: SpaceMarine* to player.
 ** Pre-Conditions: none
 ** Post-Conditions: none
 ********************************************************************/
void ControlRoom::setPlayer(SpaceMarine *playerIn)
{
   player = playerIn;
}


/********************************************************************
 ** Function: enterSpace()
 ** Description: this function is displayed when the player
 ** enters this space.
 ** Parameters: none
 ** Pre-Conditions: player moves into the Space
 ** Post-Conditions: none
 *******************************************************************/
void ControlRoom::enterSpace()
{ 
   std::cout << "********************************" << std::endl; 
   std::cout << "You have entered the " << type << std::endl;
   std::cout << "********************************" << std::endl;
}


/********************************************************************
 ** Function: leaveSpace()
 ** Description: this function is displayed when the player leaves
 ** this space.
 ** Parameters: none
 ** Pre-Conditions: player leaves a Space
 ** Post-Conditions: none
 *******************************************************************/
void ControlRoom::leaveSpace()
{ 
   std::cout << "********************************" << std::endl; 
   std::cout << "You're leaving the " << type << std::endl;
   std::cout << "********************************" << std::endl;
}


/********************************************************************
 ** Function: setPtrs()
 ** Description: sets the 4 Space pointers for the object.
 ** Parameters: 4 Space* for each connecting room.
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
void ControlRoom::setPtrs(Space* next, Space* last, Space* left, Space* right)
{  
   nextSpace = next;
   lastSpace = last;
   leftSpace = left;
   rightSpace = right;
}


/********************************************************************
 ** Function: setPodNum()
 ** Description: not used with this class.
 *******************************************************************/
void ControlRoom::setPodNum(int pNum)
{
   NULL;
}


/********************************************************************
 ** Function: setBridgeType()
 ** Description: not used with this class.
 *******************************************************************/
void ControlRoom::setBridgeType(std::string bType)
{
   NULL;
}


/******************************************************************
 ** Function: getType()
 ** Description: returns the type.
 ** Paramters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
std::string ControlRoom::getType()
{
   return type;
}


/******************************************************************
 ** Function: getNext()
 ** Description: returns the next Space type.
 ** Paramters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
std::string ControlRoom::getNext()
{
   return nextSpace->getType();
}


/******************************************************************
 ** Function: getLast()
 ** Description: returns the Last Space type.
 ** Paramters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
std::string ControlRoom::getLast()
{
   return lastSpace->getType();
}


/******************************************************************
 ** Function: getLeft()
 ** Description: returns the left Space type.
 ** Paramters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
std::string ControlRoom::getLeft()
{
   return leftSpace->getType();
}


/******************************************************************
 ** Function: getRight()
 ** Description: returns the right Space type.
 ** Paramters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
std::string ControlRoom::getRight()
{
   return rightSpace->getType();
}


/******************************************************************
 ** Function: nextPtr()
 ** Description: returns the next Space pointer.
 ** Paramters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
Space* ControlRoom::nextPtr()
{
   return nextSpace;
}


/******************************************************************
 ** Function: lastPtr()
 ** Description: returns the last Space pointer.
 ** Paramters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
Space* ControlRoom::lastPtr()
{
   return lastSpace;
}


/******************************************************************
 ** Function: leftPtr()
 ** Description: returns the left Space pointer.
 ** Paramters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
Space* ControlRoom::leftPtr()
{
   return leftSpace;
}


/******************************************************************
 ** Function: rightPtr()
 ** Description: returns the right Space pointer.
 ** Paramters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
Space* ControlRoom::rightPtr()
{
   return rightSpace;
}


/********************************************************************
 ** Function: observeSpace()
 ** Description: observes the current space, to find items, aliens
 ** and clues.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
void ControlRoom::observeSpace()
{
   std::cout << "-----OBSERVING-----" << std::endl;
   if (checked == 0) {
      std::cout << "J1M1: The ship controls are in here but we need the Key Card...";
      std::cout << std::endl;
      std::cout << "J1M1: Let me see if I can find some clues for us....";
      std::cout << std::endl;
      std::cout << "***CHECKING SHIP LOGS***" << std::endl;
      std::cout << "J1M1: It looks like the Key Card was last used in one of the";
      std::cout << std::endl;
      std::cout << "      Escape Pods attached to one of the ship's Bridges...";
      std::cout << std::endl;
      std::cout << "      Quick! We need to check them and find the Key Card!";
      std::cout << std::endl;
   } else { 
      std::cout << "J1M1: Quick get to the computer and enter the code!" << std::endl;
   }
}



/********************************************************************
 ** Function: specialInteract()
 ** Description: interacts with the Space to pick up items or fight
 ** aliens.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: updates checked variable
 *******************************************************************/
void ControlRoom::specialInteract()
{
   std::cout << "***INTERACTING***" << std::endl;
   if (checked == 0) {
      std::cout << "J1M1: We'll come back when we have the Key Card.." << std::endl;
      checked++;
      std::cout << "Enter 1 to continue:" << std::endl;
   } else {
      std::cout << "Computer: Please enter passcode.." << std::endl;
      std::cout << "---------------" << std::endl;
   }
   std::cout << "****************" << std::endl;
}
 
