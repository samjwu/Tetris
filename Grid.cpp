#include "Grid.h"

/*
 * Initialize tiles to empty in grid
 */
void Grid::init_grid() {
    for (int grid_x = 0; grid_x < GRID_WIDTH; grid_x++) {
        for (int grid_y = 0; grid_y < GRID_HEIGHT; grid_y++) {
            grid[grid_x][grid_y] = EMPTY;
        }
    }
}

/*
 * Clear a line by moving all tiles above the line down by one row
 * Note grid_y is 0-indexed in order of top to bottom
 */
void Grid::clear_line(int y) {
    for (int grid_y = y; grid_y > 0; grid_y--) {
        for (int grid_x = 0; grid_x < GRID_WIDTH; grid_x++) {
            grid[grid_x][grid_y] = grid[grid_x][grid_y - 1];
        }
    }
}

/*
 * Fill in tiles in the grid to place a tetromino
 */
void Grid::place_tetromino(int x, int y, int shape, int rotation) {
    int grid_x, grid_y;
    int tetromino_x, tetromino_y;
    for (grid_x = x, tetromino_x = 0; grid_x < x + TILES_PER_TETROMINO; grid_x++; tetromino_x++) {
        for (grid_y = y, tetromino_y = 0; grid_y < y + TILES_PER_TETROMINO; grid_y++; tetromino_y++) {
            if (tetrimonos->get_tetromino_tile(shape, rotation, tetromino_x, tetromino_y) != EMPTY) {
                grid[grid_x][grid_y] = FULL;
            }
        }
    }
}

/*
 * Check for game over state (when top grid tile/position is full)
 * Note grid_y = 0 is the top row
 */
bool Grid::game_over() {
    for (int grid_x = 0; grid_x < GRID_WIDTH; grid_x++) {
        if (grid[grid_x][0] == FULL) {
            return true;
        }
    }
    return false;
}