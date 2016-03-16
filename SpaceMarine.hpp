/***************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Tom Adamcewicz
 ** Date: 3/14/16
 ** Description: This is the SpaceMarine class, inherited from the Creature class. It
 ** has Die arrays for its attackDie and defenseDie, a vector of strings for its bag
 ** a bool if it has a sunBlade and an int for maxSP. It also includes special functions
 ** to interact with the items in its bag.
 ** Input: none
 ** Output: SpaceMarine prototype
 ***************************************************************************************/ 

#ifndef SPACEMARINE_HPP
#define SPACEMARINE_HPP

#include "Creature.hpp"
#include <vector>

class SpaceMarine : public Creature
{

   protected:

      Die attackDie[2];
      Die defenseDie[2];

      std::vector<std::string> bag;
      bool sunBlade;
      int maxSP;

   public:

      SpaceMarine();

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
 
