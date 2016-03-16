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


#include "Creature.hpp"
#include <cstdlib>


/********************************************************************
 ** Function: Creature()
 ** Description: This sets armor and sp to NULL and type to an empty
 ** string.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/ 
Creature::Creature()
{
   armor = NULL;
   sp = NULL;
 
   type = "";
} 
