
#include "render.h"

sb_renderer* sb_renderer_create(unsigned short width, unsigned short height, unsigned short pixel_size, ALLEGRO_DISPLAY* display) {
    sb_renderer* res = al_malloc(sizeof(sb_renderer));
    sbasserts(res != NULL, "MallocFailed");
    res->height = height;
    res->width = width;
    res->pixel_size = pixel_size;
    res->display = display;
    res->colors = al_malloc(sizeof(ALLEGRO_COLOR) * (SB_PIXEL_COUNT));
    sbasserts(res->colors != NULL, "MallocFailed");
    res->colors_bitmaps = al_malloc(sizeof(ALLEGRO_BITMAP*) * (SB_PIXEL_COUNT));
    sbasserts(res->colors_bitmaps != NULL, "MallocFailed");
    for (unsigned short i = 0; i < SB_PIXEL_COUNT; i++) {
        res->colors[i] = al_map_rgb(SB_PIXEL_DATA[i].color[0], SB_PIXEL_DATA[i].color[1], SB_PIXEL_DATA[i].color[2]);
        res->colors_bitmaps[i] = al_create_bitmap(pixel_size, pixel_size);
        al_set_target_bitmap(res->colors_bitmaps[i]);
        for (unsigned short x = 0; x < pixel_size; x++) {
            for (unsigned short y = 0; y < pixel_size; y++) {
                al_put_pixel(x, y, res->colors[i]);
            }
        }
    }
    al_set_target_bitmap(al_get_backbuffer(res->display));
    return res;
}

void sb_renderer_destroy(sb_renderer* renderer) {
    for (unsigned short i = 0; i < SB_PIXEL_COUNT; i++) {
        al_destroy_bitmap(renderer->colors_bitmaps[i]);
    }
    al_free(renderer->colors_bitmaps);
    al_free(renderer->colors);
    al_free(renderer);
}

void sb_renderer_put_pixel(sb_renderer* renderer, unsigned short x, unsigned short y, sb_pixel_id pixel_id) {
    al_set_target_bitmap(al_get_backbuffer(renderer->display));
    al_draw_bitmap(renderer->colors_bitmaps[pixel_id], renderer->pixel_size * x, renderer->pixel_size * y, 0);
}

unsigned short sb_renderer_get_color_count() {
    return SB_PIXEL_COUNT;
}

unsigned short sb_renderer_get_pixel_size(sb_renderer* renderer) {
    return renderer->pixel_size;
}
