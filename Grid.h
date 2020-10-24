#ifndef _GRID_
#define _GRID_

#include "Tetrominos.h"

#define GRID_BORDER_WIDTH 6 // measured in pixels
#define MIN_VERT_MARGIN 20 // measured in pixels
#define MIN_HORIZ_MARGIN 20 // measured in pixels
#define GRID_HORIZ_CENTER 320 // middle of grid horizontally measured in pixels
#define TILE_SIZE 16 // tiles are 16x16 pixels
#define TETROMINO_TILE_LENGTH 5 // tetrominos are 5x5 tiles
#define GRID_WIDTH 10 // measured in tiles
#define GRID_HEIGHT 20 // measured in tiles

class Grid {
    private:
        enum {EMPTY = 0, FULL = 1};
        int screen_height; // measured in pixels
        int grid[GRID_WIDTH][GRID_HEIGHT];
        Tetrominos *tetrominos;

        void init_grid();
        void clear_line(int y);

    public: 
        Grid(Tetrominos *tetrominos, int screen_height);

        void clear_full_lines();
        void place_tetromino(int x, int y, int shape, int rotation);
        bool game_over();
        bool is_empty_tile(int x, int y);
        bool can_move(int x, int y, int shape, int rotation);
        int get_x_pixel_pos(int x);
        int get_y_pixel_pos(int y);
};
 
#endif // _GRID_