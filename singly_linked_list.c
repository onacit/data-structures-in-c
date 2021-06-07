//
// Created by onacit on 2021-06-05.
//

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "common.h"
#include "singly_linked_list.h"

static size_t *found_index;
static struct singly_linked_node* found_node;

void find_node(struct singly_linked_list const *list, bool const (*test)(size_t, void *)) {
    assert(list != NULL);
    assert(test != NULL);
    if (list->head == NULL) {
        found_index = NULL;
        found_node = NULL;
        return;
    }
    size_t i = 0;
    struct singly_linked_node *n = list->head;
    while (true) {
        if ((*test)(i, n)) {
            *found_index = i;
            found_node = n;
            return;
        }
        if ((n = n->next) == NULL) {
            break;
        }
    }
    found_index = NULL;
    found_node = NULL;
}

void find_node_at(struct singly_linked_list *list, size_t index) {
    assert(list != NULL);
    assert(list->head != NULL);
    found_node = list->head;
    for (size_t c = 0; c < index; c++) {
        found_node = found_node->next;
        if (found_node == NULL) {
            return;
        }
    }
}

//void locate_last(struct singly_linked_list *list) {
//    assert(list != NULL);
//    assert(list->head != NULL);
//    found_node = list->head;
//    for (size_t c = 0; c < found_index; c++) {
//        found_node = found_node->next;
//        if (found_node == NULL) {
//            return;
//        }
//    }
//}

struct singly_linked_node* get_node_at(struct singly_linked_list const *l, size_t const i) {
    assert(l != NULL);
    struct singly_linked_node *n = l->head;
    for (size_t j = 0; n != NULL && j < i; j++) {
        n = n->next;
    }
    return n;
}

//void accept_for_each_node_and_with(struct singly_linked_list *list, void (*consumer)(struct singly_linked_node *), void (*then)(), void *with) {
//    assert(list != NULL);
//    assert(consumer != NULL);
//    for (struct singly_linked_node *i = list->head; i != NULL; i = i->next) {
//        (*consumer)(i);
//        if (then != NULL) {
//            (*then)(with);
//        }
//    }
//}
//
//void accept_for_each_node_and(struct singly_linked_list *list, void (*consumer)(struct singly_linked_node *), void (*then)()) {
//    assert(list != NULL);
//    assert(consumer != NULL);
//    for (struct singly_linked_node *i = list->head; i != NULL; i = i->next) {
//        (*consumer)(i);
//        if (then != NULL) {
//            (*then)();
//        }
//    }
//}
//
//void accept_data_and(struct singly_linked_node *node, void (*consumer)(void *), void (*then)()) {
//    assert(node != NULL);
//    assert(consumer != NULL);
//    (*consumer)(node);
//    if (then != NULL) {
//        (*then)();
//    }
//}

// ---------------------------------------------------------------------------------------------------------------------

struct singly_linked_list * singly_linked_list_malloc() {
    struct singly_linked_list *l = malloc(sizeof(struct singly_linked_list));
    if (l == NULL) {
        return NULL;
    }
    l->head = NULL;
    return l;
}

int singly_linked_list_insert(struct singly_linked_list *l, size_t const i, void *d) {
    assert(l != NULL);
    struct singly_linked_node *n = singly_linked_node_malloc(d);
    if (n == NULL) {
        return EXIT_FAILURE;
    }
    if (i == 0) {
        n->next = l->head;
        l->head = n;
        return EXIT_SUCCESS;
    }
    struct singly_linked_node *p = get_node_at(l, i - 1);
    if (p == NULL) {
        singly_linked_node_free(n);
        return EXIT_FAILURE;
    }
    singly_linked_node_link_next(p, n);
    return EXIT_SUCCESS;
}

void * singly_linked_list_delete(struct singly_linked_list *l, size_t const i) {
    assert(l != NULL);
    assert(l->head != NULL);
    if (i == 0) {
        struct singly_linked_node* n = l->head;
        l->head = n->next;
        n->next = NULL;
        return singly_linked_node_free(n);
    }
    struct singly_linked_node *p = get_node_at(l, i - 1);
    struct singly_linked_node *n = singly_linked_node_unlink_next(p);
    return singly_linked_node_free(n);
}

void * singly_linked_list_peek(struct singly_linked_list *l, size_t i) {
    struct singly_linked_node* n = get_node_at(l, i);
    assert(n != NULL);
    return n->data;
}

void singly_linked_list_traverse(struct singly_linked_list const *l, void const (*a)(void *)) {
    assert(l != NULL);
    assert(a != NULL);
    for (struct singly_linked_node *n = l->head; n != NULL; n = n->next) {
        (*a)(n->data);
    }
}

size_t singly_linked_list_size(struct singly_linked_list const *l) {
    assert(l != NULL);
    size_t s = 0;
    for (struct singly_linked_node *n = l->head; n != NULL; n = n->next) {
        s++;
    }
    return s;
}

//void singly_linked_list_empty(struct singly_linked_list *list, void (*consumer)(void *)) {
//    assert(list != NULL);
//    while (list->head != NULL) {
//        void *data = singly_linked_list_delete(list, 0);
//        (*consumer)(data);
//    }
//}

void singly_linked_list_free(struct singly_linked_list *l, void const (*a)(void *)) {
    assert(l != NULL);
    assert(l->head == NULL || a != NULL);
    while(l->head != NULL) {
        void *d = singly_linked_list_delete(l, 0);
        (*a)(d);
    }
    free(l);
}
