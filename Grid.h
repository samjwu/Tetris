#ifndef _GRID_
#define _GRID_

#include "Tetrominos.h"

#define GRID_BORDER_WIDTH 6
#define TILE_SIZE 16
#define GRID_CENTER 320
#define MIN_VERT_MARGIN 20
#define MIN_HORIZ_MARGIN 20
#define TILES_PER_TETROMINO 5
#define GRID_WIDTH 10 // measured in tiles
#define GRID_HEIGHT 20 // measured in tiles

class Grid {
    public: 
        Grid(Tetrominos *tetrominos, int screen_height);    
};
 
#endif // _GRID_