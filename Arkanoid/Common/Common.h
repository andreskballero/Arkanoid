//
//  Common.h
//  Arkanoid
//
//  Created by Andrés Caballero Toledo on 25/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef COMMON_H
#define COMMON_H

#define HALF_SECOND 500

#include "SDL2/SDL.h"
#include "SDL2_ttf/SDL_ttf.h"

// Screen dimension constants
extern const float ASPECT_RATIO;
extern const int SCREEN_HEIGHT;
extern const float SCREEN_WIDTH;

// The window we will be rendering to
extern SDL_Window *gWindow;

// The window renderer
extern SDL_Renderer *gRenderer;

// Globally used font
extern TTF_Font *gFont;

#endif

