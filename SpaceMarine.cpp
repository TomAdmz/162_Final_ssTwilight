/***************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Tom Adamcewicz
 ** Date: 3/14/16
 ** Description: This is the SpaceMarine class, inherited from the Creature class. It
 ** has Die arrays for its attackDie and defenseDie, a vector of strings for its bag
 ** a bool if it has a sunBlade and an int for maxSP. It also includes special functions
 ** to interact with the items in its bag.
 ** Input: none
 ** Output: SpaceMarine object.
 ***************************************************************************************/

#include "SpaceMarine.hpp"
#include <iostream>


/********************************************************************
 ** Function: SpaceMarine()
 ** Description: This is the default constructor, it sides the sides
 ** of both Die arrays. It also sets all of the SpaceMarine attributes
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none 
 ********************************************************************/
SpaceMarine::SpaceMarine()
{
   attackDie[0].setSides(2);
   attackDie[1].setSides(2);

   defenseDie[0].setSides(6);
   defenseDie[1].setSides(6);

   armor = 0;
   sp = 10;
   maxSP = 10;
   sunBlade = false; 

   type = "Space Marine";
}

/********************************************************************
 ** Function: attack()
 ** Description: two int variables are set to the values of each
 ** attack Die roll() function. The sum of these rolls is returned.
 ** Parameters: none
 ** Pre-Conditions: Die must be set
 ** Post-Conditions: none
 *******************************************************************/
int SpaceMarine::attack()
{
   int roll1 = attackDie[0].roll();
   int roll2 = attackDie[1].roll();

   return roll1 + roll2;
}


/********************************************************************
 ** Function: defend()
 ** Description: similar to the attack() function, each Die is rolled
 ** the sum of those rolls is returned.
 ** Parameters: none
 ** Pre-Conditions: Die must be set
 ** Post-Conditions: none
 ********************************************************************/
int SpaceMarine::defend()
{
   int roll1 = defenseDie[0].roll();
   int roll2 = defenseDie[1].roll();

   return roll1 + roll2;
}


/********************************************************************
 ** Function: setSP()
 ** Description: This sets the sp value to the spIn int that is 
 ** passed in.
 ** Parameters: int for spIn
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
void SpaceMarine::setSP(int spIn)
{
   sp = spIn;
}


/********************************************************************
 ** Function: getSP()
 ** Description: This returns the value of sp
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
int SpaceMarine::getSP()
{
   return sp;
}

/********************************************************************
 ** Function: getArmor()
 ** Description: returns the value of armor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
int SpaceMarine::getArmor()
{
   return armor;
}


/********************************************************************
 ** Function: addArmor()
 ** Description: changes the value of the SpaceMarines armor.
 ** Parameters: an int for the new armor value.
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
void SpaceMarine::addArmor(int armorOn)
{
   armor = armorOn;
}

/********************************************************************
 ** Function: getType()
 ** Description: returns type value
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
std::string SpaceMarine::getType()
{
   return type;
}


/********************************************************************
 ** Function: checkBag()
 ** Description: Displays the strings held in the bag vector.
 ** Parameters: none
 ** Pre-Condtions: none
 ** Post-Conditions: none
 *******************************************************************/ 
void SpaceMarine::checkBag()
{
   std::cout << "-----Bag Contents-----" << std::endl;

   for (int i = 0; i < bag.size(); i++) {
      std::cout << i << ": " << bag.at(i) << std::endl;
   }
   
   std::cout << "----------------------" << std::endl;
}

/********************************************************************
 ** Function: useItem()
 ** Description: uses/views the item at the position passed in.
 ** Parameters: int for item position.
 ** Pre-Conditions: checkBag is ran first.
 ** Post-Conditions: update bag if item is removed.
 ********************************************************************/
void SpaceMarine::useItem(int itemPos)
{
   if (itemPos > (bag.size() - 1)) {
      std::cout << "--Invalid--" << std::endl;
   } else {
      if (bag.empty()) {
         std::cout << "Your bag is empty!" << std::endl;
      } else {
         if (bag.at(itemPos) == "Blaster Rifle") {
            attackDie[0].setSides(8);
            attackDie[1].setSides(8);
            std::cout << "***BLASTER EQUIPPED***" << std::endl;
            bag.erase(bag.begin() + itemPos);
         } else if (bag.at(itemPos) == "Stim Pack") {
            heal();
            bag.erase(bag.begin() + itemPos);
            std::cout << "***HEALING***" << std::endl;
            std::cout << "**HEALTH: " << sp;
            std::cout << "***" << std::endl;
         } else if (bag.at(itemPos) == "Sun Blade") {
            sunBlade = true;
            std::cout << "You hold the power of the Sun...";
            std::cout << std::endl; 
            bag.erase(bag.begin() + itemPos);
         } else if (bag.at(itemPos) == "Key Card") {
            std::cout << "The ship module code is: 54321";
            std::cout << std::endl;
         } else if (bag.at(itemPos) == "Strike Armor") {
            addArmor(5);
            std::cout << "You put the Strike Armor on and gained 5 armor!";
            std::cout << std::endl;
            bag.erase(bag.begin() + itemPos);
         } else if (bag.at(itemPos) == "Alien Crown") {
            std::cout << "This is a trophy for beating the alien's king!";
            std::cout << std::endl;
            std::cout << "J1M1: Looks pretty cool..." << std::endl;
         } 
      }
   }
   std::cout << "**********************" << std::endl;
}
 

/********************************************************************
 ** Function: addItem()
 ** Description: adds string "item" to vector bag.
 ** Parameters: string for the item
 ** Pre-Conditions: none
 ** Post-Conditions: must add item.
 *******************************************************************/ 
void SpaceMarine::addItem(std::string itemIn){
   if (bag.size() == 5) {
      std::cout << "Bag is full!" << std::endl;
   } else {
      bag.push_back(itemIn);
   }
}


/********************************************************************
 ** Function: heal()
 ** Description: heals the SpaceMarine for 1/3 of their health.
 ** Parameters: none
 ** Pre-Conditions: stimpack must be used.
 ** Post-Conditions: none
 *******************************************************************/ 
void SpaceMarine::heal()
{
   int heals = maxSP/3;

   if (heals + sp > 10) {
      sp = 10;
   } else {
      sp = heals + sp;
   }

}


/********************************************************************
 ** Function: hasSunBlade()
 ** Description: returns true if the player has the Sun Blade.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/ 
bool SpaceMarine::hasSunBlade()
{
   if (sunBlade == true) {
      return true;
   } else {
      return false;
   }
}

