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
    this->current_shape = this->next_shape;
    this->current_rotation = this->next_rotation;
    this->current_x_pos = (GRID_WIDTH / 2) + tetrominos->get_init_y_pos(this->current_shape, this->current_rotation);
    this->current_y_pos = tetrominos->get_init_y_pos(this->current_shape, this->current_rotation);

    // generate next tetromino attributes
    this->next_shape = generate_random_integer(0, 6);
    this->next_rotation = generate_random_integer(0, 3);
}

/*
 * Initialize game objects (grid, current tetromino, next tetromino)
 */
void Logic::init_game() {
    generate_grid();
    generate_tetromino_tiles(this->current_x_pos, this->current_y_pos, this->current_shape, this->current_rotation);
    generate_tetromino_tiles(this->next_x_pos, this->next_y_pos, this->next_shape, this->next_rotation);
}

/*
 * Initialize game logic variables
 */
void Logic::init_game_logic() {
    // pseudo-random non-negative number generator
    srand ((unsigned int) time(NULL));

    // current tetromino
    this->current_shape = generate_random_integer(0, 6); // 7 shapes
    this->current_rotation = generate_random_integer(0, 3); // 4 rotations
    this->current_x_pos = (GRID_WIDTH / 2) + tetrominos->get_init_x_pos(this->current_shape, this->current_rotation);
    this->current_y_pos = tetrominos->get_init_y_pos(this->current_shape, this->current_rotation);

    // next tetromino
    this->next_x_pos = GRID_WIDTH + 5; // right side of grid border
    this->next_y_pos = 5;
    this->next_shape = generate_random_integer(0, 6); // 7 shapes
    this->next_rotation = generate_random_integer(0, 3); // 4 rotations
}

/*
 * Generate grid borders and placed tetromino tiles
 */
void Logic::generate_grid() {
    // calculate grid borders in pixels
    int left_border = GRID_HORIZ_CENTER - (TILE_SIZE * (GRID_WIDTH / 2)) - 1; // 0-indexed
    int right_border = GRID_HORIZ_CENTER + (TILE_SIZE * (GRID_WIDTH / 2));
    int top_border = this->screen_height - (TILE_SIZE * GRID_HEIGHT); // 0-indexed from top to bottom

    // render grid borders
    rendering_engine->render_tile(left_border - GRID_BORDER_WIDTH, top_border, left_border, this->screen_height - 1, Color::WHITE);
    rendering_engine->render_tile(right_border, top_border, right_border + GRID_BORDER_WIDTH, this->screen_height - 1, Color::WHITE);
	
	// render tetromino tiles that were placed in the grid
    grid_left = left_border + 1;
    for (int tile_x; tile_x < GRID_WIDTH; tile_x++) {
        for (int tile_y; tile_y < GRID_HEIGHT; tile_y++) {
            if (grid->is_empty_tile(tile_x, tile_y) == false) {
                rendering_engine->render_tile(grid_left + tile_x * TILE_SIZE, top_border + tile_y * TILE_SIZE, 
                                            grid_left + (tile_x + 1) * TILE_SIZE - 1, top_border + (tile_y + 1) * TILE_SIZE - 1, Color::RED);
            }
        }
    }
}

/*
 * Generate attributes for the tiles of a tetromino and render it to screen
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
