#pragma once 
#include "Piece.h" 
class Queen : public Piece { 
public: 
Queen(Color c, int r, int col) : Piece(c, r, col) {} 
//queens have no special property 
bool isMoveLegal(Board* board, int r1, int c1, int r2, int c2) override; 
char getSymbol() override; 
};
