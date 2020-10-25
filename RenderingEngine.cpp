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
 * Render the grid
 * Return:
 *      0 if successful
 *      1 if SDL failed to initialize
 *      2 if video mode could not be set
 */
int RenderingEngine::render_grid() {
	const SDL_VideoInfo *video_info;
	Uint8  video_bits_per_pixel;
	Uint32 video_flags;
        
	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Error during SDL initialization: %s\n", SDL_GetError());
		return 1;
	}
	atexit(SDL_Quit);

    // set video bits per pixel above 8-bit color for better alpha blending
	video_info = SDL_GetVideoInfo();
	if (video_info->vfmt->BitsPerPixel > 8) {
		video_bits_per_pixel = video_info->vfmt->BitsPerPixel;
	} else {
		video_bits_per_pixel = 16;
	}
	video_flags = SDL_SWSURFACE | SDL_DOUBLEBUF;
	
	// set video mode to 640x480
	if ((screen = SDL_SetVideoMode(640, 480, video_bits_per_pixel, video_flags)) == NULL) {
		fprintf(stderr, "Couldn't set video mode to %ix%i: %s\n", 640, 480, SDL_GetError());
		return 2;
	}
    return 0;
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
