#include "event.h"

sb_event* sb_event_create() {
    sb_event* res = al_malloc(sizeof(sb_event));
    sbasserts(res != NULL, "MallocFailed");
    res->units = sb_list_create();
    return res;
}

void sb_event_register(sb_event* sevent, ALLEGRO_EVENT_TYPE type, sb_event_handler* handler) {
    sbasserts(sevent != NULL, "BadArguments");
    sbasserts(handler != NULL, "BadArguments");
    sb_event_unit* unit = al_malloc(sizeof(sb_event_unit));
    sbasserts(unit != NULL, "MallocFailed");
    unit->type = type;
    unit->handler = handler;
    sb_list_push(sevent->units, unit);
}

void sb_event_execute(sb_event* sevent, ALLEGRO_EVENT* event) {
    sbasserts(sevent != NULL, "BadArguments");
    sbasserts(event != NULL, "BadArguments");
    for (int i = 0; i < sevent->units->length; i++) {
        sb_event_unit* units = sb_list_get(sevent->units, sb_event_unit*, i);
        if (units->type == event->type) {
            units->handler(event);
        }
    }
}

void sb_event_destroy(sb_event* sevent) {
    sbasserts(sevent != NULL, "BadArguments");
    for (int i = 0; i < sevent->units->length; i++) {
        sb_event_unit* units = sb_list_get(sevent->units, sb_event_unit*, i);
        al_free(units);
    }
    sb_list_destroy(sevent->units);
}