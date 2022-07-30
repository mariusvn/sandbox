
#ifndef SANDBOX_MOUSE_H
#define SANDBOX_MOUSE_H

#include <allegro5/allegro5.h>
#include "../data/globals.h"
#include "../data/pixels_data.h"
#include "../render/render.h"
#include "../element/element.h"

extern bool sb_mouse_is_left_mouse_button_down;
extern bool sb_mouse_is_right_mouse_button_down;

void sb_mouse_on_click(ALLEGRO_EVENT* event);
void sb_mouse_on_release(ALLEGRO_EVENT* event);
void sb_mouse_on_frame();

#endif //SANDBOX_MOUSE_H
