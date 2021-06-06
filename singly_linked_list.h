//
// Created by onacit on 2021-06-05.
//
//https://gist.github.com/meylingtaing/11018042
#ifndef DATA_STRUCTURES_IN_C_SINGLY_LINKED_LIST_H
#define DATA_STRUCTURES_IN_C_SINGLY_LINKED_LIST_H

#include "singly_linked_node.h"

//struct singly_linked_node {
//    void *data;
//    struct singly_linked_node *next;
//};

struct singly_linked_list {
    struct singly_linked_node *head;
};

struct singly_linked_list * singly_linked_list_malloc();

void singly_linked_list_free(struct singly_linked_list *);

int singly_linked_list_insert(struct singly_linked_list *, size_t, void *);

void * singly_linked_list_delete(struct singly_linked_list *, size_t);

void * singly_linked_list_peek(struct singly_linked_list *, size_t);

void singly_linked_list_traverse(struct singly_linked_list *, void (*)(void *));

size_t singly_linked_list_size(struct singly_linked_list *);

void singly_linked_list_empty(struct singly_linked_list *, void (*)(void *));


#endif //DATA_STRUCTURES_IN_C_SINGLY_LINKED_LIST_H