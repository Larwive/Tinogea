#include <stdlib.h>
#include "obj.h"
#include "../../src/engine/display.h"

SpriteData *obj1_SpriteData() {
    static SpriteData obj1_SpriteData = {
        .sprite_width = 10,
        .sprite_height = 10,
        .max_state = 2,
        .max_frames = NULL
    };
    if (obj1_SpriteData.max_frames != NULL)
        return &obj1_SpriteData;
    obj1_SpriteData.max_frames = malloc(obj1_SpriteData.max_state*sizeof(unsigned int));
    obj1_SpriteData.max_frames[0] = 4;
    obj1_SpriteData.max_frames[1] = 2;
    return &obj1_SpriteData;
}


Instance *obj1_create(int x, int y) {
    Instance *obj1 = malloc(sizeof(Instance));
    obj1->frame = 0;
    obj1->state = 0;
    obj1->scale = 1;
    obj1->sprite_data = obj1_SpriteData();
    obj1->x = x;
    obj1->y= y;

    return obj1;
}

