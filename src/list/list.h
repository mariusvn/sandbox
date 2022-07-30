
#ifndef SANDBOX_LIST_H
#define SANDBOX_LIST_H

#include <allegro5/allegro5.h>
#include "../macro/macro.h"

struct sb_list;

struct sb_list_node {
    void* element;
    struct sb_list_node* next;
    struct sb_list_node* prev;
    struct sb_list* list;
};

struct sb_list {
    struct sb_list_node* start;
    unsigned int length;
};

typedef struct sb_list sb_list;
typedef struct sb_list_node sb_list_node;
typedef void (*sb_list_foreach_hander)(void* element, unsigned int index, void* optionnal_arg);

sb_list* sb_list_create();
void sb_list_destroy(sb_list* list);
void sb_list_push_void(sb_list* list, void* element);
void sb_list_push_start_void(sb_list* list, void* element);
void* sb_list_get_void(sb_list* list, unsigned int index);
void* sb_list_remove_void(sb_list* list, unsigned int index);
void sb_list_foreach(sb_list* list, sb_list_foreach_hander handler, void* optionnal_arg);

#define sb_list_push(list, element) sb_list_push_void(list, (void*) (element))
#define sb_list_push_start(list, element) sb_list_push_start_void(list, (void*) (element))
#define sb_list_remove(list, type, index) ((type)sb_list_remove_void(list, index))
#define sb_list_get(list, type, index) ((type)sb_list_get_void(list, index))

#endif //SANDBOX_LIST_H
