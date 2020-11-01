#ifndef _APPCONSTANTS_
#define _APPCONSTANTS_

#include "SDL/include/SDL.h"

const SDL_MessageBoxButtonData Buttons[] = {
    /* .flags, .buttonid, .text */ 
    { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 0, "Yes" },
    { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 1, "No" },
};

const SDL_MessageBoxColorScheme ColorScheme = {
    { /* .colors (.r, .g, .b) */
        /* [SDL_MESSAGEBOX_COLOR_BACKGROUND] */
        { 255,   0,   0 },
        /* [SDL_MESSAGEBOX_COLOR_TEXT] */
        {   0, 255,   0 },
        /* [SDL_MESSAGEBOX_COLOR_BUTTON_BORDER] */
        { 255, 255,   0 },
        /* [SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND] */
        {   0,   0, 255 },
        /* [SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED] */
        { 255,   0, 255 }
    }
};

const SDL_MessageBoxData MessageBoxData = {
    SDL_MESSAGEBOX_INFORMATION, /* .flags */
    NULL, /* .window */
    "Restart or Exit Game", /* .title */
    "Restart the game?", /* .message */
    SDL_arraysize(Buttons), /* .numbuttons */
    Buttons, /* .buttons */
    &ColorScheme /* .colorScheme */
};

#endif // _APPCONSTANTS_