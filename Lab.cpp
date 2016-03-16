/****************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Tom Adamcewicz
 ** Date: 3/14/16
 ** Description: This is the Lab class, it is derived from the Space class and defines
 ** all of its virtual functions.
 ** Input: none
 ** Output: Lab prototype
 ***************************************************************************************/

#include "Lab.hpp"
#include <iostream>


/********************************************************************
 ** Function: Lab()
 ** Description: This is the default constructor, it sets all pointers
 ** to NULL, type to Lab and checked to 0.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions none
 ********************************************************************/
Lab::Lab()
{
   nextSpace = NULL;
   lastSpace = NULL;
   leftSpace = NULL;
   rightSpace = NULL;
  
   player = NULL; 
   type = "Lab";

   checked = 0;
}


/********************************************************************
 ** Function: setPlayer()
 ** Description: sets the player in the space.
 ** Parameters: SpaceMarine* to player.
 ** Pre-Conditions: none
 ** Post-Conditions: none
 ********************************************************************/
void Lab::setPlayer(SpaceMarine *playerIn)
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
void Lab::enterSpace()
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
void Lab::leaveSpace()
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
void Lab::setPtrs(Space* next, Space* last, Space* left, Space* right)
{
   nextSpace = next;
   lastSpace = last;
   leftSpace = left;
   rightSpace = right;
}


/********************************************************************
 ** Function: setPodNum()
 ** Description: this function does nothing for this class.
 *******************************************************************/ 
void Lab::setPodNum(int pNum)
{
   NULL;
}


/********************************************************************
 ** Function: setBridgeType()
 ** Description: not used with this class.
 *******************************************************************/
void Lab::setBridgeType(std::string bType)
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
std::string Lab::getType()
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
std::string Lab::getNext()
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
std::string Lab::getLast()
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
std::string Lab::getLeft()
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
std::string Lab::getRight()
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
Space* Lab::nextPtr()
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
Space* Lab::lastPtr()
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
Space* Lab::leftPtr()
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
Space* Lab::rightPtr()
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
void Lab::observeSpace()
{
   std::cout << "-----OBSERVING-----" << std::endl;
   if (checked == 0) {
      std::cout << "J1M1: There's a lot of experimental technology in here..";
      std::cout << std::endl;
      std::cout << "J1M1: Maybe we can find somehing useful.";
      std::cout << std::endl;
      std::cout << "J1M1: Should we check?" << std::endl;
   } else {
      std::cout << "J1M1: We already checked this room." << std::endl;
      std::cout << "J1M1: Should we check it again?" << std::endl;
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
void Lab::specialInteract()
{
   std::cout << "***INTERACTING***" << std::endl;
   if (checked == 0) {
      std::cout << "J1M1: There's Strike Armor here!" << std::endl;
      std::cout << "J1M1: That should make you a little stronger!" << std::endl;
      std::cout << "J1M1: Make sure to check your bag and use it to equip";
      std::cout << std::endl;
      player->addItem("Strike Armor");
      checked++;
   } else {
      std::cout << "J1M1: Nothing else of use in here.." << std::endl; 
   }
   std::cout << "*****************" << std::endl;
   std::cout << "-----------------" << std::endl;
}
