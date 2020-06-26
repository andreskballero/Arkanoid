//
//  Ball.cpp
//  Arkanoid
//
//  Created by Andrés Caballero Toledo on 25/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "Ball.h"


Ball::Ball() {
    srand(time(NULL));
    pos_x = SCREEN_WIDTH / 2 - ball.getWidth() / 2;
    pos_y = SCREEN_HEIGHT / 2  - ball.getHeight() / 2;
    vel_x = 0;
    vel_y = 5;
}


void Ball::drawBall() {
    ball.render(pos_x, pos_y);
}


void Ball::bounce(Bar *bar) {
    pos_x += vel_x;
    pos_y += vel_y;
    
    // If the ball hits the horizontal boundaries
    if (pos_x <= 0 || pos_x + ball.getWidth() >= SCREEN_WIDTH) {
        vel_x = vel_x * -1;
    }
    
    // If the ball hits the vertical boundaries
    if (pos_y <= 0 || pos_y + ball.getHeight() >= SCREEN_HEIGHT) {
        vel_y = vel_y * -1;
    }
    
    // If the ball hits the bar vertically
    if ((pos_y + ball.getHeight() >= bar->pos_y) &&
        (pos_x + ball.getWidth() >= bar->pos_x) &&
        (pos_x <= bar->pos_x + bar->currentBar->getWidth())) {
        // If the ball hits the mid-right segment of the bar
        if (pos_x + ball.getWidth() / 2 > bar->pos_x + bar->currentBar->getWidth() / 2) {
            vel_x = 5;
        // If the ball hits the mid-left segment of the bar
        } else if (pos_x + ball.getWidth() / 2 < bar->pos_x + bar->currentBar->getWidth() / 2) {
            vel_x = -5;
        }
        vel_y = vel_y * -1;
    }
    
    // If the bar hits on the sides
    if (((pos_y > bar->pos_y) &&
         (pos_y < bar->pos_y + bar->currentBar->getHeight()) &&
         (pos_x == bar->pos_x + bar->currentBar->getWidth()))
        ||
        ((pos_y > bar->pos_y) &&
         (pos_y < bar->pos_y + bar->currentBar->getHeight()) &&
         (pos_x == bar->pos_x))) {
        vel_y = vel_y * -1;
    }
}
