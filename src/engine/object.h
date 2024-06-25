#ifndef OBJECT_H
#define OBJECT_H

#include "display.h"
typedef struct {
    // int id; // Useful ?
    int x;
    int y;
    int scale;
    unsigned int frame;
    unsigned int state;
    SpriteData *sprite_data;
} Instance;

#endif