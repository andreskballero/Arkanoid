//
//  main.cpp
//  Arkanoid
//
//  Created by Andrés Caballero Toledo on 25/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "SDLConfig.h"
#include "Controls.h"
#include "Texture.h"
#include "Timer.h"
#include "Ball.h"
#include "Bar.h"
#include "Common.h"

#include "SDL2/SDL.h"

#include <cstdlib>
#include <string>
#include <sstream>

int main(int argc, const char *argv[]) {
    // Start SDL and initialize window
    if (!init()) {
        printf("Failed to initialize!\n");
    } else {
        // Load media
        if (!loadMedia()) {
            printf("Failed to load media!\n");
        } else {
            // Game ball
            Ball ball;
            
            // Game bar
            Bar bar;
            
            // Load textures
            if(!loadTextures(&ball)) {
                printf("Failed to load textures!\n");
            } else {
                // Game loop flag
                bool quit = false;
                
                // Event handler
                SDL_Event e;
                
                // Application timer
                Timer gameTimer;
                
                // Start counting FPS
                int countedFrames = 0;
                gameTimer.start();
                
                // Timer texture
                Texture FPSTexture;
                
                // In memory text stream
                std::stringstream timeText;
                
                //Set text color as black
                SDL_Color textColor = {0, 0, 0, 255};
                
                // Initialize and draw the board
                initializeBoard();
                loadBoard();
                
                // Game loop
                while (!quit) {
                    // ======= MOVE ======= //
                    // Handle the input
                    move(&e, &quit, &bar);
                    
                    // Move the bar
                    bar.move();
                    
                    // Calculate and correct FPS
                    float avgFPS = countedFrames / (gameTimer.getTicks() / 1000.f);
                    if (avgFPS > 2000000) {
                        avgFPS = 0;
                    }
                    if (countedFrames > 1000000) { // secure avoiding overflow
                        countedFrames = 0;
                    }
                    
                    // Set text to be rendered
                    timeText.str("");
                    timeText << "FPS: " << avgFPS;
                    
                    // Render Text
                    if (!FPSTexture.loadFromRenderedText(timeText.str().c_str(), textColor)) {
                        printf("Unable to render FPS texture!\n");
                    }
                    
                    // ======= GAME LOGIC ======= //
                    // Ball movement
                    ball.move();
                    // Check if the ball has hit a block
                    // If it hits a block, bounce accordingly
                    hitBlock(&ball);
                    // React depending on the surface the ball has hit
                    ball.bounceScreen();
                    bar.bounceBar(&ball);
                    // Reset everything when the match is won or lost
                    if (win() || ball.lose()) {
                        ball.reset();
                        loadBoard();
                    }
                    
                    // ======= GAME DRAWING ======= //
                    // Clear screen
                    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                    SDL_RenderClear(gRenderer);
                    
                    // Draw the bar
                    bar.draw();
                    // Draw the blocks
                    drawBlocks();
                    // Draw the ball
                    ball.draw();

                    // Render FPS counter
                    FPSTexture.render(0, 0);
                    
                    // Update screen
                    SDL_RenderPresent(gRenderer);
                    
                    // Update variables
                    ++countedFrames;
                }
            }
        }
    }
    
    // Free resources and close SDL
    close();
    
    return EXIT_SUCCESS;
}
