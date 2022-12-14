#include <allegro5/allegro5.h>
#include "render/render.h"
#include "input/mouse.h"
#include "macro/macro.h"
#include "event/event.h"
#include "element/element.h"
#include "data/globals.h"

ALLEGRO_TIMER* timer;
ALLEGRO_EVENT_QUEUE* queue;
ALLEGRO_DISPLAY* display;
sb_event* sevent;
sb_renderer* renderer;
sb_element_registry* registry;

void sb_init() {
    al_init();
    al_install_keyboard();
    al_install_mouse();

    timer = al_create_timer(1.0 / 144.0);
    queue = al_create_event_queue();
    display = al_create_display(1600, 900);
    sevent = sb_event_create();
    renderer = sb_renderer_create(1600, 900, 20, display);
    registry = sb_element_registry_create(renderer);

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_mouse_event_source());

    sb_event_register(sevent, ALLEGRO_EVENT_MOUSE_BUTTON_DOWN, &sb_mouse_on_click);
    sb_event_register(sevent, ALLEGRO_EVENT_MOUSE_BUTTON_UP, &sb_mouse_on_release);

    sb_element_instance* test = sb_element_instance_create(SB_PIXEL_WATER, 5, 5);
    sb_element_instance* testb = sb_element_instance_create(SB_PIXEL_WATER, 8, 8);
    sb_element_registry_add(registry, test);
    sb_element_registry_add(registry, testb);
}

void sb_destroy() {
    sb_element_registry_destroy(registry, true);
    sb_renderer_destroy(renderer);
    sb_event_destroy(sevent);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
}

int main() {
    sb_init();

    bool redraw = true;
    ALLEGRO_EVENT event;

    al_start_timer(timer);
    while (1) {
        al_wait_for_event(queue, &event);

        if (event.type == ALLEGRO_EVENT_TIMER)
            redraw = true;
        else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;
        sb_event_execute(sevent, &event);

        sb_mouse_on_frame();

        if (redraw && al_is_event_queue_empty(queue)) {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            sb_element_registry_render(registry);
            al_flip_display();

            redraw = false;
        }
    }

    sb_destroy();

    return 0;
}
