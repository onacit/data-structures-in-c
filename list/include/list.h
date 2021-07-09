//
// Created by onacit on 2021-06-05.
//
#ifndef DATA_STRUCTURES_IN_C_LIST_H
#define DATA_STRUCTURES_IN_C_LIST_H

#include <stdbool.h>

struct list {

    void *environment;

    size_t (*size)(struct list *l);
    bool (*size_zero_)(struct list *l);

    bool (*insert)(struct list *l, size_t i, void *d);
    bool (*insert_first_)(struct list *l, void *d);
    bool (*insert_last_)(struct list *l, void *d);

    bool (*delete)(struct list *l, size_t i, void (*f)(void *));
    bool (*delete_first_)(struct list *l, void (*f)(void *));
    bool (*delete_last_)(struct list *l, void (*f)(void *));

    bool (*access)(struct list *l, size_t i, void (*f)(void **));
    bool (*access_first)(struct list *l, void (*f)(void **));
    bool (*access_last)(struct list *l, void (*f)(void **));
};


size_t list_size(struct list *l);

bool list_empty(struct list *l);


bool list_insert(struct list *l, size_t i, void *d);

bool list_push_front(struct list *l, void *d);

bool list_push_back(struct list *l, void *d);


bool list_delete(struct list *l, size_t i, void (*f)(void *));

bool list_pop_front(struct list *l, void (*f)(void *));

bool list_pop_back(struct list *l, void (*f)(void *));


bool list_access(struct list *l, size_t i, void (*f)(void **));

bool list_front(struct list *l, void (*f)(void **));

bool list_back(struct list *l, void (*f)(void **));


#endif //DATA_STRUCTURES_IN_C_LIST_H