#pragma once 
#include "Piece.h" 
 
class Board { 
private: 
    Piece* board[8][8]; 
    Color currentTurn; 
    //board is an 8x8 array of Pieces 
public: 
    Board(); 
    ~Board(); 
 
    void createBoard(); 
    void displayBoard(); 
 
    Piece* getPiece(int r, int c) { 
        if (r < 0 || r >= 8 || c < 0 || c >= 8) 
            return nullptr; 
        return board[r][c]; 
    } 
    //these functions are all pretty self-explanatory 
    bool isMoveLegal(int r1, int c1, int r2, int c2); 
    void movePiece(int r1, int c1, int r2, int c2); 
    bool isKingChecked(Color kingColor); 
    bool isCheckmate(Color kingColor); 
    Color getCurrentTurn() const { return currentTurn; } 
    bool isStalemate(Color playerColor); 
};
