
#include <stdio.h>
#include "mouse.h"

void sb_mouse_on_click(ALLEGRO_EVENT* event) {
    printf("click %d\n", event->mouse.button);
}

void sb_mouse_on_release(ALLEGRO_EVENT* event) {
    printf("click %d\n", event->mouse.button);
}
