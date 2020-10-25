#ifndef _LOGIC_
#define _LOGIC_

#include <time.h>

#include "Grid.h"
#include "RenderingEngine.h"
#include "Tetriminos.h"

#define DELAY 500 // delay before tetromino falls each tick measured in ms

class Logic {
    public:
        Logic(Grid *grid, Tetrominos *tetrominos, RenderingEngine *rendering_engine, int screen_height);
        
        void create_new_tetromino();
        void create_new_grid();

        int x_pos, y_pos;
        int shape;
        int rotation;

    private:
        enum class TileType {EMPTY, NORMAL, PIVOT};
        
        void init_game();
        void generate_grid();
        void generate_tetromino_tiles(int x, int y, int shape, int rotation);
        int generate_random_integer(int a, int b);
        
        Grid *grid;
        Tetrominos *tetrominos;
        RenderingEngine *rendering_engine;
        int screen_height; // measured in pixels
        int next_x_pos, next_y_pos;
        int next_shape;
        int next_rotation;
};
 
#endif // _LOGIC_