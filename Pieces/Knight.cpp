#include "Knight.h" 
#include "Board.h" 
#include <cmath> 
//knights are probably the 2nd easiest piece to program because their  movement is 
//not impaired by objects in the way and their movement (code-wise) is predictable. 
bool Knight::isMoveLegal(Board* board, int r1, int c1, int r2, int c2) { 
    int dr = abs(r2 - r1); 
    int dc = abs(c2 - c1); 
 
    if (!((dr == 2 && dc == 1) || (dr == 1 && dc == 2))) 
        return false; 
 
    Piece* target = board->getPiece(r2, c2); 
    if (target && target->getColor() == this->color) 
        return false; 
 
    return true; 
} 
 
char Knight::getSymbol() { 
    return (color == WHITE ? 'N' : 'n'); 
}
