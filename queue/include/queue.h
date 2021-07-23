#ifndef DATA_STRUCTURES_IN_C_QUEUE_H
#define DATA_STRUCTURES_IN_C_QUEUE_H

#include <stdbool.h>

struct queue {

    void * env;

    size_t (*size)(struct queue *);
    bool (*empty)(struct queue *);

    void (*enqueue)(struct queue *, void *);
    void * (*dequeue)(struct queue *);
};

size_t queue_size(struct queue *q);

bool queue_empty(struct queue *q);

void queue_enqueue(struct queue *q, void *d);

void * queue_dequeue(struct queue *q);

#endif //DATA_STRUCTURES_IN_C_QUEUE_H
