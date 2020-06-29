//
//  Common.cpp
//  Arkanoid
//
//  Created by Andrés Caballero Toledo on 25/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "Common.h"

// Screen dimension constants
const float ASPECT_RATIO = 16.0 / 15.0;
const float SCREEN_WIDTH = HORIZONTAL_BLOCK * HORIZONTAL_WIDTH;
const int SCREEN_HEIGHT = VERTICAL_BLOCK * VERTICAL_HEIGHT; //SCREEN_WIDTH * ASPECT_RATIO;

// The window we will be rendering to
SDL_Window *gWindow = NULL;

// The window renderer
SDL_Renderer *gRenderer = NULL;

// Globally used font
TTF_Font *gFont = NULL;
