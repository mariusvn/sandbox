
#ifndef SANDBOX_GLOBALS_H
#define SANDBOX_GLOBALS_H

#include <allegro5/allegro5.h>
#include "../event/event.h"
#include "../element/element.h"
#include "../render/render.h"

extern ALLEGRO_TIMER* timer;
extern ALLEGRO_EVENT_QUEUE* queue;
extern ALLEGRO_DISPLAY* display;
extern sb_event* sevent;
extern sb_renderer* renderer;
extern sb_element_registry* registry;

#endif //SANDBOX_GLOBALS_H
