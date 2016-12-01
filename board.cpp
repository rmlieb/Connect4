#include "board.h"

Board::Board() {
}

Board::Board(const string &fen) {
}

void Board::printBoard_as_FENstring(ostream &os) const {
}

PieceType Board::atLocation(int row, int col) {
    return data[row][col];
}

void Board::prettyPrintBoard(ostream &os) const {
	os << endl;
    for (int row = NUM_ROWS - 1; row >= 0; row--)  {
        os << "     +---+---+---+---+---+---+---+"
           << endl
           << "    ";
        
        for (int col = 0; col < NUM_COLS; col++)   {
            os << " | " ;
            if ( data[row][col] == Player1)
                os <<  PLAYER1_TOKEN;
            else if (data[row][col] == Player2)
                os << PLAYER2_TOKEN;
            else
                os << EMPTY_TOKEN;
        }
        os << " |" << endl;
    }
    os << "     +---+---+---+---+---+---+---+" << endl
       <<"  col  1   2   3   4   5   6   7" << endl;
    return;
}

PieceType Board::atLocation(int row, int col) {
    return data[row][col];
}

int Board::toMove() const {
    if(nextPlayer_to_move == Player1){
        return 1;
    }
    else(nextPlayer_to_move == Player2){
        return 2;
    }
}

Result Board::makeMove(int col) {
    if(getFirstFreeRow[col] == NUM_ROWS){
        return IllegalMove;
    }
    // Put piece in board
    data[getFirstFreeRow(col)][col] = nextPlayer_to_move;
    updateToMove();
    
    if(isWin()) {
        return Win;
    }
    else if(isBoardFull()) {
        return Draw;
    }
    else {
        return NoResult;
    }
    
    
}

int Board::getFirstFreeRow(int col) const {
    return NUM_ROWS;
}

PieceType Board::updateToMove() {
    if(nextPlayer_to_move == Player1){
        nextPlayer_to_move == Player2;
        return Player2;
    }
    else(nextPlayer_to_move == Player2){
        nextPlayer_to_move == Player1;
        return Player1;
    }
}

bool Board::isBoardFull() const {
    return false;
}

bool Board::inBounds(int row, int col) const {
    return false;
}

int Board::piecesInDirection(int row, int col, int dRow, int dCol) const {
    for(dRow = 0; dRow < 4; dRow++) {
        for(dCol = 3; dCol < 4; dCol++){
            if([row][col]
        }
    }
}

bool Board::isWin(int row, int col) const {
    return false;
}


