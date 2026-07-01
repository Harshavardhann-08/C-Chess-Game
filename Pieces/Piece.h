#pragma once 
 
enum Color { WHITE, BLACK }; 
class Board; 
 
class Piece { 
protected: 
    Color color; 
    int row, col; // position 
 
public: 
    Piece(Color c, int r, int cc); 
    virtual ~Piece() {} 
 
    Color getColor() const { return color; } 
    int getRow() const { return row; } 
    int getCol() const { return col; } 
    void updatePosition(int r, int c); 
    virtual bool isMoveLegal(Board* board, int r1, int c1, int r2, int c2) = 0; 
    virtual char getSymbol() = 0; // if its P or p upper or lowercase for ex. 
    // uppercase is white, lowercase is black. 
}; 
