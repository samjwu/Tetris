#include "Logic.h"

/**
 * Call WinMain as entry point to start process for Windows application
 * @param hInstance:
 *      base address of the memory image of the executable;
 *      primarily used to load resources from the executable
 * @param hPrevInstance:
 *      always set to 0
 * @param lpCmdLine:
 *      command line arguments following the command used to start the process
 * @param nCmdShow:
 *      controls how the window is to be shown;
 *      parameter values: 
 *      https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-showwindow
 */     
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    RenderingEngine rendering_engine;
    int screen_height = rendering_engine.get_screen_height();
    Tetrominos tetrominos;
    Grid grid(&tetrominos, screen_height);
    Logic game_logic(&grid, &tetrominos, &rendering_engine, screen_height);

    // ticks time in milliseconds
    unsigned long ticks_time = SDL_GetTicks();

    while (rendering_engine.get_key_state(SDLK_ESCAPE) == 0) {
        // init game screen and starting objects
        rendering_engine.clear_screen();
        game_logic.init_game();
        rendering_engine.update_screen();

        // handle keyboard inputs
        int pressed_key = rendering_engine.poll_key_input();
        switch (pressed_key) {
            case SDLK_RIGHT:
                if (grid.tetromino_can_move(game_logic.current_tetromino_x_pos + 1, game_logic.current_tetromino_y_pos, game_logic.current_tetromino_shape, game_logic.current_tetromino_rotation)) {
                    game_logic.current_tetromino_x_pos++;
                    break;
                }
            case SDLK_DOWN:
                if (grid.tetromino_can_move(game_logic.current_tetromino_x_pos, game_logic.current_tetromino_y_pos + 1, game_logic.current_tetromino_shape, game_logic.current_tetromino_rotation)) {
                    game_logic.current_tetromino_y_pos++;
                    break;
                }
            case SDLK_LEFT:
                if (grid.tetromino_can_move(game_logic.current_tetromino_x_pos - 1, game_logic.current_tetromino_y_pos, game_logic.current_tetromino_shape, game_logic.current_tetromino_rotation)) {
                    game_logic.current_tetromino_x_pos--
                    break;
                }
        }
    }
}