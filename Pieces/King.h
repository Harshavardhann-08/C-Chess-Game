#pragma once 
#include "Piece.h" 
class King : public Piece { 
public: 
King(Color c, int r, int col) : Piece(c, r, col) {} 
//kings have no special members (aside from unimpllemented castling first moves) 
bool isMoveLegal(Board* board, int r1, int c1, int r2, int c2) override; 
char getSymbol() override; 
};
