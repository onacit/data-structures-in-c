//
// Created by onacit on 2021-06-05.
//
//https://gist.github.com/meylingtaing/11018042
#ifndef DATA_STRUCTURES_IN_C_SINGLY_LINKED_LIST_H
#define DATA_STRUCTURES_IN_C_SINGLY_LINKED_LIST_H

#include "singly_linked_node.h"

typedef struct singly_linked_list_ {
    singly_linked_node *head;
} singly_linked_list;

singly_linked_list * singly_linked_list_alloc();

void singly_linked_list_free(singly_linked_list *l, void (*a)(void *));

bool singly_linked_list_empty(singly_linked_list *l);

size_t singly_linked_list_size(singly_linked_list *l);

int singly_linked_list_insert(singly_linked_list *l, size_t i, void *d);

void * singly_linked_list_delete(singly_linked_list *l, size_t i);

int singly_linked_list_insert_last(singly_linked_list *l, void *);

void * singly_linked_list_delete_first(singly_linked_list *l);

void singly_linked_list_traverse(singly_linked_list *l, void (*a)(void *));

void * singly_linked_list_get_data(singly_linked_list *l, size_t i);

void * singly_linked_list_set_data(singly_linked_list *l, size_t i, void *d);

#endif //DATA_STRUCTURES_IN_C_SINGLY_LINKED_LIST_H