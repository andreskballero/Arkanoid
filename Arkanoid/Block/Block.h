//
//  Block.h
//  Arkanoid
//
//  Created by Andrés Caballero Toledo on 25/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef BLOCK_H
#define BLOCK_H

#include "Texture.h"

#include "SDL2/SDL.h"

// Color block id
enum ColorBlocks {
    BLUE_2,
    BLUE,
    GREEN,
    ORANGE,
    PINK,
    PINK_2,
    RED,
    YELLOW,
    TOTAL_BLOCKS
};

extern Texture blocks[TOTAL_BLOCKS];

#endif
