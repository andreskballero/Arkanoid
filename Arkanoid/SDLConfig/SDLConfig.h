//
//  SDLConfig.h
//  Arkanoid
//
//  Created by Andrés Caballero Toledo on 25/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef SDLCONFIG_H
#define SDLCONFIG_H

#include "Ball.h"
#include "Block.h"
#include "Bar.h"
#include "Common.h"

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"

// Starts SDL and creates window
bool init();

// Loads media
bool loadMedia();

// Loads the textures
bool loadTextures(Ball *ball);

// Frees resources and quits SDL
void close();

#endif
