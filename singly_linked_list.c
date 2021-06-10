//
// Created by onacit on 2021-06-05.
//

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "common.h"
#include "singly_linked_list.h"

static size_t *found_index;
static singly_linked_node* found_node;

singly_linked_node* get_node(singly_linked_list *l, size_t i) {
    assert(l != NULL);
    singly_linked_node *n = l->head;
    for (size_t j = 0; n != NULL && j < i; j++) {
        n = n->next;
    }
    assert(n != NULL);
    return n;
}

// ---------------------------------------------------------------------------------------------------------------------

singly_linked_list * singly_linked_list_alloc() {
    size_t size = sizeof(singly_linked_list);
    singly_linked_list *l = malloc(size);
    if (l == NULL) {
        return NULL;
    }
    l->head = NULL;
    return l;
}

void singly_linked_list_free(singly_linked_list *l, void (*a)(void *)) {
    assert(l != NULL);
    while(l->head != NULL) {
        void *d = singly_linked_list_delete(l, 0);
        assert(a != NULL);
        (*a)(d);
    }
    free(l);
}

size_t singly_linked_list_size(singly_linked_list *l) {
    assert(l != NULL);
    size_t s = 0;
    for (singly_linked_node *n = l->head; n != NULL; n = n->next) {
        s++;
    }
    return s;
}

bool singly_linked_list_empty(singly_linked_list *l) {
    assert(l != NULL);
    return l->head == NULL;
}

int singly_linked_list_insert(singly_linked_list *l, size_t i, void *d) {
    assert(l != NULL);
    singly_linked_node *n = singly_linked_node_alloc(d);
    if (n == NULL) {
        return EXIT_FAILURE;
    }
    if (i == 0) {
        n->next = l->head;
        l->head = n;
        return EXIT_SUCCESS;
    }
    singly_linked_node *p = get_node(l, i - 1);
    if (p == NULL) {
        singly_linked_node_free(n);
        return EXIT_FAILURE;
    }
    singly_linked_node_link_next(p, n);
    return EXIT_SUCCESS;
}

void * singly_linked_list_delete(singly_linked_list *l, size_t i) {
    assert(l != NULL);
    assert(l->head != NULL);
    if (i == 0) {
        singly_linked_node *h = l->head;
        l->head = h->next;
        h->next = NULL;
        return singly_linked_node_free(h);
    }
    singly_linked_node *p = get_node(l, i - 1);
    singly_linked_node *n = singly_linked_node_unlink_next(p);
    return singly_linked_node_free(n);
}

int singly_linked_list_insert_last(singly_linked_list *l, void *d) {
    assert(l != NULL);
    singly_linked_node *n = singly_linked_node_alloc(d);
    if (n == NULL) {
        return EXIT_FAILURE;
    }
    singly_linked_node *p;
    for (p = l->head; p != NULL && p->next != NULL; p = p->next) {
    }
    if (p == NULL) { // list is empty
        l->head = n;
        return EXIT_SUCCESS;
    }
    singly_linked_node_link_next(p, n);
    return EXIT_SUCCESS;
}

void * singly_linked_list_delete_first(singly_linked_list *l) {
    return singly_linked_list_delete(l, 0);
}


void singly_linked_list_traverse(singly_linked_list *l, void (*a)(void *)) {
    assert(l != NULL);
    assert(a != NULL);
    for (singly_linked_node *n = l->head; n != NULL; n = n->next) {
        (*a)(n->data);
    }
}

void * singly_linked_list_get_data(singly_linked_list *l, size_t i) {
    singly_linked_node* node = get_node(l, i);
    assert(node != NULL);
    return node->data;
}

void * singly_linked_list_set_data(singly_linked_list *l, size_t i, void *d) {
    singly_linked_node* node = get_node(l, i);
    assert(node != NULL);
    void *prev = node->data;
    node->data = d;
    return prev;
}



//void singly_linked_list_empty(singly_linked_list *list, void (*consumer)(void *)) {
//    assert(list != NULL);
//    while (list->head != NULL) {
//        void *data = singly_linked_list_delete(list, 0);
//        (*consumer)(data);
//    }
//}


