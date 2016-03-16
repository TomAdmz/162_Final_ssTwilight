/***************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Tom Adamcewicz
 ** Date: 3/14/16
 ** Description: This is the EscapePod class file. It's derived from the Space class
 ** it defines all virtual functions and has a data member for podNum which numbers
 ** each escape pod object.
 ** Input: none
 ** Output: EscapePod object.
 **************************************************************************************/


#include "EscapePod.hpp"
#include <iostream>
#include "Alien.hpp"


/********************************************************************
 ** Function: EscapePod()
 ** Description: This is the default constructor, sets all pointers
 ** to NULL, podNum to 1, type to escape pod, player to NULL and
 ** checked to 0.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
EscapePod::EscapePod()
{
   nextSpace = NULL;
   lastSpace = NULL;
   leftSpace = NULL;
   rightSpace = NULL;

   podNum = 1;

   type = "Escape Pod";

   player = NULL;

   checked = 0;
}


/********************************************************************
 ** Function: setPlayer()
 ** Description: sets the player in the space.
 ** Parameters: SpaceMarine* to player.
 ** Pre-Conditions: none
 ** Post-Conditions: none
 ********************************************************************/ 
void EscapePod::setPlayer(SpaceMarine *playerIn)
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
void EscapePod::enterSpace()
{
   std::cout << "********************************" << std::endl; 
   std::cout << "You have entered an " << type << std::endl;
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
void EscapePod::leaveSpace()
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
void EscapePod::setPtrs(Space* next, Space* last, Space* left, Space* right)
{
   nextSpace = next;
   lastSpace = last;
   leftSpace = left;
   rightSpace = right;
}


/*******************************************************************
 ** Function: setPodNum()
 ** Description: sets the escape pod number.
 ** Parameters: int for podNum
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/ 
void EscapePod::setPodNum(int podNumIn)
{
   podNum = podNumIn;
}


/********************************************************************
 ** Function: setBridgeType()
 ** Description: not used with this class.
 *******************************************************************/ 
void EscapePod::setBridgeType(std::string bType)
{
   NULL;
}


/******************************************************************
 ** Function: getType()
 ** Description: returns the type and pod number.
 ** Paramters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
std::string EscapePod::getType()
{
   if (podNum == 2) {
      return "Escape Pod 2";
   } else if (podNum == 3) {
      return "Escape Pod 3";
   } else if (podNum == 4) {
      return "Escape Pod 4";
   } else if (podNum == 5) {
      return "Escape Pod 5";
   } else {
      return type;
   }
}


/******************************************************************
 ** Function: getNext()
 ** Description: returns the next Space type.
 ** Paramters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
std::string EscapePod::getNext()
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
std::string EscapePod::getLast()
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
std::string EscapePod::getLeft()
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
std::string EscapePod::getRight()
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
Space* EscapePod::nextPtr()
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
Space* EscapePod::lastPtr()
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
Space* EscapePod::leftPtr()
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
Space* EscapePod::rightPtr()
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
void EscapePod::observeSpace()
{
   std::cout << "-----OBSERVING-----" << std::endl;
   if (checked == 0) {
      if (podNum == 3) {
         std::cout << "J1M1: Ooo not a pretty sight in here.." << std::endl;
         std::cout << "J1M1: I think I see the Key Card, lets grab it!";
         std::cout << std::endl;
      } else if (podNum == 4) {
         std::cout << "J1M1: I think I see someone in here" << std::endl;
         std::cout << "J1M1: Should we check on them?" << std::endl;
      } else {
         std::cout << "J1M1: Not much going on in here..." << std::endl;
         std::cout << "J1M1: Maybe there's an item in here." << std::endl;
         std::cout << "J1M1: Should we look?" << std::endl;
      }
   } else {
      std::cout << "J1M1: I think we got everything here." << std::endl; 
      std::cout << "J1M1: Should we still check it out?" << std::endl;
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
void EscapePod::specialInteract()
{
   std::cout << "***INTERACTING***" << std::endl;
   if (checked == 0) {
      if (podNum == 3) {
         player->addItem("Key Card");
         std::cout << "J1M1: View the Key Card by using it.." << std::endl;
         std::cout << "J1M1: Now lets get to the Control Room!" << std::endl;
         checked++;
      } else if (podNum == 4) {
         std::cout << "J1M1: That's not someone..its SOME THING!" << std::endl;
         
         Alien alien;
         alien.setSP(20);
         alien.addArmor(3); 
         std::cout << "J1M1: This one looks a little bigger..." << std::endl;
         std::cout << "J1M1: Looks like we gotta fight..." << std::endl; 
         bool fight = true;
      
         while (fight) {
            if (player->hasSunBlade()) {
               std::cout << "**You cut through the alien!**" << std::endl;
               std::cout << "J1M1: Good job lets get outta here!" << std::endl;
               std::cout << "**You pick up Alien Crown**" << std::endl;
               player->addItem("Alien Crown");
               checked++;
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
                  std::cout << "**You pick up Alien Crown**" << std::endl;
                  player->addItem("Alien Crown");
                  checked++;
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
                     checked++;
                     fight = false;
                  }
               }
            }
         }
      } else {
         player->addItem("Stim Pack");
         std::cout << "J1M1: Nice, we found a Stim Pack!" << std::endl;
         std::cout << "J1M1: Use it when you are low on health to heal!" << std::endl;
         checked++;
      }
   } else {
      std::cout << "J1M1: Yup, it's empty." << std::endl; 
   }
   std::cout << "*****************" << std::endl; 
   std::cout << "-----------------" << std::endl;
}

