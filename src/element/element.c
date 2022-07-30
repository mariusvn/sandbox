#include "element.h"

sb_element_instance* sb_element_instance_create(sb_pixel_id id, unsigned short x, unsigned short y) {
    sb_element_instance* instance = al_malloc(sizeof (sb_element_instance));
    sbasserts(instance != NULL, "MallocFailed");
    instance->pixel_id = id;
    instance->coords.x = x;
    instance->coords.y = y;
    return instance;
}

void sb_element_instance_destroy(sb_element_instance* instance) {
    al_free(instance);
}

void sb_element_instance_render(sb_element_instance* instance, unsigned int index, sb_renderer* renderer) {
    sb_renderer_put_pixel(renderer, instance->coords.x, instance->coords.y, instance->pixel_id);
}

sb_element_registry* sb_element_registry_create(sb_renderer* renderer) {
    sb_element_registry* registry = al_malloc(sizeof(sb_element_registry));
    sbasserts(registry != NULL, "MallocFailed");
    registry->renderer = renderer;
    registry->element_list = sb_list_create();
    return registry;
}

void sb_element_registry_add(sb_element_registry* registry, sb_element_instance* instance) {
    sb_list_push(registry->element_list, instance);
}

void sb_element_registry_destroy_childs_callback(sb_element_instance* instance, unsigned int index, void* nothing) {
    sb_element_instance_destroy(instance);
}

void sb_element_registry_destroy(sb_element_registry* registry, bool destroy_childs) {
    if (destroy_childs) {
        sb_list_foreach(
            registry->element_list,
            (sb_list_foreach_hander) sb_element_registry_destroy_childs_callback,
            NULL
        );
    }

    sb_list_destroy(registry->element_list);
    al_free(registry);
}

void sb_element_registry_render(sb_element_registry* registry) {
    sb_renderer* renderer = registry->renderer;

    sb_list_foreach(
        registry->element_list,
        (sb_list_foreach_hander) sb_element_instance_render,
        registry->renderer
    );
}