#include <iostream>
#include <list>
#include <string>
#include "NotFound.h"
#include "MidtermList.h"

// Midterm
// Create a standard library std::list container and load it with 100 random doubles
// Write an iterator based loop and print out all the elements
// Write a function to delete the 75th element in the list
// Write a function to find a given double value in this list and return its position in 
// the list if found. If not found your function should throw an exception object defined
// by you

int main() {

	// Instantiate a new list with 100 double elements. The contents will be randomized.
	MidtermList myTestList = MidtermList(100);


	std::cout << "Printing all elements in the list..." << std::endl;

	// Print all of the elements. This will print an index and the value stored there.
	myTestList.printAllElements();


	int positionToDeleteElementAt = 75;

	std::cout << std::endl << "Deleting an element at position " << positionToDeleteElementAt << std::endl;

	// Delete an element at the specified index. Inspect the list before and after to 
	// find that the value has been deleted.
	myTestList.deleteAnElement(positionToDeleteElementAt);

	// Try to find some values in the list
	try 
	{
		// Set up 2 values to search for
		// You will probably find this value...
		double valueToFind = 5.0;
		// You will not find this value due to the way the list contents are randomized
		double valueYouWontFind = 5.234234;
		
		// 5 is found (hopefully, depends on your rand() run, adjust to a found value)
		std::list<double>::iterator foundValue = myTestList.findValue(valueToFind);
		
		// 5.234234 won't be found, uncomment this to test the exception
		// std::list<double>::iterator foundValue = myTestList.findValue(valueToFind);

		// Output the found value (5). The findValue() function returns an iterator,
		// so we can dereference it to see what it is pointing at.
		std::cout << "Found it!: " << *foundValue << std::endl;
		
	}
	// Catch my custom notfound exception
	catch (NotFound exception)
	{
		// Output the error message if the value was not found
		std::cout << exception.getMessage() << std::endl;
	}

	return 0;
}