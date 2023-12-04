// This file defines the World class's constructors and functions. 



#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <fstream>

class World {

  public:

    World();

    World(int, int, int, int, int, int, int);

    virtual ~World();

    char*** getWorldMap();

    int getNumberOfLevels();

    int getDimension();

    void populateWorldMap(char***, int);

    void printWorldMapToFile(std::ofstream&);

    void printLevelMapToFile(std::ofstream&, int);

  private:

    int numberOfLevels;

    int worldDimensions;

    int coinsAmount;

    int nothingAmount;

    int goombaAmount;

    int koopaAmount;

    int mushroomAmount;

    char*** worldMap;

  

};

#endif