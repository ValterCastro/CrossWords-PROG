#include <iostream>
#include <string>
#include <set>

#include "Classes/Board.cpp"
#include "Classes/Word.cpp"
#include "Libraries/Requester.cpp"
#include "Libraries/FileWrapper.cpp"
#include "Libraries/Presenter.cpp"

using namespace std;

int main()
{
    // initiate vars
    Board board;
    string boardName;
    bool boardFinished;
    set<string> acceptableWords;
    
    vector<unsigned short> boardSize;

    boardName = Requester::requestBoardName();
    board.setName(boardName);

    boardSize = Requester::requestBoardSize();
    board.setNrRows(boardSize[0]);
    board.setNrCollumns(boardSize[1]);

    acceptableWords = FileWrapper::loadWordsFile();

    while (true)
    {
        Presenter::presentBoard(board);

        while(true){
            Word word = Requester::requestWord(acceptableWords, board.getNrRows(), board.getNrCollumns());
            if(board.addWord(word))
                break;
            else
                cout << "Invalid word size or position, please try again.\n\n";             
        }

        if(board.getWords().size() >= 5){
            boardFinished = Requester::requestIsBoardFinished();
            if (boardFinished)
            {
                break;
            }
        }
    }

    // Save Board to File
    string word = "aah";
    FileWrapper::saveBoardToFile(board.getName(), word);

    cout << "Program Finished Successfully\n";
    getline(cin, boardName);
}