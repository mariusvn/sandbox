
#ifndef SANDBOX_PIXELS_DATA_H
#define SANDBOX_PIXELS_DATA_H

typedef unsigned short sb_pixel_id;

struct sb_pixel_data {
    const char* name;
    unsigned char color[3];
    sb_pixel_id id;
};
typedef struct sb_pixel_data sb_pixel_data;

static unsigned short SB_PIXEL_COUNT = 1;
static sb_pixel_data SB_PIXEL_DATA[2] = {
    {"sand", {206, 205, 57}, 0},
    {NULL, {0, 0, 0}, 1},
};

#define SB_PIXEL_SAND 0

#endif //SANDBOX_PIXELS_DATA_H
