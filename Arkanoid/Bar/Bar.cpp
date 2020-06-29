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

void Bar::draw() {
    currentBar->render(pos_x, pos_y);
}

void Bar::move() {
    pos_x += vel;
    
    if (pos_x <= 0) {
        pos_x = 0;
    } else if (pos_x + currentBar->getWidth() >= SCREEN_WIDTH) {
        pos_x = SCREEN_WIDTH - currentBar->getWidth();
    }
}


void Bar::bounceBar(Ball *ball) {
    // Ball collision with the bar (top, bottom and sides)
    // The collision is only checked when the velocity_y is positive,
    // because it is the only scenario in which the ball can hit the
    // top or the sides of the bar
    if (ball->vel_y > 0 &&
        ball->pos_y + ball->ball.getHeight() / 2 >= pos_y &&
        ball->pos_y - ball->ball.getHeight() / 2 <= pos_y + currentBar->getHeight() &&
        ball->pos_x - ball->ball.getWidth() / 2 <= pos_x + currentBar->getWidth() &&
        ball->pos_x + ball->ball.getWidth() / 2 >= pos_x) {
        // Correct the y position to prevent possible bugs; it makes the
        // movement rough, this part needs to be improved
        ball->pos_y = pos_y - ball->ball.getHeight() / 2;
        // Depending on where the ball has hit, based on a percentage of the bar,
        // it will respond in one way or another
        if (ball->pos_x - pos_x >= currentBar->getWidth() * 0.95f) {
            ball->vel_x = 10;
            ball->vel_y = -5;
        } else if (ball->pos_x - pos_x >= currentBar->getWidth() * 0.7f) {
            ball->vel_x = 7;
            ball->vel_y = -7;
        } else if (ball->pos_x - pos_x >= currentBar->getWidth() * 0.5f) {
            ball->vel_x = 2;
            ball->vel_y = -9;
        } else if (ball->pos_x - pos_x <= currentBar->getWidth() * 0.05f) {
            ball->vel_x = -10;
            ball->vel_y = -5;
        } else if (ball->pos_x - pos_x <= currentBar->getWidth() * 0.3f) {
            ball->vel_x = -7;
            ball->vel_y = -7;
        } else {
            ball->vel_x = -2;
            ball->vel_y = -9;
        }
    }
}
