//
// Created by onacit on 2021-06-06.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

struct doubly_linked_node* doubly_linked_list_get_node(struct doubly_linked_list*, size_t);

struct doubly_linked_node* doubly_linked_list_insert_node(struct doubly_linked_list*, size_t, void*);

struct doubly_linked_node* doubly_linked_list_get_node(struct doubly_linked_list *l, size_t i) {
    assert(l != NULL);
    assert(l->head != NULL);
    struct doubly_linked_node *n = l->head;
    for (size_t c = 0; c < i; c++) {
        n = n->next;
    }
    return n;
}

struct doubly_linked_node* doubly_linked_list_insert_node(struct doubly_linked_list *l, size_t i, void *d) {
//    assert(l != NULL);
//    struct doubly_linked_node *n = malloc(sizeof(struct doubly_linked_node));
//    if (n == NULL) {
//        return NULL;
//    }
//    n->prev = NULL;
//    struct singly_linked_node *s = malloc(sizeof(struct singly_linked_node_alloc));
//    if (s == NULL) {
//        free(n);
//        return NULL;
//    }
//    s->n = NULL;
//    if (i == 0) {
//        n->sing->n = l->head;
//        l->head = n;
//    } else {
//        struct doubly_linked_node *p = doubly_linked_list_get_node(l, i - 1);
//        n->sing->n = p->sing->n;
//        p->sing->n = n;
//    }
//    n->sing->data = d;
//    return n;
    return NULL;
}

// ---------------------------------------------------------------------------------------------------------------------

struct doubly_linked_list * doubly_linked_list_malloc() {
    struct doubly_linked_list *list = malloc(sizeof(struct doubly_linked_list));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void doubly_linked_list_free(struct doubly_linked_list *list) {
    assert(list != NULL);
//    assert(list->head == NULL);
    // todo clear nodes
    free(list);
}

// ---------------------------------------------------------------------------------------------------------------------

int doubly_linked_list_insert(struct doubly_linked_list *l, size_t i, void *d) {
    struct doubly_linked_node *n = doubly_linked_list_insert_node(l, i, d);
    if (n == NULL) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}


