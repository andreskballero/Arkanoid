//
//  Ball.h
//  Arkanoid
//
//  Created by Andrés Caballero Toledo on 25/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef BALL_H
#define BALL_H

#include "Texture.h"
#include "Bar.h"

#include "SDL2/SDL.h"

class Ball {
public:
    Ball();
    
    void draw();
    void move();
    void bounceScreen();
    void bounceBar(Bar *bar);
        
    Texture ball;
    int pos_x;
    int pos_y;
    int vel_x;
    int vel_y;
};

#endif
