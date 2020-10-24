#ifndef _GRID_
#define _GRID_

#include "Tetrominos.h"

#define GRID_BORDER_WIDTH 6 // measured in pixels
#define TILE_SIZE 16 // measured in pixels
#define GRID_CENTER 320 // measured in pixels
#define MIN_VERT_MARGIN 20 // measured in pixels
#define MIN_HORIZ_MARGIN 20 // measured in pixels
#define TILES_PER_TETROMINO 5
#define GRID_WIDTH 10 // measured in tiles
#define GRID_HEIGHT 20 // measured in tiles

class Grid {
    private:
        enum {EMPTY = 0, FULL = 1};
        int grid[GRID_WIDTH][GRID_HEIGHT];
        int screen_height;
        Tetrominos *tetrominos;

        void init_grid();
        void clear_line();

    public: 
        Grid(Tetrominos *tetrominos, int screen_height);

        int get_x_pixel_pos(int x);
        int get_y_pixel_pos(int y);
        bool is_empty_tile(int x, int y);
        bool can_move(int x, int y, int shape, int rotation);
        void place_tetromino(int x, int y, int shape, int rotation);
        void clear_lines();
        bool game_over();
};
 
#endif // _GRID_