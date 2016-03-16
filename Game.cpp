/***************************************************************************************
 ** Program Filename: ssTwilight
 ** Author: Tom Adamcewicz
 ** Date: 3/14/16
 ** Description: This is the Game class header file. It has data members for a ship
 ** and a pointer to a SpaceMarine player, also an int for moves. This class runs the
 ** game and has the player interact with the various objects on the ship. 
 ** Input: User menu options
 ** Output: the ssTwilight game
 ***************************************************************************************/

#include "Game.hpp"
#include <iostream>
#include <cstdlib>


/********************************************************************
 ** Function: Game()
 ** Description: This is the default constructor for the Game. It
 ** sets the player to point to a new SpaceMarine, moves to 0
 ** and it initializes the ship's rooms.
 ** Parameters: none
 ** Pre-Conditions: SpaceMarine and Ship classes must be included.
 ** Post-Conditions: none.
 ********************************************************************/
Game::Game()
{
   player = new SpaceMarine;
   moves = 0;
   ship.setShip();
}


/********************************************************************
 ** Function: gameIntro()
 ** Description: This function introduces the game and gives a brief
 ** background.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *******************************************************************/
void Game::gameIntro()
{
   std::cout << "------GAME INITIALIZING------" << std::endl;
   std::cout << "Welcome to SS Twilight!" << std::endl;
   std::cout << "In this game, your spaceship has been invaded by aliens!";
   std::cout << std::endl;
   std::cout << "The status of the rest of the crew is unknown, but your";
   std::cout << std::endl;
   std::cout << "ship is off course and set to collide with a small planet";
   std::cout << std::endl;
   std::cout << "of peaceful creatures and invaluable resources";
   std::cout << std::endl;
   std::cout << "You must follow the advice of your AI companion" << std::endl;
   std::cout << "J1M1 in order to regain control of your ship"; 
   std::cout << std::endl;
   std::cout << "and avert a major catastrophe before its too late..." << std::endl;
   std::cout << "There is a Key Card somewhere on the ship that will" << std::endl;
   std::cout << "unlock the ship controls in the Control Room" << std::endl;
   std::cout << "Beware of the aliens, they are dangerous!" << std::endl;
   std::cout << "Good luck Space Marine!" << std::endl;
   std::cout << "** Make sure to observe each room to interact, get clues and items";
   std::cout << "**" << std::endl;
   std::cout << "** You have 20 moves before the ship crashes.. **" << std::endl;
   std::cout << "** Each time you move into a new room, that is 1 step **";
   std::cout << std::endl; 
   std::cout << "-----------------------------" << std::endl;
}


/********************************************************************
 ** Function: playGame()
 ** Description: This function plays the game, allowing the user to
 ** move, observe rooms, check their bag, and check their health. It
 ** also keeps track of how many moves they have left and displays
 ** during each turn.
 ** Pre-Conditions: none
 ** Post-Conditions: none
 ********************************************************************/ 
void Game::playGame()
{
   gameIntro();
   
   ship.getCurrent()->enterSpace();
   std::cout << "J1M1: Marine!! Wake up we are under attack!" << std::endl;
   std::cout << "J1M1: All escape pods were disabled we gotta get to the";
   std::cout << std::endl; 
   std::cout << "      next room and figure out how to get this ship back on track!";
   std::cout << std::endl;
   bool playing = true;
 
   char grader;
   std::cout << "Do you want grader hints? (y/n):";
   std::cin >> grader;

   if (grader == 'y' || grader == 'Y') {
      std::cout << "***HOW TO WIN***" << std::endl;
      std::cout << "- If you interact with the crate in the CargoBay 3 times";
      std::cout << std::endl;
      std::cout << "  you will get the Sun Blade, equip it and you are invincible";
      std::cout << std::endl;
      std::cout << "- You need some weapon equiped (Blaster Rifle or Sun Blade)";
      std::cout << std::endl;
      std::cout << "  in order to have a chance at defeating any aliens.";
      std::cout << std::endl;  
      std::cout << "- The Key Card is in Escape Pod  3 on the right";
      std::cout << "  in the South Bridge...however, it isn't required.";
      std::cout << std::endl;
      std::cout << "- The passcode is: 54321" << std::endl;
      std::cout << "- Enter that in the Control Room to win the game" << std::endl;

      std::cout << "***END  HINTS***" << std::endl;
   }

   while (playing) {

      int menuChoice;
      ship.getCurrent()->setPlayer(player);
     
      std::cout << "***You have " << 20 - moves << " moves left***";
      std::cout << std::endl;
  
      std::cout << "J1M1: What should we do?" << std::endl;
      std::cout << "-----MENU-----" << std::endl;
      std::cout << "1. Observe area" << std::endl;
      std::cout << "2. Leave Room" << std::endl;
      std::cout << "3. Check Bag" << std::endl;
      std::cout << "4. Check Health" << std::endl;

      std::cout << "J1M1: Enter the number of your choice: ";
      std::cin >> menuChoice;

      if (menuChoice == 1) {
         srand(time(NULL));
         int passCode;

         if (ship.getCurrent()->getType() == "Control Room") {
            ship.getCurrent()->observeSpace();
            ship.getCurrent()->specialInteract();
        
            std::cin >> passCode;
            if (passCode == 54321) {
               std::cout << "Computer: Access granted." << std::endl;
               std::cout << "J1M1: Good Job Marine!" << std::endl;
               std::cout << "J1M1: Lets get this ship back" << std::endl;
               std::cout << "      on course and go home!" << std::endl;
               wonGame();
               playing = false; 
            } else {
               std::cout << "Computer: Wrong.." << std::endl; 
            }
         } else {
            ship.getCurrent()->observeSpace();
            char specialAction;

            std::cout << "J1M1: Enter y for Yes or n for No" << std::endl;
            std::cin >> specialAction;
            if (specialAction == 'y' || specialAction == 'Y') {
               ship.getCurrent()->specialInteract();
            }
         }
      } else if (menuChoice == 2) {
         std::cout << "J1M1: Where would you like to go?";
         std::cout << std::endl;

         int roomChoice;

         if (ship.getCurrent()->nextPtr() != NULL) {
            std::cout << "1. Next Room: ";
            std::cout << ship.getCurrent()->getNext();
            std::cout << std::endl;
         } else {
            std::cout << "1. The next room is blocked." << std::endl;
         }

         if (ship.getCurrent()->lastPtr() != NULL) {
            std::cout << "2. Previous Room: ";
            std::cout << ship.getCurrent()->getLast();
            std::cout << std::endl;
         } else {
            std::cout << "2. The previous room is blocked." << std::endl;
         } 

         if (ship.getCurrent()->leftPtr() != NULL) {
            std::cout << "3. Left Room: ";
            std::cout << ship.getCurrent()->getLeft();
            std::cout << std::endl;
         } else {
            std::cout << "3. The room to the left is blocked." << std::endl;
         }

         if (ship.getCurrent()->rightPtr() != NULL) {
            std::cout << "4. Right Room: ";
            std::cout << ship.getCurrent()->getRight();
            std::cout << std::endl;
         } else {
            std::cout << "4. The room to the right is blocked." << std::endl;
         }
         std::cout << "5. Stay Here." << std::endl;

         std::cout << "J1M1: Enter the number you'd like to go to: ";
         std::cin >> roomChoice;

         if (roomChoice == 1) {
            if (ship.getCurrent()->nextPtr() != NULL) {
               ship.getCurrent()->leaveSpace();
               ship.setCurrent(ship.getCurrent()->nextPtr());
               ship.getCurrent()->enterSpace();
               moves++;
            } else {
               std::cout << "J1m1: You can't go there!" << std::endl;
            }
         } else if (roomChoice == 2) {
            if (ship.getCurrent()->lastPtr() != NULL) {
               ship.getCurrent()->leaveSpace();
               ship.setCurrent(ship.getCurrent()->lastPtr());
               ship.getCurrent()->enterSpace();
               moves++;
            } else {
               std::cout << "J1m1: You can't go there!" << std::endl;
            }
         } else if (roomChoice == 3) {
            if (ship.getCurrent()->leftPtr() != NULL) {
               ship.getCurrent()->leaveSpace();
               ship.setCurrent(ship.getCurrent()->leftPtr());
               ship.getCurrent()->enterSpace();
               moves++;
            } else {
               std::cout << "J1m1: You can't go there!" << std::endl;
            }
         } else if (roomChoice == 4) {
            if (ship.getCurrent()->rightPtr() != NULL) {
               ship.getCurrent()->leaveSpace();
               ship.setCurrent(ship.getCurrent()->rightPtr());
               ship.getCurrent()->enterSpace();
               moves++;
            } else {
               std::cout << "J1m1: You can't go there!" << std::endl;
            }
         }
      } else if (menuChoice == 3) {
         char useItem; 

         player->checkBag();
         std::cout << "J1M1: Would you like to use an item? (y/n) : ";
         std::cin >> useItem;

         if (useItem == 'y' || useItem == 'Y') {
            int itemNum; 
            std::cout << "Enter the number of the item you want to use: "; 
            std::cin >> itemNum;

            player->useItem(itemNum);
         }
     
      } else if (menuChoice == 4) {
         std::cout << "*****HEALTH*****" << std::endl;
         std::cout << "Health: " << player->getSP() << std::endl; 
         std::cout << "****************" << std::endl;
      }
       
      if (player->getSP() <= 0 || moves > 20) {
         std::cout << "You died...Mission failed..." << std::endl;
         std::cout << "*********GAME OVER********" << std::endl;
         playing = false;
      }
   }
}

/********************************************************************
 ** Function: wonGame()
 ** Description: congratulates player for winning game.
 ** Parameters: none
 ** Pre-Conditions: player must enter correct pass code.
 ** Post-Conditions: none
 *******************************************************************/ 
void Game::wonGame()
{
   std::cout << "---------------------------------------------" << std::endl;

   std::cout << "Congratulations! You saved the day yet again!" << std::endl;
   std::cout << "----------------GAME COMPLETED---------------" << std::endl;
}
