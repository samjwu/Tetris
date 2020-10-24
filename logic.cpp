#include "logic.h"

/*
 * Generate random integer between a and b
 * Input assumption is that b > a
 */
int Logic::generate_random_integer(int a, int b) {
    return std::rand() % (b - a + 1) + a;
}