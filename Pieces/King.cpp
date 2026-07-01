#include "King.h" 
#include "Board.h" 
#include <cmath> 
//kings are pretty simple when they arent in check! simple 1 square movement. 
bool King::isMoveLegal(Board* board, int r1, int c1, int r2, int c2) { 
    int dr = abs(r2 - r1); 
    int dc = abs(c2 - c1); 
 
    if (dr > 1 || dc > 1) 
        return false; 
 
    Piece* target = board->getPiece(r2, c2); 
    if (target && target->getColor() == this->color) 
        return false; 
 
    return true; 
} 
 
char King::getSymbol() { 
    return (color == WHITE ? 'K' : 'k'); 
}
