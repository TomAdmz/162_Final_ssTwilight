/***************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Thomas Adamcewicz
 ** Date: 3/14/16
 ** Description: This is the Die class implementation file. 
 ** It has a default constructor that sets sides to 0. 
 ** It has get and set functions for the sides and also a roll function that
 ** generates and returns a random number from 1 to the number of sides it has.
 ** Input: n/a
 ** Output: Die object functions.
 ***************************************************************************************/

#include "Die.hpp"
#include <cstdlib>

/********************************************************************
 ** Function: Die()
 ** Description: This is the default constructor, it sets sides to 0.
 ** Parameters: none
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 ********************************************************************/
Die::Die() 
{
   sides = 0;
}

/********************************************************************
 ** Function: setSides()
 ** Description: This function sets the size data member to the int
 ** that is passed. 
 ** Parameters: int for numSides 
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 ********************************************************************/
void Die::setSides(int numSides) 
{
   sides = numSides;
}

/********************************************************************
 ** Function: getSides()
 ** Description: This function returns the value of the objects sides.
 ** Parameters: none
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 ********************************************************************/
int Die::getSides() 
{
   return sides;
}

/********************************************************************
 ** Function: roll()
 ** Description: This function generates a random number from 1 to
 ** the number of sides of the Dice object and returns that number.
 ** Parameters: none
 ** Pre-Conditions: srand() must be seeded in main function.
 ** Post-Conditions: n/a
 ********************************************************************/
int Die::roll() 
{
   int numSides = getSides();

   return (rand() % numSides + 1);
}
