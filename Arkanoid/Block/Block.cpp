//
//  Block.cpp
//  Arkanoid
//
//  Created by Andrés Caballero Toledo on 25/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "Block.h"

Texture blocks[TOTAL_BLOCKS];

int board[NUM_BLOCKS_Y][NUM_BLOCKS_X];


void initializeBoard() {
    for (int y = 0; y < NUM_BLOCKS_Y; ++y) {
        for (int x = 0; x < NUM_BLOCKS_X; ++x) {
            board[y][x] = 0;
        }
    }
}


void loadBoard() {
    for (int y = NUM_BLOCKS_Y - 1; y >= 0; --y) {
        for (int x = 0; x < NUM_BLOCKS_X; ++x) {
            board[y][x] = y;
            //printf("%d ", board[y][x]);
        }
        //printf("\n\n");
    }
}


void drawBlocks() {
    for (int y = 0; y < NUM_BLOCKS_Y; ++y) {
        for (int x = 0; x < NUM_BLOCKS_X; ++x) {
            if (board[y][x] != -1) {
                int block = board[y][x];
                blocks[block].render((x + 1) * blocks[block].getWidth(), (y + 1) * blocks[block].getHeight());
            }
        }
    }
}


void hitBlock(Ball *ball) {
    // Velocity inverted flags
    int inverted_x = false;
    int inverted_y = false;
    // Run the board of blocks
    for (int y = 0; y < NUM_BLOCKS_Y; ++y) {
        for (int x = 0; x < NUM_BLOCKS_X; ++x) {
            // Clarification variables
            int ball_x = ball->pos_x;
            int ball_y = ball->pos_y;
            int block_x = blocks[y].getWidth() * (x + 1) - MARGIN;
            int block_y = blocks[y].getHeight() * (y + 1) - MARGIN;
            int block_x2 = blocks[y].getWidth() * (x + 2) + MARGIN;
            int block_y2 = blocks[y].getHeight() * (y + 2) + MARGIN;
            
            // If the ball has hit the block and it was different than -1;
            // -1 meaning there is no block at all from the integer array
            if (ball_y >= block_y &&
                ball_x >= block_x &&
                ball_y <= block_y2 &&
                ball_x <= block_x2 &&
                board[y][x] != -1) {
                
                // If the ball has hit one block on the sides
                if ((ball->last_x < block_x || ball->last_x > block_x2) &&
                    !inverted_x) {
                    ball->vel_x = -ball->vel_x;
                    inverted_x = true;
                }
                // If the ball has hit one block on top or bottom
                if ((ball->last_y < block_y || ball->last_y > block_y2) &&
                    !inverted_y) {
                    ball->vel_y = -ball->vel_y;
                    inverted_y = true;
                }
                
                --board[y][x];
            }
        }
    }
}
