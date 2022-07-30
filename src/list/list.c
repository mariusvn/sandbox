#include "list.h"

sb_list_node* sb_list_node_create(sb_list* list, void* element) {
    sb_list_node* node = al_malloc(sizeof(sb_list_node));
    sbasserts(node != NULL, "MallocFailed");
    sbasserts(list != NULL, "BadArguments");
    node->list = list;
    node->element = element;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void sb_list_node_destroy(sb_list_node* node) {
    al_free(node);
}

sb_list* sb_list_create() {
    sb_list* list = al_malloc(sizeof(sb_list));
    sbasserts(list != NULL, "MallocFailed");
    list->length = 0;
    list->start = NULL;
    return list;
}

void sb_list_destroy(sb_list* list) {
    sb_list_node* node = list->start;
    sb_list_node* tmp;

    while (node) {
        tmp = node->next;
        sb_list_node_destroy(node);
        node = tmp;
    }
    al_free(list);
}

void sb_list_push_void(sb_list* list, void* element) {
    sb_list_node* node = sb_list_node_create(list, element);

    /* if list empty */
    if (list->start == NULL) {
        assert(list->length == 0);
        list->start = node;
        list->length = 1;
        return;
    }

    /* if list not empty */
    sb_list_node* c_node = list->start;

    while (c_node->next) {
        c_node = c_node->next;
    }

    c_node->next = node;
    node->prev = c_node;

    list->length ++;
}

void* sb_list_get_void(sb_list* list, unsigned int index) {
    sb_list_node* node = list->start;
    sbasserts(node != NULL, "OutOfRangeException");

    for (unsigned int i = 0; i < index; i++) {
        node = node->next;
    }

    return node->element;
}

void* sb_list_remove_void(sb_list* list, unsigned int index) {
    sb_list_node* node = list->start;
    sbasserts(node != NULL, "OutOfRangeException");

    for (unsigned int i = 0; i < index; i++) {
        node = node->next;
    }
    void* elem = node->element;

    if (node->prev) {
        node->prev->next = node->next;
    }
    node->list->length --;
    sb_list_node_destroy(node);

    return elem;
}

void sb_list_foreach(sb_list* list, sb_list_foreach_hander handler, void* optionnal_arg) {
    sb_list_node* node = list->start;
    unsigned int index = 0;

    while (node) {
        handler(node->element, index, optionnal_arg);
        index++;
        node = node->next;
    }
}