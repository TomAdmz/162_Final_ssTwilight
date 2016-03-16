/***************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Tom Adamcewicz
 ** Date: 3/14/16
 ** Description: This is the Alien class, it inherits from the Creature class. It holds
 ** 2 array data members for an attackDie and a defenseDie. It has functions to attack
 ** and defend as well as getters and setters for its inherited data.
 ** Input: none
 ** Output: Alien prototype
 **************************************************************************************/

#ifndef ALIEN_HPP
#define ALIEN_HPP

#include "Creature.hpp"

class Alien : public Creature
{

   protected:

      Die attackDie[2];
      Die defenseDie[2];

   public:

      Alien();

      int attack();
      int defend();

      void setSP(int);
      int getSP();

      int getArmor();
      void addArmor(int);

      std::string getType();

      void checkBag();
      void useItem(int);
      void addItem(std::string);

      void heal();

      bool hasSunBlade();

};

#endif
      
