#include "objPosArrayList.h"
#include <stdexcept> // to throw errors for out of bound

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    // initializing private data members
    sizeArray = ARRAY_MAX_CAP;
    sizeList = 0;
    aList = new objPos[sizeArray]; // on the heap -> deleted in destructor below
    for (int i = 0; i < sizeArray; i++) {
        aList[i] = objPos(); // init every element to zero by calling constructor from objpos
    }
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList; // 1d list of objects, simple as that
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (sizeList == sizeArray) {
        throw std::runtime_error("List is full."); // throw error if full
    }
    int i;
    for (i = sizeList; i > 0; i--) {
        aList[i] = aList[i - 1]; // shift every element to the right, including head
    }

    aList[0] = thisPos; // insert head
    sizeList++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (sizeList == sizeArray) {
        throw std::runtime_error("List is full.");
    }

    aList[sizeList] = thisPos; // using sizeList as the index gives us the newest element
    sizeList++;
}

void objPosArrayList::removeHead()
{
    if (sizeList == 0) { // dont remove if empty
        throw std::runtime_error("List is empty.");
    } else if (sizeList == 1) { // only remove the first element
        aList[0] = objPos(); // set head to 0
        sizeList--;
        return;
    }
    // otherwise move every element left once
    int i;
    for (i = 1; i < sizeList; i++) {
        aList[i - 1] = aList[i];
    }
    aList[sizeList - 1] = objPos(); // delete the copied tail by setting it to 0
    sizeList--;
}

void objPosArrayList::removeTail()
{
    if (sizeList == 0) {
        throw std::runtime_error("List is empty.");
    } 
    aList[sizeList - 1] = objPos(); // simply remove the last element
    sizeList--;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    if (sizeList == 0) {
        throw std::runtime_error("List is empty.");
    }
    
    aList[0].getObjPos(returnPos); // write the head data into returnPos obj
    
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    if (sizeList == 0) {
        throw std::runtime_error("List is empty.");
    }
    
    aList[sizeList - 1].getObjPos(returnPos); // write the tail data into returnPos obj
    
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    if (index < 0 || index >= sizeArray) { // make sure index is within range of our array
        throw std::out_of_range("Index out of range.");
    }
    aList[index].getObjPos(returnPos); // write the index object data into returnPos obj
}