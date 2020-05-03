#include "Requester.h"

#include <iostream>
#include <string>

Requester::Requester() {}

std::string Requester::requestBoardName() {
	std::string boardName;
	std::cout << "How would you like to call this board?\n";
	std::getline(std::cin, boardName);
	return boardName;
}