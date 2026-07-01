#include "Queen.h" 
#include "Board.h" 
#include <cmath> 
//in essence, queens are just rooks and bishops combined into one, making them not 
too complex. 
bool Queen::isMoveLegal(Board* board, int r1, int c1, int r2, int c2) { 
    int dr = abs(r2 - r1); 
    int dc = abs(c2 - c1); 
    //determine the direction type of the queen. 
    bool straight = (r1 == r2 || c1 == c2); 
    bool diagonal = (dr == dc); 
    // the queen cant move diagonally and straight at the same time. 
    if (!straight && !diagonal) 
        return false; 
 
    int stepR = (r2 > r1 ? 1 : (r2 < r1 ? -1 : 0)); 
    int stepC = (c2 > c1 ? 1 : (c2 < c1 ? -1 : 0)); 
 
    int r = r1 + stepR; 
    int c = c1 + stepC; 
 
    while (r != r2 || c != c2) { 
        if (board->getPiece(r, c) != nullptr) 
            return false; 
        r += stepR; 
        c += stepC; 
    } 
    //checking if the targeted piece or square is an enemy color 
    Piece* target = board->getPiece(r2, c2); 
    if (target && target->getColor() == this->color) 
        return false; 
 
    return true; 
} 
 
char Queen::getSymbol() { 
    return (color == WHITE ? 'Q' : 'q'); 
} 
