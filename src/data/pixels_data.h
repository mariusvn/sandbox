
#ifndef SANDBOX_PIXELS_DATA_H
#define SANDBOX_PIXELS_DATA_H

struct sb_pixel_data {
    const char* name;
    unsigned char color[3];
};
typedef struct sb_pixel_data sb_pixel_data;
typedef unsigned short sb_pixel_id;

static unsigned short SB_PIXEL_COUNT = 1;
static sb_pixel_data SB_PIXEL_DATA[2] = {
    {"sand", {206, 205, 57}},
    {NULL, {0, 0, 0}},
};

#define SB_PIXEL_SAND 0

#endif //SANDBOX_PIXELS_DATA_H
