#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 100000 // 0.1s

//Game mechanics object pointer
GameMechs* myGM;

//Player object pointer
Player *myPlayer;

//Food object pointer
Food *foodObj;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    //Initiallizing object pointers on the heap
    myGM = new GameMechs(30, 15); //30x15 board

    foodObj = new Food(myGM->getBoardSizeX(), myGM->getBoardSizeY());
    
    myPlayer = new Player(myGM, foodObj);

    objPosArrayList* tempPosList;

    tempPosList = myPlayer->getPlayerPos();

    //Generating initial food coordinate
    foodObj->generateFood(tempPosList);

}

void GetInput(void)
{
    myGM->getInput();

}

void RunLogic(void)
{
    //If statement to check if exit key was pressed
    if(myGM->getInput() == ' '){
        myGM->setExitTrue(); //NOTE: ASK IF exitFlag should be set to true in updatePlayerDir() because already calling getInput in that method
    }

    //Else statement to change direction of player based on key pressed
    else{
        //Class method to update player direction
        myPlayer->updatePlayerDir();
        //Class method to move player based on player direction
        myPlayer->movePlayer();
    }

    myGM->clearInput(); //Resetting input to 0
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    //Variable to act as an indicator for when player body is drawn
    bool drawn; 

    //Local variables to store gameboard size
    int totalRows = myGM->getBoardSizeY();
    int totalCols = myGM->getBoardSizeX();

    //Initializing objects to temporarily store playerPositionList and its elements individually
    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;

    //Creating tempFoodList to temporarily store position info of current food items on the board
    objPosArrayList *tempFoodList = foodObj->getFoodPos();
    // the element in this list
    objPos tempFoodPos;

    //For loop to iterate through every row of game board
    for(int row=0; row<totalRows; row++){
        //For loop to iterate through every column per row
        for(int col=0; col<totalCols; col++){
          
          //Resetting drawn flag to false
          drawn = false;

          //For loop to iterate through every element in player array list
          for (int index=0; index<playerBody->getSize(); index++){
            
            playerBody->getElement(tempBody, index);

            if(tempBody.x == col && tempBody.y == row){
                MacUILib_printf("%c", tempBody.symbol);
                drawn = true;
                break;
            }
          }

          //For loop to iterate through every element in food array list
          for (int index=0; index<tempFoodList->getSize(); index++){
            
            //Passing element's positional info at index i of food array list
            tempFoodList->getElement(tempFoodPos, index);

            //Printing food character when program is at the position of food item
            if(tempFoodPos.x == col && tempFoodPos.y == row){
                MacUILib_printf("%c", tempFoodPos.symbol);
                drawn = true;
                break;
            }
          }

          //Continue statement to skip past logic below to prevent player body characters to be cleared by spaces
          if(drawn) continue;
          
          
          //If statements to check if printing first or last row of game board
          if(row == 0 || row == totalRows-1){
            MacUILib_printf("%c", '#');
          }

          else{
            //If statement to print border if in first or last column
            if(col == 0 || col == totalCols-1){
                MacUILib_printf("%c", '#');
            }

            //Else to print space if no other character occupies that space
            else{
                MacUILib_printf("%c", ' ');
            }
          }  
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("Score: %d", myGM->getScore());

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();

    //If statement to provide different output based on loseFlag condition
    if(myGM->getLoseFlagStatus()){
        MacUILib_printf("Collision occured!");
    }

    else{
        MacUILib_printf("Exited game.");
    }    

    //Printing score
    MacUILib_printf("\nScore: %d\n", myGM->getScore());
    
    //Deallocating memory of objects created on the heap
    delete myGM;
    delete myPlayer;
    delete foodObj;

    MacUILib_uninit();
}
