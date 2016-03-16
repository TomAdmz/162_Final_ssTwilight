/***************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Thomas Adamcewicz
 ** Date: 3/14/16
 ** Description: This is the Die class header file, it includes the protected data
 ** member for its number of sides. It has a default constructor that sets sides 
 ** to 0. It has get and set functions for the sides and also a roll function that
 ** generates and returns a random number from 1 to the number of sides it has.
 ** Input: n/a
 ** Output: Die object prototypes.
***************************************************************************************/

#ifndef DIE_HPP
#define DIE_HPP


class Die 
{
   protected:
      int sides;

   public:
      Die();
   
      void setSides(int);
      int getSides();

      int roll();

};

#endif
