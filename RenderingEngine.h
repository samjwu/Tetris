#ifndef _RENDERINGENGINE_
#define _RENDERINGENGINE_
  
#include "SDL/include/SDL.h"                            
#include "SDL/SDL_GfxPrimitives/SDL_gfxPrimitives.h"

enum class Color {BLACK, WHITE, BLUE, RED};

class RenderingEngine {
    public:
        RenderingEngine();
        void clear_screen();
        void update_screen();
        void render_tile(int x1, int y1, int x2, int y2, Color tile_color);
        int render_grid();
        int get_screen_height();
        int poll_key_input();
        int get_key_input();
        int get_key_state(int key);
};
 
#endif // _RENDERINGENGINE_