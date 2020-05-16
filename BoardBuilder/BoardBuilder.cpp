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
    const unsigned short MIN_WORDS = 5;

    Board board;
    string boardName;
    vector<unsigned short> boardSize;
    set<string> acceptableWords;
    bool boardFinished;

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

        if(board.getWords().size() >= MIN_WORDS && Requester::requestIsBoardFinished())
            break;
    }

    FileWrapper::saveBoardToFile(board);
    cout << "Board saved successfully with name " << board.getName() << ".txt" << '\n';

    return 0;
}