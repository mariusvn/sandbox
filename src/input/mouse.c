
#include <stdio.h>
#include "mouse.h"

bool sb_mouse_is_left_mouse_button_down = false;
bool sb_mouse_is_right_mouse_button_down = false;

void sb_mouse_on_click(ALLEGRO_EVENT* event) {
    if (event->mouse.button == 1) {
        sb_mouse_is_left_mouse_button_down = true;
    } else if (event->mouse.button == 2) {
        sb_mouse_is_right_mouse_button_down = true;
    }
}

void sb_mouse_on_release(ALLEGRO_EVENT* event) {
    if (event->mouse.button == 1) {
        sb_mouse_is_left_mouse_button_down = false;
    } else if (event->mouse.button == 2) {
        sb_mouse_is_right_mouse_button_down = false;
    }
}

void sb_mouse_on_frame() {
    if (sb_mouse_is_left_mouse_button_down) {
        ALLEGRO_MOUSE_STATE state;
        al_get_mouse_state(&state);
        unsigned short pixel_size = sb_renderer_get_pixel_size(renderer);
        sb_element_instance* instance = sb_element_instance_create(
            SB_PIXEL_SAND,
            state.x / pixel_size,
            state.y / pixel_size
        );
        sb_element_registry_add(registry, instance);
    }
}
