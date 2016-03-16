/***************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Tom Adamcewicz
 ** Date: 3/14/16
 ** Description: This is the Alien class, it inherits from the Creature class. It holds
 ** 2 array data members for an attackDie and a defenseDie. It has functions to attack
 ** and defend as well as getters and setters for its inherited data.
 ** Input: none
 ** Output: Alien object
 **************************************************************************************/

#include "Alien.hpp"


/********************************************************************
 ** Function: Alien()
 ** Description: This is the default constructor it sets the Alien's
 ** data members to the appropriate values.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
Alien::Alien()
{
   attackDie[0].setSides(6);
   attackDie[1].setSides(6);

   defenseDie[0].setSides(6);
   defenseDie[1].setSides(6);

   armor = 0;
   sp = 12;

   type = "Alien";
}

/********************************************************************
 ** Function: attack()
 ** Description: two int variables are set to the values of each
 ** attack Die roll() function. The sum of these rolls is returned.
 ** Parameters: none
 ** Pre-Conditions: Die must be set
 ** Post-Conditions: none
 *******************************************************************/
int Alien::attack()
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
int Alien::defend()
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
void Alien::setSP(int spIn)
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
int Alien::getSP()
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
int Alien::getArmor()
{
   return armor;
}


/********************************************************************
 ** Function: addArmor()
 ** Description: updates the armor value to the armor passed in.
 ** Parameters: int for armor to be added
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
void Alien::addArmor(int armorOn)
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
std::string Alien::getType()  
{
   return type;
}

/********************************************************************
 ** Function: checkBag()
 ** Description: this function does nothing for the Alien.
 *******************************************************************/
void Alien::checkBag()
{
   NULL;
}


/********************************************************************
 ** Function: useItem()
 ** Description: this function does nothing for the Alien.
 *******************************************************************/
void Alien::useItem(int itemPos)
{
   NULL;
}

/********************************************************************
 ** Function: addItem()
 ** Description: this function does nothing for the Alien.
 *******************************************************************/
void Alien::addItem(std::string itemIn)
{
   NULL;
}


/********************************************************************
 ** Function: heal()
 ** Description: this function does nothing for the Alien.
 *******************************************************************/
void Alien::heal()
{
   NULL;
}

/********************************************************************
 ** Function: hasSunBlade()
 ** Description: this function does nothing for the Alien.
 *******************************************************************/
bool Alien::hasSunBlade()
{
   return false;
}
