#ifndef _LOGIC_
#define _LOGIC_

#include <time.h>

#include "Grid.h"
#include "RenderingEngine.h"
#include "Tetriminos.h"

#define DELAY 750 // delay before tetromino falls each tick measured in ms

class Logic {
    private:
        enum class TileType {EMPTY, NORMAL, PIVOT};
        int screen_height; // measured in pixels
        int next_x_pos, next_y_pos;
        int next_shape;
        int next_rotation;
        Grid *grid;
        Tetrominos *tetrominos;
        
        void init_game();
        void generate_grid();
        void generate_tetromino_tiles(int x, int y, int shape, int rotation);
        int generate_random_integer(int a, int b);

    public:
        int x_pos, y_pos;
        int shape;
        int rotation;

        Logic(Grid *grid, Tetrominos *tetrominos);
        void create_new_tetromino();
        void create_new_grid();
};
 
#endif // _LOGIC_