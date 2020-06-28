//
//  Bar.cpp
//  Arkanoid
//
//  Created by Andrés Caballero Toledo on 25/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "Bar.h"

Texture bars[TOTAL_BARS];


Bar::Bar() {
    currentBar = &bars[MIDDLE];
    
    pos_x = SCREEN_WIDTH / 2 - currentBar->getWidth() / 2;
    pos_y = SCREEN_HEIGHT - SCREEN_HEIGHT / 10;
    vel = 0;
}

void Bar::drawBar() {
    currentBar->render(pos_x, pos_y);
}

void Bar::moveBar() {
    //vel = 10;
    pos_x += vel;
    
    if (pos_x <= 0) {
        pos_x = 0;
    } else if (pos_x + currentBar->getWidth() >= SCREEN_WIDTH) {
        pos_x = SCREEN_WIDTH - currentBar->getWidth();
    }
}
