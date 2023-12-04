// This file defines the World class's constructors and functions. 


#include "World.h"



  World::World() { // Default World constructor 

    numberOfLevels = 0;

    worldDimensions = 0;

    worldMap = nullptr;
    
  }




  World::World(int levels, int dimension, int coins, int nothing, int goombas, int koopas, int mushrooms) { // Overloaded World constructor that fills the worldMap array with blank spaces

    numberOfLevels = levels;
    
    worldDimensions = dimension;

    coinsAmount = coins;

    nothingAmount = nothing;

    goombaAmount = goombas;

    koopaAmount = koopas;

    mushroomAmount = mushrooms;  

    worldMap = new char**[numberOfLevels];
  

    for (int i = 0; i < numberOfLevels; ++i) {
      
      worldMap[i] = new char*[worldDimensions];
      
      for (int j = 0; j < worldDimensions; ++j) {
        
          worldMap[i][j] = new char[worldDimensions];

        for (int k = 0; k < worldDimensions; ++k) {

            worldMap[i][j][k] = 'x';

        
        }
    
      }
  
    }

  }  




  
  World::~World() { // World destructor

    for (int i = 0; i < numberOfLevels; i++) {
    
      for (int j = 0; j < worldDimensions; j++) {
      
        delete[] worldMap[i][j];
      }
    
       delete[] worldMap[i];
    
      }
  
    delete[] worldMap;
    
  }




  char*** World::getWorldMap() { // Returns the three-dimensional worldMap character array


    return worldMap;

    
  }




    int World::getNumberOfLevels() { // Returns the number of levels

      return numberOfLevels;
    

    
    }


   int World::getDimension() { // Returns the worldArray dimension

      return worldDimensions;
      
    }




  void World::populateWorldMap(char*** worldMap, int levelNumber) { // Randomly populates the worldMap array with each character

     for (int i = 0; i < coinsAmount; ++i) {

        worldMap[levelNumber][rand() % worldDimensions][rand() % worldDimensions] = 'c';

    }
  

    for (int i = 0; i < nothingAmount; ++i) {
  
      worldMap[levelNumber][rand() % worldDimensions][rand() % worldDimensions] = 'x';
      
    }
  

    for (int i = 0; i < goombaAmount; ++i) {
  
       worldMap[levelNumber][rand() % worldDimensions][rand() % worldDimensions] = 'g';
      
    }
  

    for (int i = 0; i < koopaAmount; ++i) {
  
       worldMap[levelNumber][rand() % worldDimensions][rand() % worldDimensions] = 'k';
      
    }
  

    for (int i = 0; i < mushroomAmount; ++i) {
  
      worldMap[levelNumber][rand() % worldDimensions][rand() % worldDimensions] = 'm';
      
    }
  
       worldMap[levelNumber][rand() % worldDimensions][rand() % worldDimensions] = 'b';
      
      
  }





  void World::printWorldMapToFile(std::ofstream& output) { // Outputs a textual representation of the array to tbe given output file

    for (int i = 0; i < numberOfLevels; ++i) {

      for (int j = 0; j < worldDimensions; ++j) {

        for (int k = 0; k < worldDimensions; ++k) {

        output << worldMap[i][j][k] << " ";
        
        }

      output << std::endl;;

      }


     output << std::endl;

    }

  }





  void World::printLevelMapToFile(std::ofstream& output, int level) { // Outputs a textual representation of the current level to tbe given output file

      for (int j = 0; j < worldDimensions; ++j) {

        for (int k = 0; k < worldDimensions; ++k) {

        output << worldMap[level][j][k] << " ";
        
        }

      output << std::endl;

      }


     output << std::endl;

    }





  