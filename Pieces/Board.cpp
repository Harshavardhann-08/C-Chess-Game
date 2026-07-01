#include "Board.h" 
#include "Pawn.h" 
#include "Rook.h" 
#include "Bishop.h" 
#include "Knight.h" 
#include "Queen.h" 
#include "King.h" 
#include <iostream> 
using namespace std; 
 
Board::Board() { 
    for (int i = 0; i < 8; i++) 
        for (int j = 0; j < 8; j++) 
            board[i][j] = nullptr; 
// this constructor initializes the board with null pieces and sets the first turn 
to white's 
    currentTurn = WHITE; 
} 
 
Board::~Board() { 
    for (int i = 0; i < 8; i++) 
        for (int j = 0; j < 8; j++) 
            delete board[i][j]; 
} // deletes the board when done 
 
void Board::createBoard() { 
    for (int j = 0; j < 8; j++) { 
        //inserting pawns into the board 
        board[6][j] = new Pawn(WHITE, 6, j); 
        board[1][j] = new Pawn(BLACK, 1, j); 
    } 
    //insert rooks 
    board[7][0] = new Rook(WHITE, 7, 0); 
    board[7][7] = new Rook(WHITE, 7, 7); 
    board[0][0] = new Rook(BLACK, 0, 0); 
    board[0][7] = new Rook(BLACK, 0, 7); 
    //insert knights 
    board[7][1] = new Knight(WHITE, 7, 1); 
    board[7][6] = new Knight(WHITE, 7, 6); 
    board[0][1] = new Knight(BLACK, 0, 1); 
    board[0][6] = new Knight(BLACK, 0, 6); 
    //insert bishops 
    board[7][2] = new Bishop(WHITE, 7, 2); 
    board[7][5] = new Bishop(WHITE, 7, 5); 
    board[0][2] = new Bishop(BLACK, 0, 2); 
    board[0][5] = new Bishop(BLACK, 0, 5);
     //insert queens 
    board[7][3] = new Queen(WHITE, 7, 3); 
    board[0][3] = new Queen(BLACK, 0, 3); 
    //insert kings 
    board[7][4] = new King(WHITE, 7, 4); 
    board[0][4] = new King(BLACK, 0, 4); 
} 
 
void Board::displayBoard() { 
    cout << "\033[2J\033[1;1H"; 
    // file grid printout 
    for (int i = 0; i < 8; i++) { 
        cout << (8 - i) << " "; 
        for (int j = 0; j < 8; j++) { 
            if (board[i][j] == nullptr) 
                cout << "- "; 
            else 
                cout << board[i][j]->getSymbol() << " "; 
        }// empty squares on board are - 
        cout << "\n"; 
    } 
    //again print file grid 
    cout << "  a b c d e f g h\n"; 
} 
 
bool Board::isMoveLegal(int r1, int c1, int r2, int c2) { 
    Piece* p = getPiece(r1, c1); 
    if (!p) return false; // if piece doesnt exists, illegal 
 
    if (p->getColor() != currentTurn) 
        return false;// if its not your turn, illegal 
 
    if (!p->isMoveLegal(this, r1, c1, r2, c2)) 
        return false; // if cannot pass, illegal 
 
    //simulating moves on the board for checks 
    Piece* captured = board[r2][c2]; 
    board[r2][c2] = p; 
    board[r1][c1] = nullptr; 
    //basically temporarily moving a piece somewhere to test legality 
    int oldR = p->getRow(); 
    int oldC = p->getCol(); 
    p->updatePosition(r2, c2); 
    //now we check if the king is in check after the temporary move 
    bool kingInCheck = isKingChecked(currentTurn); 

 // move the piece back after the check 
    board[r1][c1] = p; 
    board[r2][c2] = captured; 
    p->updatePosition(oldR, oldC); 
 
    if (kingInCheck)// if king is in check the move is illegal 
        return false; 
 
    return true; 
} 
 
void Board::movePiece(int r1, int c1, int r2, int c2) { 
    Piece* p = board[r1][c1]; 
 
    if (board[r2][c2] != nullptr) { 
        delete board[r2][c2]; 
    }// move the piece to new spot and replace it with a null ptr "-" 
 
    board[r2][c2] = p; 
    board[r1][c1] = nullptr; 
    p->updatePosition(r2, c2);

//swap the turns 
    currentTurn = (currentTurn == WHITE ? BLACK : WHITE); 
 
    if (Pawn* pawn = dynamic_cast<Pawn*>(p)) 
        pawn->firstMove = false; 
} 
 
bool Board::isKingChecked(Color kingColor) { 
    int kingR = -1, kingC = -1; 
    //firstly we must locate the king, r = row, c = column 
    for (int r = 0; r < 8; r++) { 
        for (int c = 0; c < 8; c++) { 
            Piece* p = board[r][c]; 
            if (p && p->getColor() == kingColor) { 
                if (p->getSymbol() == 'K' || p->getSymbol() == 'k') { 
                    kingR = r; 
                    kingC = c; 
                } 
            } 
        } 
    } 
 
    if (kingR == -1) return false; // if king is not found, its not checked 
    for (int r = 0; r < 8; r++) { 
        for (int c = 0; c < 8; c++) { 
            Piece* p = board[r][c]; // checking pieces to see if their moves are 
legal 
            if (p && p->getColor() != kingColor) { 
                if (p->isMoveLegal(this, r, c, kingR, kingC)) { 
                    return true; 
                } 
            } 
        } 
    } 
 
    return false; 
} 

bool Board::isCheckmate(Color kingColor) { 
    if (!isKingChecked(kingColor)) 
        return false; 
 
    for (int r1 = 0; r1 < 8; r1++) { 
        for (int c1 = 0; c1 < 8; c1++) { 
            Piece* p = board[r1][c1]; 
            //essentially we are checking if the king has ANY method to escape or 
block with another piece 
            if (p && p->getColor() == kingColor) { 
                for (int r2 = 0; r2 < 8; r2++) { 
                    for (int c2 = 0; c2 < 8; c2++) { 
 
                        if (isMoveLegal(r1, c1, r2, c2)) { 
                            return false; 
                        } 
 
                    } 
                } 
            } 
        } 
    }

 return true; 
} 
bool Board::isStalemate(Color playerColor) { 
    if (isKingChecked(playerColor)) 
        return false; 
    // if the king is checked, stalemate is impossible! ^^^^^ 
    for (int r1 = 0; r1 < 8; r1++) { 
        for (int c1 = 0; c1 < 8; c1++) { 
            Piece* p = board[r1][c1]; 
            //checking the pieces of the board 
            if (p && p->getColor() == playerColor) { 
                for (int r2 = 0; r2 < 8; r2++) { 
                    for (int c2 = 0; c2 < 8; c2++) { 
 
                        if (isMoveLegal(r1, c1, r2, c2)) { 
                            return false; // has at least one move 
                        } 
 
                    } 
                } 
            } 
        } 
    } 
 
    return true; // no legal moves and not in check 
} 

