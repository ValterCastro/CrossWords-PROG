#include <iostream>
#include <string>
#include <set>

#include "Classes/Board.cpp"
#include "Classes/Word.cpp"
#include "Libraries/Requester.cpp"
#include "Libraries/FileWrapper.cpp"

using namespace std;

int main()
{   
    // initiate vars
    Board board;
    string boardName;
    bool boardFinished;
    set<string> words;

    vector<unsigned short> boardSize;

    boardName = Requester::requestBoardName();
    board.setName(boardName);

    boardSize = Requester::requestBoardSize();
    board.setSize(boardSize[0], boardSize[1]);
    
    words = FileWrapper::loadWordsFile();
    
    while(true){
        // Render Board
        // Ask for a word && check word exists in words
        // Ask position and Horz/Vert (allow to restart iteration on "R") && check position is valid
        // Update Board.board with new letters
        // Save word in Board.words
        // IF i > 5, Ask if they want to finish the Board (if "Y", break)    
        
        boardFinished = Requester::requestIsBoardFinished();
        if(boardFinished){
            break;
        }
    }


    // Save Board to File
    string word = "aah";
    FileWrapper::saveBoardToFile(board.getName(), word);

    cout << "Program Finished Successfully\n";
    getline(cin, boardName);
}