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
    vector<unsigned short> boardSize;

    boardName = Requester::requestBoardName();
    board.setName(boardName);

    boardSize = Requester::requestBoardSize();
    board.setSize(boardSize[0], boardSize[1]);

    cout << "Program Finished Successfully\n";
    getline(cin, boardName);
}