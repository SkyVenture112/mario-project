/* The following main method reads in different inputs for populating the
level from the given input file, then instantiates both a
World and Mario object given said inputs. 

It then populates the World object's worldMap array and prints out a character 
representation of the array to the given output file. Mario then
interacts with the world once before being placing into it. 
The game proceeds while Mario does not run out of lives or has 
not defeated the final boss. 
*/


#include "Mario.h"
#include "World.h"

int main(int argc, char *argv[]) {

  srand(time(0));

  int numberOfLevels;
  int arrayDimension;
  int initialLives; 
  int coinPercentage;
  int nothingPercentage;
  int goombaPercentage;
  int koopaPercentage;
  int mushroomPercentage;

  std::ifstream input;
  std::ofstream output; 

  input.open(argv[1]);

  input >> numberOfLevels;
  input >> arrayDimension;
  input >> initialLives;
  input >> coinPercentage;
  input >> nothingPercentage;
  input >> goombaPercentage;
  input >> koopaPercentage; 
  input >> mushroomPercentage;

  input.close();

  output.open(argv[2]); 


  int levelPlaces = arrayDimension * arrayDimension;

  int coinPlaces = (levelPlaces * coinPercentage) / 100;

  int nothingPlaces = (levelPlaces * nothingPercentage) / 100;

  int goombaPlaces = (levelPlaces * goombaPercentage) / 100;

  int koopaPlaces = (levelPlaces * koopaPercentage) / 100;

  int mushroomPlaces = (levelPlaces * mushroomPercentage) / 100;

  

  World* world = new World (numberOfLevels, arrayDimension, coinPlaces, nothingPlaces, goombaPlaces, 
  koopaPlaces, mushroomPlaces);

  Mario* mario = new Mario(initialLives, 0, 0, 0, (rand() % arrayDimension), 
  (rand() % arrayDimension), 0, 0, false, false, "", "");


  for (int i = 0; i < world -> getNumberOfLevels(); ++i) {

    world -> populateWorldMap(world -> getWorldMap(), i);
    
  } 


   for (int i = 0; i < world -> getNumberOfLevels() - 1; ++i) {

    world -> getWorldMap()[i][rand() % world -> getDimension()][rand() % world -> getDimension()] = 'w';
    
  }
  

  
  
  world -> printWorldMapToFile(output);

  mario -> interact(world);
  
  world -> getWorldMap()[mario -> getCurrentLevel()][mario -> getXPosition()][mario -> getYPosition()] = 'H';

  


  
   while (mario -> getNumOfLives() > 0) {
     
     
      if (mario -> getNumOfCoins() == 20) {

        mario -> setNumOfLives(mario -> getNumOfLives() + 1);
    
        mario -> setNumOfCoins(0);
    
      }
     

      if (mario -> getEnemiesDefeated() == 7) {

        mario -> setNumOfLives(mario -> getNumOfLives() + 1);

        mario -> setEnemiesDefeated(0);
        
      }



     mario -> moveRandomly(world);



     output << "Level: " + std::to_string(mario -> getCurrentLevel() + 1) << " - ";

     output << "Position: [" + std::to_string(mario -> getXPosition()) + "] [" + 
    std::to_string(mario -> getYPosition()) + "]" << " - ";

     output << "Action: " << mario -> getAction() << " - ";
     
     output << "Power level: " + std::to_string(mario -> getPowerLevel()) << " - ";
     
     output << "Lives: " + std::to_string(mario -> getNumOfLives()) << " - ";
     
     output << "Coins: " + std::to_string(mario -> getNumOfCoins()) << " - ";

     output << "Next direction: " << mario -> getNextDirection() << std::endl; 

     
     
     world -> printLevelMapToFile(output, mario -> getCurrentLevel());
     

     if (mario -> getNumOfLives() == 0) {

       output << "Mario lost the game." << std::endl;

       output << "Movements: " + std::to_string(mario -> getMovements()) << std::endl;
       
        break;
       
     }

     else if (mario -> getFinalBossDefeated() == true) {

       output << "Mario won the game!" << std::endl;

       output << "Movements: " + std::to_string(mario -> getMovements()) << std::endl;

        break;
       
     }

  }




    
  
  output.close();

  
  delete world;

  
  delete mario;
  
  
  exit(0);
  

}