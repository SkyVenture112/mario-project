#include <iostream>
#include <time.h>
#include <cstdlib>

#include "Mario.h"



  Mario::Mario() { // Default Mario constructor 

    numOfLives = 0;

    numOfCoins = 0;
  
    powerLevel = 0;

    numberOfMovements = 0;

    x = 0;

    y = 0;

    enemiesDefeated = 0;

    currentLevel = 0;

    finalBossDefeated = false;

    action = "";

    nextDirection = "";
  
  }

      

  Mario::Mario(int lives, int coins, int power, int moves, int xPosition, int yPosition, int enemies, int level, bool enemy, bool boss, std::string actionString, std::string directionString) { // Overloaded Mario constructor 
  
      numOfLives = lives;
  
      numOfCoins = coins;
    
      powerLevel = power;

      numberOfMovements = moves;

      x = xPosition;

      y = yPosition;

      enemiesDefeated = enemies;

      currentLevel = level;

      enemyDefeated = enemy; 

      finalBossDefeated = boss;

      action = actionString;

      nextDirection = directionString;

    
  }



  Mario::~Mario() { // Mario destructor 

    
  }



  int Mario::getNumOfLives() {  // Returns Mario's number of lives remanining

    return numOfLives;
    
  }



  int Mario::getNumOfCoins() { // Returns Mario's number of coins

    return numOfCoins;
    
  }



  int Mario::getPowerLevel() { // Returns Mario's current power level (0, 1, or 2)

    return powerLevel;
    
  }



  int Mario::getMovements() { // Returns Mario's current number of movements
  
      return numberOfMovements;
      
    }


  int Mario::getXPosition() { // Returns Mario's current x position

    return x;
    
  }


  int Mario::getYPosition() { // Returns Mario's current y position

    return y;
    
  }



  int Mario::getEnemiesDefeated() { // Returns Mario's current number of enemies defeated

    return enemiesDefeated;
    
  }



  int Mario::getCurrentLevel() { // Returns Mario's current level

    return currentLevel;
    
  }



  bool Mario::getFinalBossDefeated() { // Returns whether or not the final boss has been defeated

    return finalBossDefeated;
    
  }


  std::string Mario::getAction() { // Returns Mario's current action

    return action;
    
  }


  std::string Mario::getNextDirection() { // Returns Mario's next movement direction

    return nextDirection;
    
  }




  void Mario::setNumOfLives(int lives) { // Sets Mario's number of lives

    numOfLives = lives;
    
  }



  void Mario::setNumOfCoins(int coins) { // Sets Mario's number of coins

    numOfCoins = coins;
    
  }



  void Mario::setPowerLevel(int power) { // Sets Mario's power level
 
    powerLevel = power;
    
  }


  void Mario::setEnemiesDefeated(int enemies) { // Sets Mario's number of enemies defeated

    enemiesDefeated = enemies;
    
  }


  void Mario::setCurrentLevel(int level) { // Sets Mario's current level

    currentLevel = level;
    
  }







   void Mario::moveRight(World* world) { // Moves the Mario character representation on the world map one space to the right (or loops back around if it is on the edge of the map)

    if (y + 1 <= (world -> getDimension() - 1)) {

      if (world -> getWorldMap()[currentLevel][x][y] == 'b' && enemyDefeated == false) {

        world -> getWorldMap()[currentLevel][x][y] = 'b';

         y = y + 1;

        interact(world);
      
        world -> getWorldMap()[currentLevel][x][y] = 'H';
        
      }


      else {
    
        world -> getWorldMap()[currentLevel][x][y] = 'x'; 
  
        y = y + 1;
  
        interact(world);
        
        world -> getWorldMap()[currentLevel][x][y] = 'H';
        
      }

    }

    else {

       if (world -> getWorldMap()[currentLevel][x][y] == 'b' && enemyDefeated == false) {

        world -> getWorldMap()[currentLevel][x][y] = 'b';

         y = world -> getDimension() - 1;

        interact(world);
      
        world -> getWorldMap()[currentLevel][x][y] = 'H';
        
      }


      else {
        
        world -> getWorldMap()[currentLevel][x][y] = 'x'; 
  
         y = world -> getDimension() - 1;
  
        interact(world);
  
        world -> getWorldMap()[currentLevel][x][y] = 'H';
        
      }
      
    }

    nextDirection = "Right";
    
      
  }






    void Mario::moveLeft(World* world) { // Moves the Mario character representation on the world map one space to the left (or loops back around if it is on the edge of the map)

    if (y - 1 >= 0) {

      if (world -> getWorldMap()[currentLevel][x][y] == 'b' && enemyDefeated == false) {

         world -> getWorldMap()[currentLevel][x][y] = 'b';

         y = y - 1;

        interact(world);
      
        world -> getWorldMap()[currentLevel][x][y] = 'H';
        
      }


      else {
    
        world -> getWorldMap()[currentLevel][x][y] = 'x'; 
  
        y = y - 1;
  
        interact(world);
        
        world -> getWorldMap()[currentLevel][x][y] = 'H';
        
      }

    }

    else {

       if (world -> getWorldMap()[currentLevel][x][y] == 'b' && enemyDefeated == false) {

        world -> getWorldMap()[currentLevel][x][y] = 'b';

         y = world -> getDimension() - 1;

        interact(world);
      
        world -> getWorldMap()[currentLevel][x][y] = 'H';
        
      }


      else {
        
        world -> getWorldMap()[currentLevel][x][y] = 'x'; 
  
         y = world -> getDimension() - 1;
  
        interact(world);
  
        world -> getWorldMap()[currentLevel][x][y] = 'H';
        
      }
      
    }

    nextDirection = "Left";
    
      
  }






  void Mario::moveUp(World* world) { // Moves the Mario character representation on the world map one space up (or loops back around if it is on the edge of the map)

    if (x - 1 >= 0) {

      if (world -> getWorldMap()[currentLevel][x][y] == 'b' && enemyDefeated == false) {

         world -> getWorldMap()[currentLevel][x][y] = 'b';

         x = x - 1;

        interact(world);
      
        world -> getWorldMap()[currentLevel][x][y] = 'H';
        
      }


      else {
    
        world -> getWorldMap()[currentLevel][x][y] = 'x'; 
  
        x = x - 1;
  
        interact(world);
        
        world -> getWorldMap()[currentLevel][x][y] = 'H';
        
      }

    }

    else {

       if (world -> getWorldMap()[currentLevel][x][y] == 'b' && enemyDefeated == false) {

        world -> getWorldMap()[currentLevel][x][y] = 'b';

         x = x - 1;

        interact(world);
      
        world -> getWorldMap()[currentLevel][x][y] = 'H';
        
      }


      else {
        
        world -> getWorldMap()[currentLevel][x][y] = 'x'; 
  
        x = (world -> getDimension() - 1);
  
        interact(world);
  
        world -> getWorldMap()[currentLevel][x][y] = 'H';
        
      }
      
    }

    nextDirection = "Up";
    
      
  }





    void Mario::moveDown(World* world) { // Moves the Mario character representation on the world map one space down (or loops back around if it is on the edge of the map)

    if (x + 1 <= (world -> getDimension() - 1)) {

      if (world -> getWorldMap()[currentLevel][x][y] == 'b' && enemyDefeated == false) {

         x = x + 1;

        interact(world);
      
        world -> getWorldMap()[currentLevel][x][y] = 'H';
        
      }


      else {
    
        world -> getWorldMap()[currentLevel][x][y] = 'x'; 
  
        x = x + 1;
  
        interact(world);
        
        world -> getWorldMap()[currentLevel][x][y] = 'H';
        
      }

    }

    else {

       if (world -> getWorldMap()[currentLevel][x][y] == 'b' && enemyDefeated == false) {

         x = x + 1;

        interact(world);
      
        world -> getWorldMap()[currentLevel][x][y] = 'H';
        
      }


      else {
        
        world -> getWorldMap()[currentLevel][x][y] = 'x'; 
  
        x = 0;
  
        interact(world);
  
        world -> getWorldMap()[currentLevel][x][y] = 'H';
        
      }
      
    }

    nextDirection = "Down";
    
      
  }

    
  




    


    void Mario::moveRandomly(World* world) { // Gets a random number between 0 and 3, then determines what direction Mario will move in based on that number

      if ((rand() % 4) == 0) {
      
          moveLeft(world);
    
      }
          
       else if ((rand() % 4) == 1) {
      
          moveRight(world);
          
        }
          
        else if ((rand() % 4) == 2) {
      
          moveUp(world);
      
        }
          
        else {
      
          moveDown(world);  
          
        }


      numberOfMovements += 1;
    
    }






  void Mario::interact(World* world) { // Defines Mario's interactions with each character representation in the world

    if (world -> getWorldMap()[currentLevel][x][y] == 'c') {
    
        numOfCoins += 1;

      action = "Coin gained.";

        
     
      }

      else if (world -> getWorldMap()[currentLevel][x][y] == 'm') {
    
        if (powerLevel == 2) {

          action = "Mushroom not eaten due to power level being at maximum.";
          
        }

        else {

          powerLevel += 1;
          
          action = "Power gained.";
          
        }

        



      }
    
      else if (world -> getWorldMap()[currentLevel][x][y] == 'x') {
      
        action = "Empty position.";
      
      }
    
      else if (world -> getWorldMap()[currentLevel][x][y] == 'g') {
    
    
        if ((rand() % 100) < 80) {
    
          enemiesDefeated += 1;

          action = "Goomba defeated.";

          enemyDefeated = true;
          
        }
    
        else {
    
          if (powerLevel > 0) {
    
            powerLevel -= 1;

            action = "Lost to Goomba. Power level lost.";

            enemyDefeated = false;
    
          }
    
          else {
    
            if (numOfLives > 0) {
    
              numOfLives -= 1;

              action = "Lost to Goomba. Life lost.";

              enemyDefeated = false;

    
            }
    
            
         }
    
         
        }
    
      }
        
    
      else if (world -> getWorldMap()[currentLevel][x][y] == 'k') {
    
    
        if ((rand() % 100) < 65) {
    
          enemiesDefeated += 1;

          action = "Koopa defeated.";

          enemyDefeated = true;

          
        }
    
        else {
    
          if (powerLevel > 0) {
    
            powerLevel -= 1;

            action = "Lost to Koopa. Power level lost.";

             enemyDefeated = false;

    
          }
    
          else {
    
            if (numOfLives > 0) {
    
              numOfLives -= 1;

               action = "Lost to Koopa. Life lost.";

               enemyDefeated = false;

    
            }
    
    
            
          }
    
          
        }
    
      }
        
     else if (world -> getWorldMap()[currentLevel][x][y] == 'b') {
    
    
        if ((rand() % 100) < 50) {


          if (currentLevel + 1 == world -> getNumberOfLevels()) {

            action = "Final boss defeated.";
    
            finalBossDefeated = true;
            
          }

          else {

            action = "Boss defeated.";

            currentLevel += 1;

           

          }

           
          
        }
    
        else {
    
          if (powerLevel == 2) {
    
            powerLevel = 0;

             action = "Lost to boss. 2 power levels lost.";

             enemyDefeated = false;

            interact(world);
            

    
          }
    
          else {
    
            if (numOfLives > 0) {
    
              numOfLives -= 1;

               action = "Lost to boss. Life lost.";

              enemyDefeated = false;

              interact(world);
    
            }
    
            
          }
    
          
        }



     }


     else if (world -> getWorldMap()[currentLevel][x][y] == 'w') {

      if (currentLevel < world -> getNumberOfLevels()) {
        
            currentLevel += 1;

            x = rand() % (world -> getDimension());

            y = rand() % (world -> getDimension());

            action = "Warp pipe used.";


     }
    




    
    }

  }


