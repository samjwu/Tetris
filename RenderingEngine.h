#ifndef _RENDERINGENGINE_
#define _RENDERINGENGINE_
  
#include "SDL/include/SDL.h"
#include <unordered_map>
#include <vector>

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
    
    private:
        std::unordered_map<int, std::vector<int>> ColorRgb = {
                                                    {(int) Color::BLACK, {0, 0, 0}},
                                                    {(int) Color::WHITE, {255, 255, 255}},
                                                    {(int) Color::BLUE, {0, 0, 255}},
                                                    {(int) Color::RED, {255, 0, 0}},
                                                };
        int screen_height;    
};
 
#endif // _RENDERINGENGINE_