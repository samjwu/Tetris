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
        void init_game();

        int current_tetromino_x_pos, current_tetromino_y_pos; // measured in tiles
        int current_tetromino_shape;
        int current_tetromino_rotation;

    private:
        enum class TileType {EMPTY, NORMAL, PIVOT};
        
        void init_game_logic();
        void generate_grid();
        void generate_tetromino_tiles(int tetromino_x, int tetromino_y, int tetromino_shape, int tetromino_rotation);
        int generate_random_integer(int a, int b);
        
        Grid *grid;
        Tetrominos *tetrominos;
        RenderingEngine *rendering_engine;
        int screen_height; // measured in pixels
        int next_tetromino_x_pos, next_tetromino_y_pos; // measured in tiles
        int next_tetromino_shape;
        int next_tetromino_rotation;
};
 
#endif // _LOGIC_