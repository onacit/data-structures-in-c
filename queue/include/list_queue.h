//
// Created by onacit on 2021-07-23.
//

#ifndef DATA_STRUCTURES_IN_C_LIST_QUEUE_H
#define DATA_STRUCTURES_IN_C_LIST_QUEUE_H

#include "list.h"
#include "queue.h"

struct queue * list_queue(struct list *l);

struct list * list_queue_free(struct queue *q);

#endif //DATA_STRUCTURES_IN_C_LIST_QUEUE_H
