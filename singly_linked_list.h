//
// Created by onacit on 2021-06-05.
//
#ifndef DATA_STRUCTURES_IN_C_SINGLY_LINKED_LIST_H
#define DATA_STRUCTURES_IN_C_SINGLY_LINKED_LIST_H

#include "singly_linked_node.h"

struct singly_linked_list {
    struct singly_linked_node *head;
};

struct singly_linked_list * singly_linked_list_alloc();

void singly_linked_list_free(struct singly_linked_list *l, void (*a)(void *));

bool singly_linked_list_empty(struct singly_linked_list *l);

size_t singly_linked_list_size(struct singly_linked_list *l);

int singly_linked_list_insert(struct singly_linked_list *l, size_t i, void *d);

void * singly_linked_list_delete(struct singly_linked_list *l, size_t i);

void singly_linked_list_traverse(struct singly_linked_list *l, void (*a)(void *));

void * singly_linked_list_get_data(struct singly_linked_list *l, size_t i);

void * singly_linked_list_set_data(struct singly_linked_list *l, size_t i, void *d);

#endif //DATA_STRUCTURES_IN_C_SINGLY_LINKED_LIST_H