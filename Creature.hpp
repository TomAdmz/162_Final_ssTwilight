/***************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Tom Adamcewicz
 ** Date: 3/14/16
 ** Description: This is the Creature base class. It holds data members for armor and
 ** strength points as well as a string for type. It holds all the prototypes for the
 ** functions used by the SpaceMarine and Alien classes.
 ** Input: none
 ** Output: Creature virtual prototype
 **************************************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "Die.hpp"
#include <string>

class Creature
{

   protected:

      int armor;
      int sp;

      std::string type;

   public:

      Creature();

      virtual int attack() = 0;
      virtual int defend() = 0;

      virtual void setSP(int) = 0;
      virtual int getSP() = 0;

      virtual int getArmor() = 0;
      virtual void addArmor(int) = 0;

      virtual std::string getType() = 0;

      virtual void checkBag() = 0;
      virtual void useItem(int) = 0;
      virtual void addItem(std::string) = 0;
      
      virtual void heal() = 0;

      virtual bool hasSunBlade() = 0;

};

#endif
