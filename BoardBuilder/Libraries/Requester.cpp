#include "Requester.h"

#include <iostream>
#include <fstream>
#include <string>
#include <set>

#include "FileWrapper.h"
#include "Classes/Word.h"

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

Word Requester::requestWord(std::set<std::string> acceptableWords, unsigned short nrRows, unsigned short nrCollumns){
	std::string question;
	std::string wordString;
	std::string positionAndOrientationString;
	WordOrientation orientation;

	question = "Which word you would like to add?";
	wordString = Requester::getValidWord(question, acceptableWords);
	std::cout << '\n';
	
	question = "And which position and orientation? (eg: 'Ca H' or 'Ab V')";
	positionAndOrientationString = Requester::getValidPositionAndOrientation(question, nrRows, nrCollumns);
	std::cout << '\n';
	
	char position[2] = {positionAndOrientationString[0], positionAndOrientationString[1]};
	orientation = positionAndOrientationString[3] == 'H' ? WordOrientation::Horizontal : WordOrientation::Vertical;
	Word word(position, orientation, wordString);
	
	return word;
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
	
	do
	{
		std::cout << question << '\n'; 
		getline(std::cin, answer);
		if (FileWrapper::isValidFilename(answer + ".txt")) {
			valid_input = true;
		}
		else
		{
			std::cout << "Invalid input, please write a valid filename.\n\n";
		}
	} while (!valid_input);

	return answer;
}

int Requester::getValidInt(std::string question, int min, int max) {
	bool valid_input = false;
	int answer;
	
	do
	{
		std::cout << question << '\n'; 
		std::cin >> answer;
		if (!std::cin.fail() && answer >= min && answer <= max){
			valid_input = true;
			std::cin.ignore(1000, '\n');
		}
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
			std::cout << "Invalid input, please write Y/Yes or N/No.\n\n";
		}
	} while (!valid_input);

	return (answer == "Y" || answer == "Yes" || answer == "yes");
}

std::string Requester::getValidWord(std::string question, std::set<std::string> acceptableWords) {
	bool valid_input = false;
	std::string answer;

	do
	{
		std::cout << question << '\n'; 
		getline(std::cin, answer);
		if (acceptableWords.find(answer) != acceptableWords.end())
			valid_input = true;
		else
		{
			std::cout << "Word not found in WORDS.TXT, please write a word from that file.\n\n";
		}
	} while (!valid_input);

	return answer;
}

std::string Requester::getValidPositionAndOrientation(std::string question, unsigned short nrRows, unsigned short nrCollumns){
	bool valid_input = false;
	std::string answer;
	char maxRowLetter;
	char maxCollumnLetter;

	maxRowLetter = Board::INITIAL_ROW_LETTER + (nrRows - 1);
	maxCollumnLetter = Board::INITIAL_COLLUMN_LETTER + (nrCollumns - 1);

	do
	{
		std::cout << question << '\n'; 
		getline(std::cin, answer);
		
		if (answer[0] <= maxRowLetter && answer[1] <= maxCollumnLetter && answer[2] == ' ' && (answer[3] == 'H' || answer[3] == 'V'))
			valid_input = true;
		else
		{
			std::cout << "Invalid input, please write a valid position and orientation.\n\n";
		}
	} while (!valid_input);

	return answer;	
}