#pragma once 
#include "Piece.h" 
class Knight : public Piece { 
public: 
Knight(Color c, int r, int col) : Piece(c, r, col) {} 
//knights have no special members 
bool isMoveLegal(Board* board, int r1, int c1, int r2, int c2) override; 
char getSymbol() override; 
};
