#include <iostream>
#include "Classes/Board.cpp"
#include "Classes/Word.cpp"
#include "Libraries/Requester.cpp"

using namespace std;

int main()
{   
    // initiate vars
    Board board;
    string boardName;

    boardName = Requester::requestBoardName();
    board.setName(boardName);


    cout << "Program Finished Successfully\n";
    getline(cin, boardName);
}