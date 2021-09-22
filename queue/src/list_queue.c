//
// Created by onacit on 2021-07-23.
//

#include <assert.h>
#include "list_queue.h"

size_t list_queue_size(struct queue *q) {
    assert(q != NULL);
    struct list *l = q->env;
    return list_size(l);
}

bool list_queue_empty(struct queue *q) {
    assert(q != NULL);
    struct list *l = q->env;
    return list_empty(l);
}

void list_queue_enqueue(struct queue *q, void *d) {
    assert(q != NULL);
    struct list *l = q->env;
    list_insert_first(l, d);
}

void *list_queue_dequeue(struct queue *q) {
    assert(q != NULL);
    struct list *l = q->env;
    return list_delete_last(l);
}

struct queue *list_queue(struct list *l) {
    assert(l != NULL);
    struct queue *q = malloc(sizeof(struct queue));
    if (q == NULL) {
        return NULL;
    }
    q->env = l;
    q->size = list_queue_size;
    q->empty = list_queue_empty;
    q->enqueue = list_queue_enqueue;
    q->dequeue = list_queue_dequeue;
    return q;
}

struct list *list_queue_free(struct queue *q) {
    assert(q != NULL);
    struct list *l = q->env;
    q->env = NULL;
    q->size = NULL;
    q->empty = NULL;
    q->enqueue = NULL;
    q->dequeue = NULL;
    free(q);
    return l;
}