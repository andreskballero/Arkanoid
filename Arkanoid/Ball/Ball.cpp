//
//  Ball.cpp
//  Arkanoid
//
//  Created by Andrés Caballero Toledo on 25/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "Ball.h"

Ball::Ball() {
    pos_x = SCREEN_WIDTH / 2 - ball.getWidth() / 2;
    pos_y = SCREEN_HEIGHT / 2  - ball.getHeight() / 2;
    vel_x = 0;
    vel_y = 5;
}


void Ball::draw() {
    ball.render(pos_x, pos_y);
}


void Ball::move() {
    // Ball movement
    pos_x += vel_x;
    pos_y += vel_y;
}


void Ball::bounceScreen() {
    // Ball collision checking with the sides
    // If the velocity_x is negative, it cannot hit the right boundary,
    // therefore only the left side is checked, OR
    // If the velocity_x is positive, it cannot hit the left boundary,
    // therefore only the right side is checked
    if ((vel_x < 0 && pos_x <= 0) || (vel_x > 0 && pos_x + ball.getWidth() >= SCREEN_WIDTH)) {
        vel_x = vel_x * -1;
    }
    
    // Ball collision checking with top and bottom
    // If the velocity_y is negative, it cannot hit the bottom boundary,
    // therefore only the top is checked, OR
    // If the velocity_y is positive, it cannot hit the top boundary,
    // therefore only the bottom is checked
    if ((vel_y < 0 && pos_y <= 0) || (pos_y > 0 && pos_y + ball.getHeight() >= SCREEN_HEIGHT)) {
        vel_y = vel_y * -1;
    }
}


void Ball::bounceBar(Bar *bar) {
    // Ball collision with the bar (top, bottom and sides)
    // The collision is only checked when the velocity_y is positive,
    // because it is the only scenario in which the ball can hit the
    // top or the sides of the bar
    if (vel_y > 0 &&
        pos_y + ball.getHeight() >= bar->pos_y &&
        pos_y <= bar->pos_y + bar->currentBar->getHeight() &&
        pos_x <= bar->pos_x + bar->currentBar->getWidth() &&
        pos_x + ball.getWidth() >= bar->pos_x) {
        // Correct the y position to prevent possible bugs; it makes the
        // movement rough, this part needs to be improved
        pos_y = bar->pos_y - ball.getHeight();
        // Depending on where the ball has hit, based on a percentage of the bar,
        // it will respond in one way or another
        if (pos_x + ball.getWidth() / 2 - bar->pos_x >= bar->currentBar->getWidth() * 0.95f) {
            vel_x = 10;
            vel_y = -5;
        } else if (pos_x + ball.getWidth() / 2 - bar->pos_x >= bar->currentBar->getWidth() * 0.7f) {
            vel_x = 7;
            vel_y = -7;
        } else if (pos_x + ball.getWidth() / 2 - bar->pos_x >= bar->currentBar->getWidth() * 0.5f) {
            vel_x = 2;
            vel_y = -9;
        } else if (pos_x + ball.getWidth() / 2 - bar->pos_x <= bar->currentBar->getWidth() * 0.05f) {
            vel_x = -10;
            vel_y = -5;
        } else if (pos_x + ball.getWidth() / 2 - bar->pos_x <= bar->currentBar->getWidth() * 0.30f) {
            vel_x = -7;
            vel_y = -7;
        } else {
            vel_x = -2;
            vel_y = -9;
        }
    }
}
