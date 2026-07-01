#include "Piece.h" 
Piece::Piece(Color c, int r, int cc) 
: color(c), row(r), col(cc) { 
} 
void Piece::updatePosition(int r, int c) { 
row = r; 
col = c; 
}
