#include "Food.h"

Food::Food(){
    //Initialising food object to be outside of game board
    objPos foodPos;
    foodPos.setObjPos(-1, -1, 'o');
    
    //Creating objPosArrayList on the heap
    foodBucket = new objPosArrayList();
    
    //Adding foodPos to head of array list
    foodBucket->insertHead(foodPos);

    xRange = 30;
    yRange = 15;

    //Seeding random number generation function with current time
    srand(time(NULL));
}

Food::Food(int boardSizeX, int boardSizeY){
    //Initialising food object to be outside of game board
    objPos foodPos;
    foodPos.setObjPos(-1, -1, 'o');
    
    //Creating objPosArrayList on the heap
    foodBucket = new objPosArrayList();
    
    //Adding foodPos to head of array list
    foodBucket->insertHead(foodPos);

    xRange = boardSizeX;
    yRange = boardSizeY;

    //Seeding random number generation function with current time
    srand(time(NULL));
}

Food::~Food(){
    //Deallocating memory from heap
    delete foodBucket;
}

void Food::generateFood(objPosArrayList* blockOff){

    //Local variables
    int regenerateStatus, rand_x, rand_y;

    //Object to temporarily store a playerArrayList element's position and a foodBucket element's pos
    objPos tempElementPos, tempFoodPos;

    //Do while loop to continuosly generate random coordinates for food
    do{
        //Resetting do while loop exit flag
        regenerateStatus = 0;

        // clear the list by removing tail elements until list size is 0
        while (foodBucket->getSize() > 0) {
            foodBucket->removeTail();
        }

        int i, j;
        for (i = 0; i < 5; i++) { // 5 food objects
            objPos newFoodPos;
            //Generating random x and y values within ranges
            rand_x = (rand() % (xRange-2))+1;
            rand_y = (rand() % (yRange-2))+1;
            // generate special chars for special food
            char foodSymbol;
            
            //If statements to assign the correct amount of food objects of corresponding symbols: 2 special food items, 3 regular food items
            if (i == 0) {foodSymbol = 'X';} else if (i == 1) {foodSymbol = '$';} else {foodSymbol = 'o';}
            
            //Updating food position
            newFoodPos.setObjPos(rand_x, rand_y, foodSymbol);

            //For loop to check if pre-existing food elements have same pos as new Food element
            for(int foodElementIndex = 0; foodElementIndex<=i; foodElementIndex++){
                //Passing positional info of food element within food bucket
                foodBucket->getElement(tempFoodPos, foodElementIndex);

                //Setting variable to 1, indicating that random food must be regenerated when current food item has same position as other food items
                if(tempFoodPos.isPosEqual(&newFoodPos)){
                    regenerateStatus = 1;
                    break;
                }
 
            }

            //Break out of for loop to prevent duplicate positions added to list
            if(regenerateStatus){
                break;
            }

            //Adding food item to food bucket
            foodBucket->insertTail(newFoodPos);
        }
        
        // check if overlapping

        for(i=0; i<blockOff->getSize(); i++){
            //Passing individual element's position info in arrayList to temporary object
            blockOff->getElement(tempElementPos, i);
            
            //Setting regenerateStatus to 1 when food pos is equal to player pos, regenerating random coordinates again
            for (j = 0; j < foodBucket->getSize(); j++) {
                foodBucket->getElement(tempFoodPos, j);
                
                if (tempFoodPos.isPosEqual(&tempElementPos)) {
                    regenerateStatus = 1;
                    break;
                }
            }
            
        }


    } while(regenerateStatus);


}

objPosArrayList* Food::getFoodPos() {
    // simply return the bucket
    return foodBucket;
}