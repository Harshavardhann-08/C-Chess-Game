#pragma once 
#include "Piece.h" 
class Pawn : public Piece { 
public: 
bool firstMove = true; 
//pawns have a special property of first move, where after their 
//first move they cannot move 2 squares ahead. 
Pawn(Color c, int r, int col) : Piece(c, r, col) {} 
bool isMoveLegal(Board* board, int r1, int c1, int r2, int c2) override; 
char getSymbol() override; 
};
