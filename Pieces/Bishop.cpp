#include "Bishop.h" 
#include "Board.h" 
#include "Piece.h" 
#include <iostream> 
// bishops are a small step up in difficulty from rooks because they add another 
axis of movement 
bool Bishop::isMoveLegal(Board* board, int r1, int c1, int r2, int c2) { 
    if (r1 == r2 && c1 == c2)// cant move to the same place its currently in 
        return false; 
    // must move diagonally 
    int dr = r2 - r1; 
    int dc = c2 - c1; 
    if (abs(dr) != abs(dc)) 
        return false; 
    // determine direction 
    int stepR = (dr > 0) ? 1 : -1; 
    int stepC = (dc > 0) ? 1 : -1; 
    // diagonal movement 
    int r = r1 + stepR; 
    int c = c1 + stepC; 
    while (r != r2 && c != c2) { 
        if (board->getPiece(r, c) != nullptr) 
            return false; // blocked 
        r += stepR; 
        c += stepC; 
    } 
    Piece* target = board->getPiece(r2, c2); 
    if (target != nullptr && target->getColor() == this->color) 
        return false; // can't capture your own piece, this is to be put 
    // in all future pieces legal move function. 
    return true; 
} 
 
char Bishop::getSymbol() { 
    return (color == WHITE ? 'B' : 'b'); // if its white, then do R, else black is 
r. 
}
