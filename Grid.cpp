#include "Grid.h"

void Grid::init_grid() {
    for (int i=0; i<GRID_WIDTH; i++) {
        for (int j=0; j<GRID_HEIGHT; j++) {
            grid[i][j] = EMPTY;
        }
    }
}