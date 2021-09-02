#include "Agent.h"

Agent::Agent (char c, Board* b) {
    linkBoard(b);
    initMoveTrackers();
    repr = c;
    row = NUM_ROWS - 2;
    // Place the agent. If space is occupied, try again.
    retry:
    col = randBetween(1, NUM_COLS - 2);
    numTimesOnSpace[row][col]++;
    if (checkCollision(row, col))
        goto retry;
}

void Agent::initMoveTrackers(void) {
    for (int i = 0; i < NUM_ROWS; i++)
        for (int j = 0; j < NUM_COLS; j++) {
            deadEnds[i][j] = false;
            numTimesOnSpace[i][j] = 0;
        }
}

bool Agent::checkCollision(int r, int c) {
    // Check for collision with walls.
    if ((r == NUM_ROWS - 1) || (c == NUM_COLS - 1) || (r == 0) || (c == 0))
        deadEnds[r][c] = true;
    // Check for collision with obstacles.
    for (int i = 0; i < NUM_OBSTACLES; i++)
        if (r == board->obstacles[i][0] && c == board->obstacles[i][1])
            deadEnds[r][c] = true;
    // Check whether the location has been previously deemed a dead end.
    return deadEnds[r][c];
}

unsigned char Agent::getAvailableMoves(void) {
    /*
        Returns a binary value where moves not resulting in a collision are
        represented from bit 0 to bit 4 as ones, indicating the move is
        available, or zero, indicating the move is not available.
    */
    unsigned char available = 0;
    unsigned char numMoves = 0;

    if (!checkCollision(row - 1, col))
        available += UP;
    if (!checkCollision(row + 1, col))
        available += DOWN;
    if (!checkCollision(row, col - 1))
        available += LEFT;
    if (!checkCollision(row, col + 1))
        available += RIGHT;

    // Tally the number of moves available while on this space.
    for (int i = 0; i < 4; i++)
        numMoves += (available >> (i)) & 1;

    /*
        Flag the space as a dead end if the agent has been on
        the space more than the maximum number of times or preemtively Flag
        as a dead end if only one move is available.
    */
    deadEnds[row][col] = ((numTimesOnSpace[row][col] >= MAX_TIMES_ON_SPACE) || numMoves == 1);
        // deadEnds[row][col] = true;

    return available;
}

void Agent::move(void) {
    // Remove the agent character from it's previous position on the board.
    board->placeCharacter(row, col, ' ');
    // Check for available moves.
    unsigned char moves =  getAvailableMoves();
    if (moves & UP)
        row--;
    else if (moves & LEFT)
        col--;
    else if (moves & RIGHT)
        col++;
    else if (moves & DOWN)
        row++;

    numTimesOnSpace[row][col]++;
}