#include "Rook.h" 
#include "Board.h" 
#include "Piece.h" 
#include <iostream> 
bool Rook::isMoveLegal(Board* board, int r1, int c1, int r2, int c2) { 
    if (r1 == r2 && c1 == c2)// cant move to the same place its currently in 
        return false; 
    // Must move in straight line 
    if (r1 != r2 && c1 != c2) 
        return false; 
    if (c1 == c2) {// up and down 
        int step = (r2 > r1) ? 1 : -1; // if r2 is greater than r1, step = 1 else 
step = -1 
        for (int i = r1 + step; i != r2; i += step) { 
            if (board->getPiece(i, c1) != nullptr) 
                return false; 
        } 
    } 
    else {// left and right 
        int step = (c2 > c1) ? 1 : -1; 
        for (int i = c1 + step; i != c2; i += step) { 
            if (board->getPiece(r1, i) != nullptr) 
                return false; 
        } 
    } 
    Piece* target = board->getPiece(r2, c2); 
    if (target != nullptr && target->getColor() == this->color) 
        return false; // can't capture your own piece, this is to be put 
    // in all future pieces legal move function. 
    return true; 
} 
 
char Rook::getSymbol() { 
    return (color == WHITE ? 'R' : 'r'); // if its white, then do R, else black is 
r. 
}  
