//
// Created by onacit on 2021-06-05.
//

#include <assert.h>
#include <stdlib.h>
#include "singly_linked_list.h"

struct singly_linked_node* get_node_at(struct singly_linked_list *, size_t);

struct singly_linked_node* get_node_at(struct singly_linked_list *list, size_t index) {
    assert(list != NULL);
    assert(list->head != NULL);
    struct singly_linked_node *node = list->head;
    for (size_t c = 0; c < index; c++) {
        node = node->next;
        if (node == NULL) {
            return NULL;
        }
    }
    return node;
}

// ---------------------------------------------------------------------------------------------------------------------

struct singly_linked_list* singly_linked_list_malloc() {
    struct singly_linked_list *list = malloc(sizeof(struct singly_linked_list));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    return list;
}

void singly_linked_list_free(struct singly_linked_list *list) {
    assert(list != NULL);
    while(list->head != NULL) {
        void *data = singly_linked_list_delete(list, 0);
    }
    free(list);
}

// ---------------------------------------------------------------------------------------------------------------------

int singly_linked_list_insert(struct singly_linked_list *list, size_t index, void *data) {
    assert(list != NULL);
    struct singly_linked_node *node = singly_linked_node_malloc(data);
    if (node == NULL) {
        return EXIT_FAILURE;
    }
    if (index == 0) {
        node->next = list->head;
        list->head = node;
    } else {
        struct singly_linked_node *prev = get_node_at(list, index - 1);
        if (prev == NULL) {
            singly_linked_node_free(node);
            return EXIT_FAILURE;
        }
        singly_linked_node_link(prev, node);
    }
    return EXIT_SUCCESS;
}

void * singly_linked_list_delete(struct singly_linked_list *list, size_t index) {
    assert(list != NULL);
    assert(list->head != NULL);
    if (index == 0) {
        struct singly_linked_node* node = list->head;
        list->head = node->next;
        node->next = NULL;
        return singly_linked_node_free(node);
    }
    struct singly_linked_node *prev = singly_linked_list_peek(list, index - 1);
    struct singly_linked_node *node = singly_linked_node_unlink(prev);
    return singly_linked_node_free(node);
}

void * singly_linked_list_peek(struct singly_linked_list *list, size_t index) {
    struct singly_linked_node* node = get_node_at(list, index);
    if (node == NULL) {
        return NULL;
    }
    return node->data;
}

void singly_linked_list_traverse(struct singly_linked_list *list, void (*consumer)(void *)) {
    assert(list != NULL);
    for (struct singly_linked_node *node = list->head; node != NULL; node = node->next) {
        (*consumer)(node->data);
    }
}

size_t singly_linked_list_size(struct singly_linked_list *list) {
    assert(list != NULL);
    size_t size = 0;
    for (struct singly_linked_node *node = list->head; node != NULL; node = node->next) {
        size++;
    }
    return size;
}

void singly_linked_list_empty(struct singly_linked_list *list, void (*consumer)(void *)) {
    assert(list != NULL);
    while (list->head != NULL) {
        void *data = singly_linked_list_delete(list, 0);
        (*consumer)(data);
    }
}

