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
* Point (x1, y1) is the top left of the tile (in pixels)
* Point (x2, y2) is the bottom right of the tile (in pixels)
*/
void RenderingEngine::render_tile(int x1, int y1, int x2, int y2, Color tile_color) {
    boxColor(screen, x1, y1, x2, y2 - 1, colors[(int) tile_color]);
}

/* 
* Return height of screen in pixels
*/
int RenderingEngine::get_screen_height() {
    return screen->h;
}

/* 
* Poll for input from keyboard
* Return input if valid key, exit if input is ESC, else return -1 for error
*/
int RenderingEngine::poll_key_input() {
    SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_KEYDOWN:
				return event.key.keysym.sym;
			case SDL_QUIT: // ESC key
				exit(3);
		}
	}
	return -1;
}

/* 
* Return input from keyboard
*/
int RenderingEngine::get_key_input() {
    SDL_Event event;
	while (true) {
	  SDL_WaitEvent(&event);
	  if (event.type == SDL_KEYDOWN)
		  break;
      if (event.type == SDL_QUIT) // ESC key
		  exit(3);
	};
	return event.key.keysym.sym;
}

/* 
* Put all key states into hash table with events as keys
* Then return state of pressed key
*/
int RenderingEngine::get_key_state(int key_pressed) {
    Uint8* key_states;
	int num_keys;
	SDL_PumpEvents();
	key_states = SDL_GetKeyState(&num_keys);
	return key_states[key_pressed];
}
