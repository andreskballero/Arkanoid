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
    last_x = 0;
    pos_y = SCREEN_HEIGHT / 2  - ball.getHeight() / 2;
    last_y = 0;
    vel_x = 0;
    vel_y = 5;
}


void Ball::draw() {
    ball.render(pos_x - ball.getWidth() / 2, pos_y - ball.getHeight() / 2);
}


void Ball::move() {
    // Ball movement
    last_x = pos_x;
    last_y = pos_y;
    pos_x += vel_x;
    pos_y += vel_y;
}


void Ball::bounceScreen() {
    // Ball collision checking with the sides
    // If the velocity_x is negative, it cannot hit the right boundary,
    // therefore only the left side is checked, OR
    // If the velocity_x is positive, it cannot hit the left boundary,
    // therefore only the right side is checked
    if ((vel_x < 0 && pos_x - ball.getWidth() / 2 <= 0) || (vel_x > 0 && pos_x + ball.getWidth() / 2 >= SCREEN_WIDTH)) {
        vel_x = vel_x * -1;
    }
    
    // Ball collision checking with top and bottom
    // If the velocity_y is negative, it cannot hit the bottom boundary,
    // therefore only the top is checked, OR
    // If the velocity_y is positive, it cannot hit the top boundary,
    // therefore only the bottom is checked
    if (vel_y < 0 && pos_y - ball.getHeight() / 2 <= 0) {
        vel_y = vel_y * -1;
    }
}


void Ball::reset() {
    pos_x = SCREEN_WIDTH / 2 - ball.getWidth() / 2;
    last_x = 0;
    pos_y = SCREEN_HEIGHT / 2  - ball.getHeight() / 2;
    last_y = 0;
    vel_x = 0;
    vel_y = 5;
}


bool Ball::lose() {
    if (pos_y - ball.getHeight() / 2 >= SCREEN_HEIGHT) {
        return true;
    }
    return false;
}
