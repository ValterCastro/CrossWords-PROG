#ifndef REQUESTER_H
#define REQUESTER_H

#include <string>
#include <vector>

// Responsible for handling console requests to user
class Requester {
public:
	Requester();
	
	std::string static requestBoardName();
	std::vector<unsigned short> static requestBoardSize();
	bool static requestIsBoardFinished();
private:
	std::string static getValidFilename(std::string question);
	int static getValidInt(std::string question, int min, int max);
	bool static getValidYesOrNo(std::string question);
};

#endif