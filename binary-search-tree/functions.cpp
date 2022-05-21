#include "functions.h"

int random_range(int min, int max) {
    //returns a random number between min and max inclusive
    return (std::rand() % (max - min + 1)) +min;
}

