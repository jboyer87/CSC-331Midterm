#include "MidtermList.h"
#include "NotFound.h"
#include <string>
#include <list>
#include <iostream>

MidtermList::MidtermList(int initialSizeOfList)
{
	this->fillListWithRandomDoubles(initialSizeOfList);
}

MidtermList::~MidtermList()
{
	// Nothing to do here...
}

void MidtermList::printAllElements()
{
	// Value to count the index we are at
	int i = 0;

	// Advance the iterator to the end
	for (std::list<double>::iterator listIterator = m_midtermList.begin(); listIterator != m_midtermList.end(); listIterator++)
	{
		// Output the index and what listIterator is pointing to
		std::cout << i << ": " << *listIterator << std::endl;
		i++;
	}
}

void MidtermList::deleteAnElement(int indexOfElement)
{
	// New iterator at the beginning of the list
	std::list<double>::iterator listIterator = m_midtermList.begin();

	// Advance the iterator the appropriate number of times
	for (int i = 0; i < indexOfElement; i++)
	{
		listIterator++;
	}

	// Delete the element that the iterator now points to
	m_midtermList.erase(listIterator);
}

void MidtermList::fillListWithRandomDoubles(int initialSizeOfList)
{
	// Push_front a bunch of random elements until we have filled the list
	for (int i = 0; i < initialSizeOfList; i++)
	{
		m_midtermList.push_front(std::rand() % initialSizeOfList);
	}
}

std::list<double>::iterator MidtermList::findValue(double valueToFind)
{
	std::list<double>::iterator listIterator = m_midtermList.begin();

	// Advance the iterator through the list, but don't go over the end
	for (int i = 0; i < m_midtermList.size(); i++)
	{
		// If the iterator is pointing at the value we're looking for
		if ((*listIterator) == valueToFind)
		{
			// Return the iterator
			return listIterator;
		}

		// If we haven't found it, advance and keep looking
		listIterator++;
	}

	// If we've searched the whole list, the value isn't there. Throw an exception
	throw(NotFound("The value was not found in the list"));
}