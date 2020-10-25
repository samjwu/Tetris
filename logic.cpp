#include "Logic.h"

/*
 * Constructor. Initializes game logic variables.
 */
void Logic::Logic(Grid *grid, Tetrominos *tetrominos, RenderingEngine *rendering_engine, int screen_height) {
    this->grid = grid;
    this->tetrominos = tetrominos;
    this->rendering_engine = rendering_engine;
    this->screen_height = screen_height;
    init_game_logic();
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

/*
 * Initialize game logic variables
 */
void Logic::init_game_logic() {
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
void Logic::generate_tetromino_tiles(int x, int y, int shape, int rotation) {
    Color tile_color;

    // pixel position for new tile
    int tile_x_pixel = grid->get_tile_x_pixel_pos(x);
    int tile_y_pixel = grid->get_tile_y_pixel_pos(y);

    for (int tile_y = 0; tile_y < TETROMINO_TILE_LENGTH; tile_y++) {
        for (int tile_x = 0; tile_x < TETROMINO_TILE_LENGTH; tile_x++) {
            switch (tetrominos->get_tile_type(shape, rotation, tile_x, tile_y)) {
                case TileType::NORMAL:
                    tile_color = Color::BLUE;
                    break;
                case TileType::PIVOT:
                    tile_color = Color::WHITE;
                    break;
            }

            if (tetrominos->get_tile_type(shape, rotation, tile_x, tile_y) != TileType::EMPTY) {
            
            }
        }
    }
}

/*
 * Generate random integer between a and b inclusive
 * Input assumption is that b > a
 */
int Logic::generate_random_integer(int a, int b) {
    return std::rand() % (b - a + 1) + a;
}
