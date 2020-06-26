//
//  Controls.cpp
//  Arkanoid
//
//  Created by Andrés Caballero Toledo on 25/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "Controls.h"

void move(SDL_Event *e, bool *quit, Bar *bar) {
    // Handle events on queue
    while (SDL_PollEvent(e) != 0) {
        if (e->type == SDL_QUIT) {
            *quit = true;
        } else if (e->type == SDL_KEYDOWN && e->key.repeat == 0) {
            switch (e->key.keysym.sym) {
                case SDLK_RIGHT:
                    bar->vel += 10;
                    break;
                case SDLK_LEFT:
                    bar->vel -= 10;
                    break;
            }
        } else if (e->type == SDL_KEYUP && e->key.repeat == 0) {
            switch (e->key.keysym.sym) {
                case SDLK_RIGHT:
                    bar->vel -= 10;
                    break;
                case SDLK_LEFT:
                    bar->vel += 10;
                    break;
            }
        }
    }
}
