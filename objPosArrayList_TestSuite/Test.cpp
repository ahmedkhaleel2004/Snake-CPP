#include "./cute/cute.h"
#include "./cute/ide_listener.h"
#include "./cute/xml_listener.h"
#include "./cute/cute_runner.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include <iostream>

// WARNING!!  This test suite does not contain any test cases for accessing elements out-of-bound.
//
// You must deploy exception throwing for all out-of-bound accesses.


// Test Case 1 - Constructor Tester
// - Will require you to implement getSize() and getElement() methods.
void testConstructor()
{
	objPos zeroPos, currentPos;
	objPosArrayList thisList;
	int expectedSize = 0;
	int actualSize = thisList.getSize();
	
	// First check the list size
	ASSERT_EQUAL(expectedSize, actualSize);

	bool expectedCheck = true;
	bool actualCheck;

	// Then check all elements in the array are zero-initialized via objPos() default constructor
	for(int i = 0; i < ARRAY_MAX_CAP; i++)
	{
		thisList.getElement(currentPos, i);
		actualCheck = zeroPos.isPosEqual(&currentPos);

		ASSERT_EQUAL(expectedCheck, actualCheck);
	}

	// The destructor will be called automatically for stack-allocated objects
}


// Test Case 2a - insertHead 1 Element 
// - Will require you to implement getHeadElement(), getTailElement(), and getElement() methods.
void testInsertHead_1Element()
{
	objPos currentPos;
	objPos samplePos{2, 5, 'a'};  

	// Insert 1 sample element
	objPosArrayList thisList;
	thisList.insertHead(samplePos);

	int expectedSize = 1;
	int actualSize = thisList.getSize();
		
	// First check the list size is 1
	ASSERT_EQUAL(expectedSize, actualSize);

	bool expectedCheck = true;
	bool actualCheck;

	// Then check whether the head element is what we have inserted.
	thisList.getHeadElement(currentPos);
	actualCheck = samplePos.isPosEqual(&currentPos);

	ASSERT_EQUAL(expectedCheck, actualCheck);


	// Next, check whether the tail element is also the head element in a list of 1 element.
	thisList.getTailElement(currentPos);
	actualCheck = samplePos.isPosEqual(&currentPos);

	ASSERT_EQUAL(expectedCheck, actualCheck);


	// Finally, chech whether the element at index = 0 is also the head element in a list of 1 element
	// Then check whether the head element is what we have inserted.
	thisList.getElement(currentPos, 0);
	actualCheck = samplePos.isPosEqual(&currentPos);

	ASSERT_EQUAL(expectedCheck, actualCheck);

	// The destructor will be called automatically for stack-allocated objects
}

// Test Case 2b - insertHead 5 Element 
// - Will require you to implement getHeadElement() and getTailElement() method.
void testInsertHead_5Element()
{
	objPos currentPos;
	objPos bodyPos{2, 5, 'a'};  
	objPos headPos{3, 3, 'm'};

	// Insert 4 body elements, then 1 unique head element
	objPosArrayList thisList;
	thisList.insertHead(bodyPos);
	thisList.insertHead(bodyPos);
	thisList.insertHead(bodyPos);
	thisList.insertHead(bodyPos);
	thisList.insertHead(headPos);

	int expectedSize = 5;
	int actualSize = thisList.getSize();
		
	// Confirm the list size is now 5
	ASSERT_EQUAL(expectedSize, actualSize);

	bool expectedCheck = true;
	bool actualCheck;

	// Then, check the head element is the unique element
	thisList.getHeadElement(currentPos);
	actualCheck = headPos.isPosEqual(&currentPos);

	ASSERT_EQUAL(expectedCheck, actualCheck);

	// Next, chech the body elements at index 1, 2, and 3.
	for(int i = 1; i < actualSize - 1; i++)
	{
		thisList.getElement(currentPos, i);
		actualCheck = bodyPos.isPosEqual(&currentPos);

		ASSERT_EQUAL(expectedCheck, actualCheck);	
	}

	// Finally, check the tail element is the body element
	thisList.getTailElement(currentPos);
	actualCheck = bodyPos.isPosEqual(&currentPos);

	ASSERT_EQUAL(expectedCheck, actualCheck);

	// The destructor will be called automatically for stack-allocated objects
}



// Test Case 3a - insertTail 1 Element 
void testInsertTail_1Element()
{
	objPos currentPos;
	objPos samplePos{2, 5, 'a'};  

	// Insert 1 sample element
	objPosArrayList thisList;
	thisList.insertTail(samplePos);

	int expectedSize = 1;
	int actualSize = thisList.getSize();
		
	// First check the list size is 1
	ASSERT_EQUAL(expectedSize, actualSize);

	bool expectedCheck = true;
	bool actualCheck;

	// Then check whether the head element is what we have inserted.
	thisList.getHeadElement(currentPos);
	actualCheck = samplePos.isPosEqual(&currentPos);

	ASSERT_EQUAL(expectedCheck, actualCheck);


	// Next, check whether the tail element is also the head element in a list of 1 element.
	thisList.getTailElement(currentPos);
	actualCheck = samplePos.isPosEqual(&currentPos);

	ASSERT_EQUAL(expectedCheck, actualCheck);


	// Finally, chech whether the element at index = 0 is also the head element in a list of 1 element
	// Then check whether the head element is what we have inserted.
	thisList.getElement(currentPos, 0);
	actualCheck = samplePos.isPosEqual(&currentPos);

	ASSERT_EQUAL(expectedCheck, actualCheck);

	// The destructor will be called automatically for stack-allocated objects
}

// Test Case 3b - insertTail 5 Element 
void testInsertTail_5Element()
{
	objPos currentPos;
	objPos bodyPos{2, 5, 'a'};  
	objPos tailPos{3, 3, 'm'};

	// Insert 4 body elements, then 1 unique head element
	objPosArrayList thisList;
	thisList.insertTail(bodyPos);
	thisList.insertTail(bodyPos);
	thisList.insertTail(bodyPos);
	thisList.insertTail(bodyPos);
	thisList.insertTail(tailPos);

	int expectedSize = 5;
	int actualSize = thisList.getSize();
		
	// Confirm the list size is now 5
	ASSERT_EQUAL(expectedSize, actualSize);

	bool expectedCheck = true;
	bool actualCheck;

	// Then, check the head element is the common body element
	thisList.getHeadElement(currentPos);
	actualCheck = bodyPos.isPosEqual(&currentPos);

	ASSERT_EQUAL(expectedCheck, actualCheck);

	// Next, chech the body elements at index 1, 2, and 3.
	for(int i = 1; i < actualSize - 1; i++)
	{
		thisList.getElement(currentPos, i);
		actualCheck = bodyPos.isPosEqual(&currentPos);

		ASSERT_EQUAL(expectedCheck, actualCheck);	
	}

	// Finally, check the tail element is the body element
	thisList.getTailElement(currentPos);
	actualCheck = tailPos.isPosEqual(&currentPos);

	ASSERT_EQUAL(expectedCheck, actualCheck);

	// The destructor will be called automatically for stack-allocated objects
}


// Test Case 4a - removeHead from 1 Element List
void testRemoveHead_1Element()
{
	objPos currentPos;
	objPos samplePos{2, 5, 'a'};  

	// Insert 1 sample element
	objPosArrayList thisList;
	thisList.insertHead(samplePos);

	thisList.removeHead();

	int expectedSize = 0;
	int actualSize = thisList.getSize();
		
	// The destructor will be called automatically for stack-allocated objects
}

// Test Case 4b - removeHead from 5 Element list
void testRemoveHead_5Element()
{
	objPos currentPos;
	objPos bodyPos{2, 5, 'a'};  
	objPos headPos{3, 3, 'm'};

	// Insert 4 body elements, then 1 unique head element
	objPosArrayList thisList;
	thisList.insertHead(bodyPos);
	thisList.insertHead(bodyPos);
	thisList.insertHead(bodyPos);
	thisList.insertHead(bodyPos);
	thisList.insertHead(headPos);
	// some helpful debugging code here that im going to leave just in case for the future
	// int i;
	// std::cout << "Before!" << std::endl;
	// for (i = 0; i < thisList.getSize(); i++) {thisList.getElement(currentPos, i);std::cout << "i = " << i << ": " << currentPos.getSymbol() << std::endl;} 
	thisList.removeHead();
	// std::cout << "After!" << std::endl;
	// for (i = 0; i < thisList.getSize(); i++) {thisList.getElement(currentPos, i);std::cout << "i = " << i << ": " << currentPos.getSymbol() << std::endl;} 
	int expectedSize = 4;
	int actualSize = thisList.getSize();
		
	// Confirm the list size is now 4
	ASSERT_EQUAL(expectedSize, actualSize);

	bool expectedCheck = true;
	bool actualCheck;

	// Then, check the unique element has been removed
	thisList.getHeadElement(currentPos);
	actualCheck = bodyPos.isPosEqual(&currentPos);

	ASSERT_EQUAL(expectedCheck, actualCheck);

	// Next, the rest of the elements are still common elements
	for(int i = 1; i < actualSize; i++)
	{
		thisList.getElement(currentPos, i);
		actualCheck = bodyPos.isPosEqual(&currentPos);

		ASSERT_EQUAL(expectedCheck, actualCheck);	
	}

	// The destructor will be called automatically for stack-allocated objects
}

// Test Case 5a - removeTail 1 Element 
void testRemoveTail_1Element()
{
	objPos currentPos;
	objPos samplePos{2, 5, 'a'};  

	// Insert 1 sample element
	objPosArrayList thisList;
	thisList.insertTail(samplePos);

	thisList.removeTail();

	int expectedSize = 0;
	int actualSize = thisList.getSize();
		
	// First check the list size is 1
	ASSERT_EQUAL(expectedSize, actualSize);

	// The destructor will be called automatically for stack-allocated objects
}

// Test Case 5b - removeTail 5 Element 
void testRemoveTail_5Element()
{
	objPos currentPos;
	objPos bodyPos{2, 5, 'a'};  
	objPos tailPos{3, 3, 'm'};

	// Insert 4 body elements, then 1 unique head element
	objPosArrayList thisList;
	thisList.insertTail(bodyPos);
	thisList.insertTail(bodyPos);
	thisList.insertTail(bodyPos);
	thisList.insertTail(bodyPos);
	thisList.insertTail(tailPos);

	thisList.removeTail();

	int expectedSize = 4;
	int actualSize = thisList.getSize();
		
	// Confirm the list size is now 4
	ASSERT_EQUAL(expectedSize, actualSize);

	bool expectedCheck = true;
	bool actualCheck;

	// Then, check the tail element removed
	thisList.getTailElement(currentPos);
	actualCheck = bodyPos.isPosEqual(&currentPos);

	ASSERT_EQUAL(expectedCheck, actualCheck);

	// Next, chech the body elements at index 1, 2, and 3.
	for(int i = 0; i < actualSize - 1; i++)
	{
		thisList.getElement(currentPos, i);
		actualCheck = bodyPos.isPosEqual(&currentPos);

		ASSERT_EQUAL(expectedCheck, actualCheck);	
	}

	// The destructor will be called automatically for stack-allocated objects
}




bool runAllTests(int argc, char const *argv[]) {
	cute::suite s;
	
    s.push_back(CUTE(testConstructor));
	s.push_back(CUTE(testInsertHead_1Element));
	s.push_back(CUTE(testInsertHead_5Element));
	s.push_back(CUTE(testInsertTail_1Element));
	s.push_back(CUTE(testInsertTail_5Element));
	s.push_back(CUTE(testRemoveHead_1Element));
	s.push_back(CUTE(testRemoveHead_5Element));
	s.push_back(CUTE(testRemoveTail_1Element));
	s.push_back(CUTE(testRemoveTail_5Element));
	



	//TODO add your test here

	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<> > lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
