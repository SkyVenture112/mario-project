#ifndef MARIO_H
#define MARIO_H

#include "World.h"
#include <string>

class Mario {

  public:

    Mario();
  
    Mario(int, int, int, int, int, int, int, int, bool, bool, std::string, std::string);
  
    virtual ~Mario();
  
    int getNumOfLives();
  
    int getNumOfCoins();
  
    int getPowerLevel();

    int getMovements();

    int getXPosition();

    int getYPosition();

    int getEnemiesDefeated();

    int getCurrentLevel();

    bool getFinalBossDefeated();

    std::string getAction();

    std::string getNextDirection();

    void setNumOfLives(int);
  
    void setNumOfCoins(int);
  
    void setPowerLevel(int);

    void setEnemiesDefeated(int);

    void setCurrentLevel(int);

    void moveRight(World*);

    void moveLeft(World*);

    void moveUp(World*);

    void moveDown(World*);

    void moveRandomly(World*);

    void moveWithoutChange(World*);

    void interact(World*);



  private:

    int numOfLives;
  
    int numOfCoins;
  
    int powerLevel;

    int numberOfMovements;

    int x;

    int y;

    int enemiesDefeated;

    int currentLevel;

    bool enemyDefeated;

    bool finalBossDefeated;  

    std::string action;

    std::string nextDirection;

};

#endif