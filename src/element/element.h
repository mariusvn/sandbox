
#ifndef SANDBOX_ELEMENT_H
#define SANDBOX_ELEMENT_H

#include <allegro5/allegro5.h>
#include "../data/pixels_data.h"
#include "../data/types.h"
#include "../list/list.h"
#include "../render/render.h"

struct sb_element_instance {
    sb_pixel_id pixel_id;
    sb_coords coords;
    // add execution handler
};

typedef struct sb_element_instance sb_element_instance;

struct sb_element_registry {
    sb_list* element_list;
    sb_renderer* renderer;
};

typedef struct sb_element_registry sb_element_registry;

sb_element_instance* sb_element_instance_create(sb_pixel_id id, unsigned short x, unsigned short y);
void sb_element_instance_destroy(sb_element_instance* instance);
void sb_element_instance_render(sb_element_instance* instance, unsigned int index, sb_renderer* renderer);
sb_element_registry* sb_element_registry_create(sb_renderer* renderer);
void sb_element_registry_add(sb_element_registry* registry, sb_element_instance* instance);
void sb_element_registry_destroy(sb_element_registry* registry, bool destroy_childs);
void sb_element_registry_render(sb_element_registry* registry);



#endif //SANDBOX_ELEMENT_H
