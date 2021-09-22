//
// Created by onacit on 2021-07-22.
//

#include <assert.h>
#include "queue.h"

size_t queue_size(struct queue *q) {
    assert(q != NULL);
    return q->size(q);
}

bool queue_empty(struct queue *q) {
    assert(q != NULL);
    if (q->empty != NULL) {
        return q->empty(q);
    }
    return queue_size(q) == 0;
}

void queue_enqueue(struct queue *q, void *d) {
    assert(q != NULL);
    q->enqueue(q, d);
}

void *queue_dequeue(struct queue *q) {
    assert(q != NULL);
    return q->dequeue(q);
}

