#include "Requester.h"
#include "FileWrapper.h"

#include <iostream>
#include <fstream>
#include <string>

Requester::Requester() {}

std::string Requester::requestBoardName() {
	std::string boardName;
	std::string question;

	question = "How would you like to call this board?";
	boardName = Requester::getValidFilename(question);
	std::cout << '\n';

	return boardName;
}

std::vector<unsigned short> Requester::requestBoardSize() {
	std::vector<unsigned short> sizes;
	unsigned short nrRows;
	unsigned short nrCollumns;
	std::string question;

	question = "How many rows should the board have?";
	nrRows = Requester::getValidInt(question, 5, 20);
	sizes.push_back(nrRows); 
	std::cout << '\n';
	
	question = "How many collumns should the board have?";
	nrCollumns = nrRows = Requester::getValidInt(question, 5, 20);
	sizes.push_back(nrCollumns); 
	std::cout << '\n';
	
	return sizes;
}

bool Requester::requestIsBoardFinished() {
	bool boardFinished;
	
	boardFinished = !Requester::getValidYesOrNo("Would you like to add another word?");
	std::cout << '\n';

	return boardFinished;
}

// Private

std::string Requester::getValidFilename(std::string question) {
	bool valid_input = false;
	std::string answer;
	std::string filename;
	
	do
	{
		std::cout << question << '\n'; 
		getline(std::cin, answer);
		
		filename = answer + ".txt";
		
		if (FileWrapper::isValidFilename(filename)) {
			valid_input = true;
		}
		else
		{
			std::cout << "Invalid input, please write a valid filename.\n\n";
		}
	} while (!valid_input);

	return filename;
}

int Requester::getValidInt(std::string question, int min, int max) {
	bool valid_input = false;
	int answer;
	
	do
	{
		std::cout << question << '\n'; 
		std::cin >> answer;
		if (!std::cin.fail() && answer >= min && answer <= max)
			valid_input = true;
		else
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid input, please write a number between " << min << " and " << max << ".\n\n";
		}
	} while (!valid_input);

	return answer;
}

bool Requester::getValidYesOrNo(std::string question) {
	bool valid_input = false;
	std::string answer;
	
	do
	{
		std::cout << question << '\n'; 
		getline(std::cin, answer);
		if (answer == "Y" || answer == "Yes" || answer == "yes" || answer == "N" || answer == "No" || answer == "no")
			valid_input = true;
		else
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid input, please write Y/Yes or N/No.\n\n";
		}
	} while (!valid_input);

	return (answer == "Y" || answer == "Yes" || answer == "yes");
}