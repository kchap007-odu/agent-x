#include "Board.h"
#include "constants_and_macros.h"

Board::Board(void) {
    initBoard();
    generateObstacles();
    placeObstacles();
}

void Board::generateObstacles(void) {
    for (int i = 0; i < NUM_OBSTACLES; i++) {
        obstacles[i][0] = i+1;
        obstacles[i][1] = randBetween(1, NUM_COLS - 2);;
    }
}

void Board::placeObstacles(void) {
    for (int i = 0; i < NUM_OBSTACLES; i++)
        board[obstacles[i][0]][obstacles[i][1]] = 'X';
}

void Board::initBoard(void) {
    for (int i = 1; i < NUM_ROWS - 1; i++)
        for (int j = 1; j < NUM_COLS - 1; j++)
            board[i][j] = ' ';
    drawBorder();
}

void Board::drawBorder(void) {
    for (int i = 1; i < NUM_ROWS - 1; i++) {
        board[i][0] = '|';
        board[i][NUM_COLS-1] = '|';
    }
    for (int i = 0; i < NUM_COLS; i++) {
        board[0][i] = '-';
        board[NUM_ROWS-1][i] = '-';
    }
}

void Board::drawBoard(void) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++)
            std::cout << board[i][j];
        std::cout << std::endl;
    }
}