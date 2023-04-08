#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP 16

#define DEFAULT 0
#define XBOX 1
#define PLAYSTATION 2

void drawOption(SDL_Surface* screen, const char* text, TTF_Font* font, SDL_Rect rect, int selected)
{
    SDL_Color yellow = { 255, 255, 0 };
    SDL_Color white = { 255, 255, 255 };
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, selected ? yellow : white);

    if (textSurface == NULL) {
        printf("Failed to render text: %s\n", TTF_GetError());
        return;
    }

    SDL_BlitSurface(textSurface, NULL, screen, &rect);

    SDL_FreeSurface(textSurface);
}


int main(int argc, char* argv[])
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        printf("SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    // Initialize SDL_ttf
    if (TTF_Init() == -1)
    {
        printf("SDL_ttf initialization failed: %s\n", TTF_GetError());
        return 1;
    }

    // Set up the screen
    SDL_Surface* screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    if (screen == NULL)
    {
        printf("Video mode initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    // Load font
    TTF_Font* font = TTF_OpenFont("arial.ttf", 24);
    if (font == NULL)
    {
        printf("Failed to load font: %s\n", TTF_GetError());
        return 1;
    }

    // Set up option rectangles
    SDL_Rect defaultRect = {80, 120, 480, 60};
    SDL_Rect xboxRect = {80, 200, 480, 60};
    SDL_Rect playstationRect = {80, 280, 480, 60};

    int quit = 0;
    int selectedOption = DEFAULT;
    SDL_Event e;  // Declare the SDL event variable


    // Main loop
    while (!quit)
    {
        // Handle events
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = 1;
            }
            else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                    case SDLK_UP:
                        // Move selection up
                        if (selectedOption > DEFAULT)
                        {
                            selectedOption--;
                        }
                        break;
                    case SDLK_DOWN:
                        // Move selection down
                        if (selectedOption < PLAYSTATION)
                        {
                            selectedOption++;
                        }
                        break;
                    case SDLK_RETURN:
                    case SDLK_SPACE:
                    default:
                        // Perform the appropriate action and quit the program
                        

                        switch (selectedOption)
                        {

                            case XBOX:
                                break;
                            case PLAYSTATION:
                                break;
                            default:
                                // The default option does not require any action, so just quit the program
                                quit = 1;
                                
                        }

                        // Move the selected unlock sound file from /mnt/SDCARD/unlock to /mnt/SDCARD/RetroArch/.retroarch/assets
                        if (selectedOption == 2) {
                        // Move the selected unlock sound file from /mnt/SDCARD/unlock to /mnt/SDCARD/RetroArch/.retroarch/assets
                        if (rename("/mnt/SDCARD/unlock/xboxunlock.ogg", "/mnt/SDCARD/RetroArch/.retroarch/assets/unlock.ogg") != 0) {
                            printf("Error: Failed to move Xbox unlock sound file.\n");
                        } else {
                            printf("Xbox unlock sound file moved successfully.\n");
                        }
                    } else if (selectedOption == 3) {
                        // Move the selected unlock sound file from /mnt/SDCARD/unlock to /mnt/SDCARD/RetroArch/.retroarch/assets
                        if (rename("/mnt/SDCARD/unlock/psunlock.ogg", "/mnt/SDCARD/RetroArch/.retroarch/assets/unlock.ogg") != 0) {
                            printf("Error: Failed to move PlayStation unlock sound file.\n");
                        } else {
                            printf("PlayStation unlock sound file moved successfully.\n");
                        }
}

                        // Quit the program
                        quit = 1;
                        break;
                }
            }
        }

        // Clear the screen
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

        // Draw the options
        drawOption(screen, "Default Achievement Unlock Sound", font, defaultRect, selectedOption == DEFAULT);
        drawOption(screen, "Xbox Achievement Unlock Sound", font, xboxRect, selectedOption == XBOX);
        drawOption(screen, "Playstation Trophy Unlock Sound", font, playstationRect, selectedOption == PLAYSTATION);

        // Update the screen
        SDL_Flip(screen);
    }

    // Clean up
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
