#pragma once 
#include "Piece.h" 
class Bishop : public Piece { 
public: 
Bishop(Color c, int r, int col) : Piece(c, r, col) {} 
//bishops have no special members 
bool isMoveLegal(Board* board, int r1, int c1, int r2, int c2) override; 
char getSymbol() override; 
};
