//
//  Bar.h
//  Arkanoid
//
//  Created by Andrés Caballero Toledo on 25/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef BAR_H
#define BAR_H

#include "Texture.h"

#include "SDL2/SDL.h"

enum SizeBars {
    LITTLE,
    MIDDLE,
    LARGE,
    TOTAL_BARS
};

extern Texture bars[TOTAL_BARS];

#endif
