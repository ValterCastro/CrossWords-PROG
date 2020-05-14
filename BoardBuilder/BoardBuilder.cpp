#include <iostream>
#include <string>
#include <set>

#include "Classes/Board.cpp"
#include "Classes/Word.cpp"
#include "Libraries/Requester.cpp"

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

    // Word building process:
    // Load WORDS.TXT and save to set "words"
    // Iteration until break
    // Render Board
    // Ask for a word && check word exists in words
    // Ask position and Horz/Vert (allow to restart iteration on "R") && check position is valid
    // Update Board.board with new letters
    // Save word in Board.words
    // IF i > 5, Ask if they want to finish the Board (if "Y", break)

    // word building process


    while(true){

        

        boardFinished = Requester::requestIsBoardFinished();
        if(boardFinished){
            break;
        }
    }

    cout << "Program Finished Successfully\n";
    getline(cin, boardName);
}