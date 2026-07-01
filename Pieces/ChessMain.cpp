#include <iostream> 
#include <string> 
#include "Board.h" 
using namespace std; 
 
void getPlayerMove(const string& move, int& r1, int& c1, int& r2, int& c2) { 
    if (move.length() < 5) { 
        r1 = c1 = r2 = c2 = -1; 
        return; // basically if the move inputted is junk, disregard it. 
    } 
 
    char fromColumn = move[0]; 
    char fromRow = move[1]; 
    char toColumn = move[3]; 
    char toRow = move[4]; 
 
    c1 = fromColumn - 'a'; 
    r1 = 8 - (fromRow - '0'); 
    c2 = toColumn - 'a'; 
    r2 = 8 - (toRow - '0'); 
} 
 
int main() { 
    Board b; 
    b.createBoard(); 
 
    string message = "";//this will store the message to output later 
    //ex. invalid move or check, etc. 
    while (true) { 
        b.displayBoard(); 
        cout << (b.getCurrentTurn() == WHITE ? "\nWhite" : "\nBlack") << " to 
move\n"; 
        if (!message.empty()) {// this chunk is self explanatory 
            cout << message << "\n"; 
            message = ""; 
        } 
 
        // check/checkmate messages 
        if (b.isKingChecked(b.getCurrentTurn())) { 
            cout << "CHECK!\n"; 
 
            if (b.isCheckmate(b.getCurrentTurn())) { 
                cout << "CHECKMATE!\n"; 
                cout << (b.getCurrentTurn() == WHITE ? "Black wins!\n" : "White 
wins!\n"); 
                break; 
            } 
        } 
        // stalemate messages 
        else if (b.isStalemate(b.getCurrentTurn())) { 
            cout << "STALEMATE!\n"; 
            cout << "Draw game.\n"; 
            break; 
        } 
 
        cout << "\nEnter move (e.g., e2 e4): "; 
        string move; 
        getline(cin, move); // receiving player movement input 
        int r1, c1, r2, c2; 
        getPlayerMove(move, r1, c1, r2, c2); 
 
        if (b.isMoveLegal(r1, c1, r2, c2)) { 
            b.movePiece(r1, c1, r2, c2); 
        } 
        else { 
            message = "Illegal move."; 
        } 
    } 
 
    return 0; 
}
