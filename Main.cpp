#include "AppConstants.h"
#include "Logic.h"
#include "RestartAPI/RestartAPI.h"

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
    // check for previous restart
    if (RA_CheckForRestartProcessStart()) {
        RA_WaitForPreviousProcessFinish();
    }

    // init game objects
    RenderingEngine rendering_engine;
    int screen_height = rendering_engine.get_screen_height();
    Tetrominos tetrominos;
    Grid grid(&tetrominos, screen_height);
    Logic game_logic(&grid, &tetrominos, &rendering_engine, screen_height);

    // ticks time in milliseconds
    unsigned long ticks_time = SDL_GetTicks();

    while (rendering_engine.get_key_state(SDLK_ESCAPE) == 0) {
        // init game screen and starting game logic objects
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
            case SDLK_SPACE:
                while (grid.tetromino_can_move(game_logic.current_tetromino_x_pos, game_logic.current_tetromino_y_pos + 1, game_logic.current_tetromino_shape, game_logic.current_tetromino_rotation)) {
                    game_logic.current_tetromino_y_pos++;
                }
                grid.place_tetromino(game_logic.current_tetromino_x_pos, game_logic.current_tetromino_y_pos, game_logic.current_tetromino_shape, game_logic.current_tetromino_rotation);

                grid.clear_full_lines();

                if (grid.game_over()) {
                    int buttonId;
                    if (SDL_ShowMessageBox(&MessageBoxData, &buttonId) < 0) {
                        SDL_Log("Error displaying message box");
                        return 1;
                    }
                    if (buttonId == -1) {
                        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Selection Error", "Nothing was selected.", NULL);
                    } else if (buttonId == 0) {
                        // create new active instance of application
                        if (!RA_ActivateRestartProcess()) {
                            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Restart Failed", "Error occurred during restart. Exiting application.", NULL);
                        }
                    } else { // buttonId == 1
                        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Game Over", "Ending game.", NULL);
                        
                    }
                    RA_DoRestartProcessFinish(); // release mutex
                    exit(0); // close current instance
                }
        }
    }

    RA_DoRestartProcessFinish(); // release mutex
    return 0;
}