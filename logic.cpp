#include "logic.h"

/*
 * Initialize game logic variables
 */
void Logic::init_game() {
    // pseudo-random non-negative number generator
    srand ((unsigned int) time(NULL));

    // current tetromino
    shape = generate_random_integer(0, 6); // 7 shapes
    rotation = generate_random_integer(0, 3); // 4 rotations
    x_pos = (GRID_WIDTH / 2) + tetrominos->get_init_x_pos(shape, rotation);
    y_pos = tetrominos->get_init_y_pos(shape, rotation);

    // next tetromino
    next_x_pos = GRID_WIDTH + 5; // right side of grid border
    next_y_pos = 5;
    next_shape = generate_random_integer(0, 6); // 7 shapes
    next_rotation = generate_random_integer(0, 3); // 4 rotations
}

/*
 * Generate attributes for the tiles of a tetromino
 */
void Logic::generate_tetromino_tiles() {

}

/*
 * Generate random integer between a and b inclusive
 * Input assumption is that b > a
 */
int Logic::generate_random_integer(int a, int b) {
    return std::rand() % (b - a + 1) + a;
}

/*
 * Create a new tetromino 
 */
void Logic::create_new_tetromino() {
    // set new tetromino attributes
    shape = next_shape;
    rotation = next_rotation;
    x_pos = (GRID_WIDTH / 2) + tetrominos->get_init_y_pos(shape, rotation);
    y_pos = tetrominos->get_init_y_pos(shape, rotation);

    // generate next tetromino attributes
    next_shape = generate_random_integer(0, 6);
    next_rotation = generate_random_integer(0, 3);
}