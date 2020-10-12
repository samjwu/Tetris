#include "Grid.h"

/*
 * Initialize tiles to empty in grid
 */
void Grid::init_grid() {
    for (int row=0; row<GRID_WIDTH; row++) {
        for (int col=0; col<GRID_HEIGHT; col++) {
            grid[row][col] = EMPTY;
        }
    }
}

/*
 * Fill in tiles to place a tetromino
 */
void Grid::place_tetromino(int x, int y, int shape, int rotation) {
    int tetromino_x, tetromino_y;
    int tile_x, tile_y;
    for (tetromino_x = x, tile_x = 0; tetromino_x < x + TILES_PER_TETROMINO; tetromino_x++; tile_x++) {
        for (tetromino_y = y, tile_y = 0; tetromino_y < y + TILES_PER_TETROMINO; tetromino_y++; tile_y++) {
            if (tetrimonos->get_tetromino_tile(shape, rotation, tile_x, tile_y) != 0) {
                grid[tetromino_x][tetromino_y] = FULL;
            }
        }
    }
}