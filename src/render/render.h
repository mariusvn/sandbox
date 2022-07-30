
#ifndef SANDBOX_RENDER_H
#define SANDBOX_RENDER_H

#include <allegro5/allegro5.h>
#include "../data/pixels_data.h"
#include "../macro/macro.h"

struct sb_renderer {
    ALLEGRO_COLOR* colors;
    ALLEGRO_BITMAP** colors_bitmaps;
    ALLEGRO_DISPLAY* display;
    unsigned short width;
    unsigned short height;
    unsigned short pixel_size;
};

typedef struct sb_renderer sb_renderer;

sb_renderer* sb_renderer_create(unsigned short width, unsigned short height, unsigned short pixel_size, ALLEGRO_DISPLAY* display);
void sb_renderer_destroy(sb_renderer* renderer);
void sb_renderer_put_pixel(sb_renderer* renderer, unsigned short x, unsigned short y, sb_pixel_id pixel_id);
unsigned short sb_renderer_get_color_count();

#endif //SANDBOX_RENDER_H
