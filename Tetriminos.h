#ifndef _TETROMINOS_
#define _TETROMINOS_

class Tetrominos {
    public:
        int get_tile_type(int shape, int rotation, int x, int y);
        int get_init_x_pos(int shape, int rotation);
        int get_init_y_pos(int shape, int rotation);
};
 
#endif // _TETROMINOS_