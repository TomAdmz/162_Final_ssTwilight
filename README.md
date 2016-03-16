# 162_Final_ssTwilight
Text based game made for CS 162 Final project

This is a text based game made for my final project. 

Language: c++
Concepts: Polymorphism, Inheritance, Linked Lists, Pointers
Features:
  - Die class
    - can set sides
    - roll function returns random number based on sides
  - A Creature class with two derived classes:
    - Attributes: sp (health), armor, attackDie, defenseDie 
    - SpaceMarine: player class
      - has a bag for items (vector of strings)
      - can use/add items which affect attributes
    - Alien: AI class
  - Space class with 5 derived classes:
    - CargoBay, EscapePod, Lab, Bridge and ControlRoom
    - Each Space child has its own special function for special actions (items, fights, etc.)
    - Each Space has 4 pointers to other Spaces or NULL
    - Certain rooms contain Alien objects which the player has to fight to continue
  - Ship class
    - Container of Space*
    - Creates the layout of the Ship by connecting respective Spaces
  - Game class
    - Creates a Ship and a SpaceMarine player
    - has the player interact with the Ship to reach final goal
    - Provide instructions to player
    - Menu driven: observe room, leave room, check bag, check health.

Game Description:
  In this game you are a Space Marine and your space ship (the SS Twilight) has been attacked by aliens. You wake up in an escape pod at the end of the ship. Your AI companion informs you the escape pods have been disabled, the crew is gone and the aliens are attacking. The ship is off course and set to collide with a nearby planet which would destroy the ship and much of the planet. You must fight your way through the ship to find a "Key Card" which has a passcode to get into the computer in the Control Room and set the ship back on course. You have 20 moves before the ship crashed(each time you leave a room, that is 1 move). 
