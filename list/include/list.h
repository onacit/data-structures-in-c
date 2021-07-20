//
// Created by onacit on 2021-06-05.
//
#ifndef DATA_STRUCTURES_IN_C_LIST_H
#define DATA_STRUCTURES_IN_C_LIST_H

#include <stdbool.h>


struct list {

    void *env_;

    size_t (*size)(struct list *l);
    bool (*empty_)(struct list *l);

    void (*insert)(struct list *l, size_t i, void *d);
    void (*insert_first_)(struct list *l, void *d);
    void (*insert_last_)(struct list *l, void *d);

    void * (*delete)(struct list *l, size_t i);
    void * (*delete_first_)(struct list *l);
    void * (*delete_last_)(struct list *l);

    void * (*get)(struct list *l, size_t i);
    void * (*get_first_)(struct list *l);
    void * (*get_last_)(struct list *l);

    void * (*set)(struct list *l, size_t i, void *d);
    void * (*set_first_)(struct list *l, void *d);
    void * (*set_last_)(struct list *l, void *d);

    //struct list_iterator * (*iterator)(struct list *l, size_t i);
};

struct list_iterator {

    void *env_;

    bool (*next)(struct list_iterator *i);

    bool (*prev)(struct list_iterator *i);

    void (*insert)(struct list_iterator *i, void *d);

    void * (*delete)(struct list_iterator *i);

    void * (*get)(struct list_iterator *i);

    void * (*set)(struct list_iterator *i, void *d);
};


size_t list_size(struct list *l);

bool list_empty_(struct list *l);


void list_insert(struct list *l, size_t i, void *d);

void list_insert_first_(struct list *l, void *d);

void list_insert_last_(struct list *l, void *d);


void * list_delete(struct list *l, size_t i);

void * list_delete_first_(struct list *l);

void * list_delete_last_(struct list *l);


void * list_get(struct list *l, size_t i);

void * list_get_first(struct list *l);

void * list_get_last(struct list *l);


void * list_set(struct list *l, size_t i, void *d);

void * list_set_first(struct list *l, void *d);

void * list_set_last(struct list *l, void *d);


#endif //DATA_STRUCTURES_IN_C_LIST_H