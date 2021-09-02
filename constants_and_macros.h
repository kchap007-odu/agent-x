#ifndef MACROS_H_INCLUDED
#define MACROS_H_INCLUDED

#include<cstdlib>
#include<limits>
#include<ctime>

#define FLUSH_BUFFER std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')

/*
    From stackoverflow: https://stackoverflow.com/questions/6424911/link-error-with-really-simple-functions-c-on-h-file
    Need to declare function as inline or a multiple definition error
    occurs during linking. Include guards prevent multiple inclusion of
    headers at compile time when performing a single compile, but does
    not persist when linking multiple object files together.
*/

inline int randBetween(int min, int max) {return (rand() % ((max + 1) - min)) + (min);};


// For cross-platform functionality.
#if defined(_WIN32) || defined(WIN32)
    #include <windows.h> // for Sleep
    #define CLEAR_WINDOW system("CLS")
    #define SLEEP(x) Sleep(x)
#elif defined(__unix__)
    #include <unistd.h> // for usleep
    #define CLEAR_WINDOW system("clear")
    #define SLEEP(x) usleep(x * 1000)
#endif


#endif