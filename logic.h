#ifndef _LOGIC_
#define _LOGIC_

#include <time.h>

#include "Grid.h"
#include "Tetriminos.h"

#define DELAY 750 // delay before tetromino falls each tick measured in ms

class Logic {
    private:
        int screen_height; // measured in pixels
        int next_x_pos, next_y_pos;
        int next_shape;
        int next_rotation;
        Grid *grid;
        Tetrominos *tetrominos;
        
        int generate_random_integer(int a, int b);
        void init_game();
        void init_create_grid();
        void create_tetromino(int x, int y, int shape, int rotation);

    public:
        Logic(Grid *grid, Tetrominos *tetrominos);
};
 
#endif // _LOGIC_