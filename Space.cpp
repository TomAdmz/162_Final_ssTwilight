/***************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Tom Adamcewicz
 ** Date: 3/14/16
 ** Description: This is the Space parent class. It defines all the virtual functions
 ** for the classes derived from it. It has data members for 4 pointers to other spaces
 ** a string for type a pointer to a SpaceMarine for player and an int for checked
 ** if a Space has been checked. 
 ** Input: none
 ** Output: Space object
 **************************************************************************************/

#include "Space.hpp"
#include <cstdlib>

Space::Space()
{
    nextSpace = NULL;
    lastSpace = NULL;
    leftSpace = NULL;
    rightSpace = NULL;

    player = NULL;

    checked = 0;
}

