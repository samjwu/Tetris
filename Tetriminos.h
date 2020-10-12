#ifndef _TETROMINOS_
#define _TETROMINOS_

class Tetrominos {
    public:
        int get_tetromino_type (int tetromino, int rotation, int x, int y);
        int get_init_x_pos (int tetromino, int rotation);
        int get_init_y_pos (int tetromino, int rotation);
};
 
#endif // _TETROMINOS_