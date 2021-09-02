#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include<iostream>
#include<fstream>

const int NUM_COLS = 15;
const int NUM_ROWS = 15;
// There should be an obstacle in every row. Top and bottom rows are border.
const int NUM_OBSTACLES = NUM_ROWS - 2;

class Board {
    public:
        Board(void);
        void generateObstacles(void);
        void placeObstacles(void);
        void initBoard(void);
        void drawBorder(void);
        void drawBoard(void);
        void placeCharacter(int r, int c, char x)   {board[r][c] = x;};
        int obstacles[NUM_OBSTACLES][2];
    private:
        char board[NUM_ROWS][NUM_COLS];
};

#endif