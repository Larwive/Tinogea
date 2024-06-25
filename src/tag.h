#ifndef TAG_H
#define TAG_H

typedef struct {
    char *name;
} tag;

char check_tag(void *obj, tag *tags);

#endif