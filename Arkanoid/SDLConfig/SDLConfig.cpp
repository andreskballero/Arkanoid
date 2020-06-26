//
//  SDLConfig.cpp
//  Arkanoid
//
//  Created by Andrés Caballero Toledo on 25/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "SDLConfig.h"

bool init() {
    // Initialization flag
    bool success = true;
    
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    } else {
        // Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            printf("Warning: Linear texture filtering not enabled!\n");
        }
        
        // Create window
        gWindow = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        } else {
            // create vsynced renderer for the window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == NULL) {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            } else {
                // Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                
                // Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
                
                // Initialize SDL_ttf
                if (TTF_Init() == -1) {
                    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
                    success = false;
                }
            }
        }
    }
    return success;
}


bool loadMedia() {
    // Loading success flag
    bool success = true;
    
    gFont = TTF_OpenFont("../Assets/lazy.ttf", 11);
    if (gFont == NULL) {
        printf("Failed to load lazy Font! SDL_ttf Error: %s\n", TTF_GetError());
        success = false;
    }
    
    return success;
}


bool loadTextures(Ball *ball) {
    bool success = true;
    
    // Ball texture
    if(!ball->ball.loadFromFile("../Assets/Ball.png")) {
        printf("Could not load the ball texture.\n");
        success = false;
    }
    
    // Block textures
    if(!blocks[BLUE].loadFromFile("../Assets/BlueBlock.png")) {
        printf("Could not load the blue block texture.\n");
        success = false;
    }
    if(!blocks[BLUE_2].loadFromFile("../Assets/Blue2Block.png")) {
        printf("Could not load the blue_2 block texture.\n");
        success = false;
    }
    if(!blocks[GREEN].loadFromFile("../Assets/GreenBlock.png")) {
        printf("Could not load the green block texture.\n");
        success = false;
    }
    if(!blocks[ORANGE].loadFromFile("../Assets/OrangeBlock.png")) {
        printf("Could not load the orange block texture.\n");
        success = false;
    }
    if(!blocks[PINK].loadFromFile("../Assets/PinkBlock.png")) {
        printf("Could not load the pink block texture.\n");
        success = false;
    }
    if(!blocks[PINK_2].loadFromFile("../Assets/Pink2Block.png")) {
        printf("Could not load the pink_2 block texture.\n");
        success = false;
    }
    if(!blocks[RED].loadFromFile("../Assets/RedBlock.png")) {
        printf("Could not load the red block texture.\n");
        success = false;
    }
    if(!blocks[YELLOW].loadFromFile("../Assets/YellowBlock.png")) {
        printf("Could not load the yellow block texture.\n");
        success = false;
    }
    
    // Bar textures
    if (!bars[LITTLE].loadFromFile("../Assets/LittleBar.png")) {
        printf("Could not load the little bar texture.\n");
        success = false;
    }
    if (!bars[MIDDLE].loadFromFile("../Assets/MiddleBar.png")) {
        printf("Could not load the middle bar texture.\n");
        success = false;
    }
    if (!bars[LARGE].loadFromFile("../Assets/LargeBar.png")) {
        printf("Could not load the large bar texture.\n");
        success = false;
    }
    
    return success;
}


void close() {
    // Free global font
    TTF_CloseFont(gFont);
    gFont = NULL;
    
    // Destroy renderer and window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gRenderer = NULL;
    gWindow = NULL;
    
    // Quit SDL subsystems
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
