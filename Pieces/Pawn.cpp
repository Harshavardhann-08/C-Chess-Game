#include "Pawn.h" 
#include "Board.h" 
//pawn is the easiest piece to program 
bool Pawn::isMoveLegal(Board* board, int r1, int c1, int r2, int c2) { 
    int direction = (color == WHITE ? -1 : 1); 
 
// here is pawn's forward movement. 
    if (c1 == c2) {//1 square 
        if (r2 == r1 + direction && board->getPiece(r2, c2) == nullptr) 
            return true; 
 
        // 2 squares on first move: 
        if (firstMove && 
            r2 == r1 + 2 * direction && 
            board->getPiece(r1 + direction, c1) == nullptr && 
            board->getPiece(r2, c2) == nullptr) 
            return true; 
    } 
    // pawn diagonal piece capturing logic 
    if ((c2 == c1 - 1 || c2 == c1 + 1) && r2 == r1 + direction) { 
        Piece* target = board->getPiece(r2, c2); 
 
        if (target != nullptr && target->getColor() != this->color) 
            return true; 
    } 
    return false; 
    //these ismovelegal functions basically run through all legal checks and then 
otherwise return illegal 
} 
 
char Pawn::getSymbol() { 
    return (color == WHITE ? 'P' : 'p'); 
}
