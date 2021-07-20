//
// Created by onacit on 2021-06-05.
//

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_node.h"
#include "singly_linked_list.h"


struct singly_linked_list_env_ {
    struct singly_linked_node *head;
};


struct singly_linked_node * node(struct list *l, size_t i) {
    assert(l != NULL);
    struct singly_linked_list_env_ *e = l->env_;
    struct singly_linked_node *n = e->head;
    for (size_t j = 0; n != NULL && j < i; j++) {
        n = n->next;
    }
    return n;
}

struct singly_linked_node* tail(struct list *l) {
    assert(l != NULL);
    struct singly_linked_list_env_ *e = l->env_;
    struct singly_linked_node *n = e->head;
    if (n == NULL) {
        return NULL;
    }
    for (; n->next != NULL; n = n->next) {
    }
    return n;
}

size_t singly_linked_list_size(struct list *l) {
    assert(l != NULL);
    size_t s = 0;
    struct singly_linked_list_env_ *e = l->env_;
    struct singly_linked_node *n = e->head;
    for (; n != NULL; n = n->next) {
        s++;
    }
    return s;
}

bool singly_linked_list_empty(struct list *l) {
    assert(l != NULL);
    //return singly_linked_list_size(l) == 0;
    struct singly_linked_list_env_ *e = l->env_;
    return e->head == NULL;
}

void singly_linked_list_insert(struct list *l, size_t i, void *d) {
    assert(l != NULL);
    struct singly_linked_list_env_ *e = l->env_;
    if (i == 0) {
        struct singly_linked_node *n = singly_linked_node(d);
        assert(n != NULL);
        n->next = e->head;
        e->head = n;
        return;
    }
    struct singly_linked_node *p = node(l, i - 1);
    singly_linked_node_insert_next(p, d);
}

void singly_linked_list_insert_first_(struct list *l, void *d) {
    size_t i = 0;
    singly_linked_list_insert(l, 0, d);
}

void singly_linked_list_insert_last_(struct list *l, void *d) {
    size_t i = singly_linked_list_size(l);
    singly_linked_list_insert(l, i, d);
}

void * singly_linked_list_delete(struct list *l, size_t i) {
    assert(l != NULL);
    assert(!singly_linked_list_empty(l));
    if (i == 0) {
        struct singly_linked_list_env_ *e = l->env_;
        struct singly_linked_node *h = e->head;
        assert(h != NULL);
        e->head = h->next;
        h->next = NULL;
        return singly_linked_node_free(h);
    }
    struct singly_linked_node *p = node(l, i - 1);
    return singly_linked_node_delete_next(p);
}

void * singly_linked_list_delete_first_(struct list *l) {
    size_t i = 0;
    return singly_linked_list_delete(l, i);
}

void * singly_linked_list_delete_last_(struct list *l) {
    size_t i = singly_linked_list_size(l) - 1;
    return singly_linked_list_delete(l, i);
}

// ---------------------------------------------------------------------------------------------------------------------

struct list * singly_linked_list() {
    struct singly_linked_list_env_ *e = malloc(sizeof(struct singly_linked_list_env_));
    if (e == NULL) {
        return NULL;
    }
    struct list *l = malloc(sizeof(struct list));
    if (l == NULL) {
        free(e);
        return NULL;
    }
    l->env_ = e;
    l->size = singly_linked_list_size;
    l->empty_ = singly_linked_list_empty;
    l->insert = singly_linked_list_insert;
    l->insert_first_ = singly_linked_list_insert_first_;
    l->insert_last_ = singly_linked_list_insert_last_;
    l->delete = singly_linked_list_delete;
    l->delete_first_ = singly_linked_list_delete_first_;
    l->delete_last_ = singly_linked_list_delete_last_;
    return l;
}

void singly_linked_list_free(struct list *l) {
    assert(l != NULL);
    assert(singly_linked_list_empty(l));
    free(l);
}
