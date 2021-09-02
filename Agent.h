#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED

#include "Board.h"

// Defined in Board.h
extern const int NUM_ROWS;
extern const int NUM_COLS;
// Defined in constants_and_macros.h
extern int randBetween(int, int);

/*
    Specify a maximum number of times a space can be stepped on
    before being flagged as dead end.
*/
const int MAX_TIMES_ON_SPACE = 3;

// Available moves are represented by bit strings.
enum MOVES {
    UP = 0b00001,
    DOWN = 0b0010,
    LEFT = 0b0100,
    RIGHT = 0b1000
};

class Agent {
    public:
        Agent(char, Board*);
        void initMoveTrackers(void);
        unsigned char getAvailableMoves(void);
        void move(void);
        bool checkCollision(int, int);
        void linkBoard(Board* b)    {board = b;};
        void place(void)            {board->placeCharacter(row, col, repr);};
        bool reachedGoal(void)      {return row == 1;};
        bool isStuck(void)          {return deadEnds[row][col];};
        void printPosition()        {std::cout << row << ", " << col << std::endl;};
    private:
        Board* board;
        bool deadEnds[NUM_ROWS][NUM_COLS];
        unsigned char numTimesOnSpace[NUM_ROWS][NUM_COLS];
        int row;
        int col;
        char repr;
};

#endif