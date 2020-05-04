#include "Requester.h"

#include <iostream>
#include <string>

Requester::Requester() {}

std::string Requester::requestBoardName() {
	std::string boardName;
	
	// TODO: validate input can be a filename
	std::cout << "How would you like to call this board?\n";
	getline(std::cin, boardName);
	std::cout << '\n';

	return boardName;
}

std::vector<unsigned short> Requester::requestBoardSize() {
	std::vector<unsigned short> sizes;
	unsigned short nr_rows;
	unsigned short nr_collumns;

	// TODO: validate input between 5 and 20
	std::cout << "How many rows should the board have?\n";
	std::cin >> nr_rows;
	sizes.push_back(nr_rows); 
	std::cout << "How many collumns should the board have?\n";
	std::cin >> nr_collumns;
	sizes.push_back(nr_collumns); 
	std::cout << '\n';

	return sizes;
}