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
    pos_x = SCREEN_WIDTH / 2;
    pos_y = SCREEN_HEIGHT / 2;
    vel_x = 7;
    vel_y = 5;
}


void Ball::drawBall() {
    ball.render(pos_x, pos_y);
}


void Ball::bounce() {
    pos_x += vel_x;
    pos_y += vel_y;
    
    if (pos_x < 0 || pos_x + ball.getWidth() >= SCREEN_WIDTH) {
        vel_x = vel_x * -1;
    }
    
    if (pos_y < 0 || pos_y + ball.getHeight() >= SCREEN_HEIGHT) {
        vel_y = vel_y * -1;
    }
}
