//
//  Block.h
//  Arkanoid
//
//  Created by Andrés Caballero Toledo on 25/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef BLOCK_H
#define BLOCK_H

#define NUM_BLOCKS_Y 8
#define NUM_BLOCKS_X 9
#define MARGIN 4

#include "Texture.h"
#include "Ball.h"

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

// Loaded textures of the blocks
extern Texture blocks[TOTAL_BLOCKS];

// Array of ints containing the actual blocks
extern int board[NUM_BLOCKS_Y][NUM_BLOCKS_X];

// Initialize the board
void initializeBoard();

// Load the board with the corresponding blocks
void loadBoard();

// Function to draw the block of blocks
void drawBlocks();

// Hit block checker
void hitBlock(Ball *ball);

// Condition to win
bool win();

#endif
