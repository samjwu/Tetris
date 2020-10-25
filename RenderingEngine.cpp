#include "RenderingEngine.h"

static SDL_Surface *screen;
static Uint32 colors[4] = {
    0x000000ff, // black
    0xffffffff, // white
    0x0000ffff, // blue
    0xff0000ff // red
};

/*
 * Constructor. Initializes grid.
 */
RenderingEngine::RenderingEngine() {
	render_grid();
}

/*
 * Render the grid
 */
void RenderingEngine::render_grid() {
	
}

/*
 * Clear screen by setting all pixels to black
 */
void RenderingEngine::clear_screen() {
	boxColor(screen, 0, 0, screen->w - 1, screen->h - 1, colors[(int) Color::BLACK]);
}

/* 
* Update screen
*/
void RenderingEngine::update_screen() {
	SDL_Flip(screen);
}

/* 
* Render a tile with a given color
*/
void render_tile(int x1, int y1, int x2, int y2, Color tile_color) {
    boxColor(screen, x1, y1, x2, y2 - 1, colors[(int) tile_color]);
}