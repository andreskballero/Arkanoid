//
//  Ball.cpp
//  Arkanoid
//
//  Created by Andrés Caballero Toledo on 25/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "Ball.h"


Ball::Ball() {
    pos_x = SCREEN_WIDTH / 2;
    pos_y = SCREEN_HEIGHT / 2;
    vel_x = 10;
    vel_y = 10;
}


void Ball::drawBall() {
    ball.render(pos_x, pos_y);
}


void Ball::bounce() {
    
}
