#pragma once 
#include "Piece.h" 
class Rook : public Piece { 
public: 
Rook(Color c, int r, int col) : Piece(c, r, col) {} 
//rooks have no special members (except for castling first move, which isnt 
implemented) 
bool isMoveLegal(Board* board, int r1, int c1, int r2, int c2) override; 
char getSymbol() override; 
}; 
