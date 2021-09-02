#include<iostream>
#include<string>
#include "Agent.h"
#include "Board.h"
#include "constants_and_macros.h"

const char AGENT_CHAR = 'O';

int main() {

    char response;
    srand(time(NULL));
    beginRun:
    CLEAR_WINDOW;
    Board board;
    Agent agent(AGENT_CHAR, &board);

    agent.place();

    while (!agent.reachedGoal()) {
        CLEAR_WINDOW;
        agent.move();
        agent.place();
        board.drawBoard();
        agent.printPosition();
        if (agent.isStuck())
            break;
        SLEEP(100);
    }

    if (!agent.reachedGoal() && agent.isStuck())
        std::cout << "Failure." << std::endl;
    else
        std::cout << "Success!" << std::endl;

    prompt:
    // std::cout << "Run again? (y/n)" << std::endl;
    std::cout << "Run:  (1)" << std::endl;
    std::cout << "Exit: (0)" << std::endl;
    std::cin >> response;
    FLUSH_BUFFER;
    if (response == '1')
        goto beginRun;
    else if (response != '0') {
        std::cout << "Unrecognized response \"" << response << "\"." << std::endl;
        goto prompt;
    }

    return 0;
}