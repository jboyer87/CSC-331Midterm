#pragma once
#include <list>

class MidtermList {
public:
	MidtermList(int initialSizeOfList);

	~MidtermList();

	void printAllElements();

	void deleteAnElement(int indexOfElement);

	std::list<double>::iterator findValue(double valueToFind);

private:
	std::list<double> m_midtermList;

	void fillListWithRandomDoubles(int initialSizeOfList);
};