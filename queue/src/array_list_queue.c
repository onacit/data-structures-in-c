//
// Created by onacit on 2021-07-23.
//

#include <assert.h>
#include <stdio.h>
#include "array_list.h"
#include "array_list_queue.h"
#include "list_queue.h"

struct queue *array_list_queue() {
    struct list *l = array_list();
    if (l == NULL) {
        return NULL;
    }
    struct queue *q = list_queue(l);
    if (q == NULL) {
        array_list_free(l);
    }
    return q;
}

void array_list_queue_free(struct queue *q) {
    assert(q != NULL);
}

