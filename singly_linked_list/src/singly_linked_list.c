//
// Created by onacit on 2021-06-05.
//

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"

static size_t *found_index;
static struct singly_linked_node* found_node;

struct singly_linked_node* node(struct singly_linked_list *l, size_t i) {
    assert(l != NULL);
    struct singly_linked_node *n = l->head;
    for (size_t j = 0; n != NULL && j < i; j++) {
        n = n->next;
    }
    return n;
}

// ---------------------------------------------------------------------------------------------------------------------

struct singly_linked_list * singly_linked_list_alloc() {
    struct singly_linked_list *l = malloc(sizeof(struct singly_linked_list));
    if (l == NULL) {
        fprintf(stderr, "failed to allocate memory for a singly_linked_list");
        return NULL;
    }
    l->head = NULL;
    return l;
}

void singly_linked_list_free(struct singly_linked_list *l, void (*f)(void *)) {
    assert(l != NULL);
    assert(f != NULL);
    for (struct singly_linked_node *n = l->head; n != NULL; n = n->next) {
        (*f)(n->data);
        n->data = NULL;
    }
    for (struct singly_linked_node *n; l->head != NULL; ) {
        n = l->head;
        l->head = n->next;
        n->next = NULL;
        singly_linked_node_free(n);
    }
    free(l); // != (*f)
}

bool singly_linked_list_empty(struct singly_linked_list *l) {
    assert(l != NULL);
    return l->head == NULL;
}

size_t singly_linked_list_size(struct singly_linked_list *l) {
    assert(l != NULL);
    size_t s = 0;
    for (struct singly_linked_node *n = l->head; n != NULL; n = n->next) {
        s++;
    }
    return s;
}

int singly_linked_list_insert(struct singly_linked_list *l, size_t i, void *d) {
    assert(l != NULL);
    struct singly_linked_node *n = singly_linked_node_alloc(d);
    if (n == NULL) {
        fprintf(stderr, "failed to allocate memory for a singly_linked_node");
        return EXIT_FAILURE;
    }
    if (i == 0) {
        n->next = l->head;
        l->head = n;
        return EXIT_SUCCESS;
    }
    struct singly_linked_node *p = node(l, i - 1);
    if (p == NULL) {
        singly_linked_node_free(n);
        return EXIT_FAILURE;
    }
    singly_linked_node_link_next(p, n);
    return EXIT_SUCCESS;
}

void * singly_linked_list_delete(struct singly_linked_list *l, size_t i) {
    assert(l != NULL);
    assert(l->head != NULL);
    if (i == 0) {
        struct singly_linked_node *h = l->head;
        l->head = h->next;
        h->next = NULL;
        return singly_linked_node_free(h);
    }
    struct singly_linked_node *p = node(l, i - 1);
    struct singly_linked_node *n = singly_linked_node_unlink_next(p);
    return singly_linked_node_free(n);
}

void singly_linked_list_traverse(struct singly_linked_list *l, void (*a)(void *)) {
    assert(l != NULL);
    assert(a != NULL);
    for (struct singly_linked_node *n = l->head; n != NULL; n = n->next) {
        (*a)(n->data);
    }
}

void * singly_linked_list_get_data(struct singly_linked_list *l, size_t i) {
    struct singly_linked_node* n = node(l, i);
    assert(n != NULL);
    return n->data;
}

void * singly_linked_list_set_data(struct singly_linked_list *l, size_t i, void *d) {
    struct singly_linked_node* n = node(l, i);
    assert(n != NULL);
    void *prev = n->data;
    n->data = d;
    return prev;
}
