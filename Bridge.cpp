/***************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Tom Adamcewicz
 ** Date: 3/14/16
 ** Description: This is the Bridge class file, it is derived from the Space class
 ** and inherits all of its functions. It also has a data member bool called wonFight
 ** which returns true after the player defeats the alien.
 ** Input: none
 ** Output: Bridge object
 ***************************************************************************************/

#include "Bridge.hpp"
#include "Alien.hpp"
#include <iostream>


/********************************************************************
 ** Function: Bridge()
 ** Description: This is the default constructor, it sets all
 ** pointers to NULL, type to Bridge and wonFight to false
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
Bridge::Bridge()
{
   nextSpace = NULL;
   lastSpace = NULL;
   leftSpace = NULL;
   rightSpace = NULL;

   player = NULL;
   type = "Bridge";

   wonFight = false;
}


/********************************************************************
 ** Function: setPlayer()
 ** Description: sets the player in the space.
 ** Parameters: SpaceMarine* to player.
 ** Pre-Conditions: none
 ** Post-Conditions: none
 ********************************************************************/
void Bridge::setPlayer(SpaceMarine *playerIn)
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
void Bridge::enterSpace()
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
void Bridge::leaveSpace()
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
void Bridge::setPtrs(Space* next, Space* last, Space* left, Space* right)
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
void Bridge::setPodNum(int pNum)
{
   NULL;
}


/********************************************************************
 ** Function: setBridgeType
 ** Description: sets a unique type for each Bridge.
 ** Parameters: string for bridge type
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/ 
void Bridge::setBridgeType(std::string bridgeType)
{
   type = bridgeType;
} 


/******************************************************************
 ** Function: getType()
 ** Description: returns the type.
 ** Paramters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
std::string Bridge::getType()
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
std::string Bridge::getNext()
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
std::string Bridge::getLast()
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
std::string Bridge::getLeft()
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
std::string Bridge::getRight()
{
   return rightSpace->getType();
}


/******************************************************************
 ** Function: nextPtr()
 ** Description: returns the next Space pointer if wonFight is true.
 ** Paramters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
Space* Bridge::nextPtr()
{
   if (!wonFight) {
      return NULL;
   } else {
      return nextSpace;
   }
}


/******************************************************************
 ** Function: lastPtr()
 ** Description: returns the last Space pointer if wonFight is true.
 ** Paramters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
Space* Bridge::lastPtr()
{
   if (!wonFight) {
      return NULL;
   } else {
      return lastSpace;
   }
}


/******************************************************************
 ** Function: leftPtr()
 ** Description: returns the left Space pointer if wonFight is true.
 ** Paramters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
Space* Bridge::leftPtr()
{
   if (!wonFight) {
      return NULL;
   } else {
      return leftSpace;
   }
}


/******************************************************************
 ** Function: rightPtr()
 ** Description: returns the right Space pointer if wonFight is true.
 ** Paramters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
Space* Bridge::rightPtr()
{
   if (!wonFight) {
      return NULL;
   } else {
      return rightSpace;
   }
}


/********************************************************************
 ** Function: observeSpace()
 ** Description: observes the current space, to find items, aliens
 ** and clues.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/ 
void Bridge::observeSpace()
{
   std::cout << "-----OBSERVING-----" << std::endl;
   if (wonFight) {
      std::cout << "J1M1: Looks like nothing to do here.." << std::endl;
      std::cout << "J1M1: Still want to check it out?" << std::endl;
   } else { 
      std::cout << "J1M1: It looks like there's an alien ahead.." << std::endl;
      std::cout << "J1M1: We have to defeat it to move on, are you ready?";
      std::cout << std::endl;
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
void Bridge::specialInteract()
{
   std::cout << "***INTERACTING***" << std::endl;
   if (wonFight) {
      std::cout << "J1M1: We did everything we needed to do here";
      std::cout << "      lets go!" << std::endl;
      std::cout << "---------------" << std::endl;
   } else {

      Alien alien;
      std::cout << "J1M1: Here we go!" << std::endl;
      bool fight = true;

      while (fight) {
         if (player->hasSunBlade()) {
            std::cout << "**You cut through the alien!**" << std::endl;
            std::cout << "J1M1: Good job lets keep moving!" << std::endl;
            wonFight = true;
            fight = false;
         } else {
            int marineAttack = player->attack();
            int alienDefend = alien.defend() + alien.getArmor();
            int alienDamage = marineAttack - alienDefend;

            if (alienDamage > 0) {
               alien.setSP(alien.getSP() - alienDamage);
            }

            if (alien.getSP() <= 0) {
               std::cout << "**You blast the alien away!**" << std::endl;
               std::cout << "**Player Health: " << player->getSP();
               std::cout << "**" << std::endl;
               std::cout << "J1M1: Good job Marine, lets go!" << std::endl;
               wonFight = true;
               fight = false;
            } else {
               int alienAttack = alien.attack();
               int marineDefend = player->defend() + player->getArmor();
               int marineDamage = alienAttack - marineDefend;

               if (marineDamage > 0) {
                  player->setSP(player->getSP() - marineDamage);
               }

               if (player->getSP() <= 0) {
                  std::cout << "J1M1: Oh dear..." << std::endl;
                  fight = false;
               }
            }
         }
      }
   }
   std::cout << "*****************" << std::endl;
}
