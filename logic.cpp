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
    this->shape = this->next_shape;
    this->rotation = this->next_rotation;
    this->x_pos = (GRID_WIDTH / 2) + tetrominos->get_init_y_pos(this->shape, this->rotation);
    this->y_pos = tetrominos->get_init_y_pos(this->shape, this->rotation);

    // generate next tetromino attributes
    this->next_shape = generate_random_integer(0, 6);
    this->next_rotation = generate_random_integer(0, 3);
}

/*
 * Initialize game objects
 */
void Logic::init_game() {
    generate_grid();
    generate_tetromino_tiles(this->x_pos, this->y_pos, this->shape, this->rotation);
    generate_tetromino_tiles(this->next_x_pos, this->next_y_pos, this->next_shape, this->next_rotation);
}

/*
 * Initialize game logic variables
 */
void Logic::init_game_logic() {
    // pseudo-random non-negative number generator
    srand ((unsigned int) time(NULL));

    // current tetromino
    this->shape = generate_random_integer(0, 6); // 7 shapes
    this->rotation = generate_random_integer(0, 3); // 4 rotations
    this->x_pos = (GRID_WIDTH / 2) + tetrominos->get_init_x_pos(this->shape, this->rotation);
    this->y_pos = tetrominos->get_init_y_pos(this->shape, this->rotation);

    // next tetromino
    this->next_x_pos = GRID_WIDTH + 5; // right side of grid border
    this->next_y_pos = 5;
    this->next_shape = generate_random_integer(0, 6); // 7 shapes
    this->next_rotation = generate_random_integer(0, 3); // 4 rotations
}

/*
 * Generate grid 
 */
void Logic::generate_grid() {

}

/*
 * Generate attributes for the tiles of a tetromino
 */
void Logic::generate_tetromino_tiles(int tetromino_x, int tetromino_y, int tetromino_shape, int tetromino_rotation) {
    Color tile_color;

    // pixel position for new tile
    int tetromino_x_pixel = grid->get_tile_x_pixel_pos(tetromino_x);
    int tetromino_y_pixel = grid->get_tile_y_pixel_pos(tetromino_y);

    for (int tile_y = 0; tile_y < TETROMINO_TILES_PER_SIDE; tile_y++) {
        for (int tile_x = 0; tile_x < TETROMINO_TILES_PER_SIDE; tile_x++) {
            switch (tetrominos->get_tile_type(tetromino_shape, tetromino_rotation, tile_x, tile_y)) {
                case TileType::NORMAL:
                    tile_color = Color::BLUE;
                    break;
                case TileType::PIVOT:
                    tile_color = Color::WHITE;
                    break;
            }

            if (tetrominos->get_tile_type(tetromino_shape, tetromino_rotation, tile_x, tile_y) != TileType::EMPTY) {
                rendering_engine->render_tile(tetromino_x_pixel + tile_x * TILE_SIZE, tetromino_y_pixel + tile_y * TILE_SIZE, 
                                            tetromino_x_pixel + (tile_x + 1) * TILE_SIZE - 1, tetromino_y_pixel + (tile_y + 1) * TILE_SIZE - 1, tile_color);
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
