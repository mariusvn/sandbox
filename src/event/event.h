
#ifndef SANDBOX_EVENT_H
#define SANDBOX_EVENT_H

#include <allegro5/allegro5.h>
#include "../list/list.h"

typedef void (sb_event_handler)(ALLEGRO_EVENT*);

struct sb_event_unit {
    ALLEGRO_EVENT_TYPE type;
    sb_event_handler* handler;
};

typedef struct sb_event_unit sb_event_unit;

struct sb_event {
    sb_list* units; // sb_event_unit*
};

typedef struct sb_event sb_event;

sb_event* sb_event_create();
void sb_event_register(sb_event* sevent, ALLEGRO_EVENT_TYPE type, sb_event_handler* handler);
void sb_event_execute(sb_event* sevent, ALLEGRO_EVENT* event);
void sb_event_destroy(sb_event* event);

#endif //SANDBOX_EVENT_H
