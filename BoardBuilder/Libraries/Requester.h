#ifndef REQUESTER_H
#define REQUESTER_H

#include <string>

// Responsible for handling console requests to user
class Requester {
public:
	Requester();
	
	std::string static requestBoardName();
	std::vector<unsigned short> static requestBoardSize();
	bool static requestIsBoardFinished();
private:
	bool static getValidYesOrNo(std::string question);
	int static getValidInt(std::string question, int min, int max);
};

#endif