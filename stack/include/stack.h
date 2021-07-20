//
// Created by onacit on 2021-06-09.
//

#ifndef DATA_STRUCTURES_IN_C_STACK_H
#define DATA_STRUCTURES_IN_C_STACK_H

#include <stdbool.h>

struct stack {

    void * env;

    size_t (*size)(struct stack *);
    bool (*empty)(struct stack *);

    void (*push)(struct stack *, void *);
    void * (*pop)(struct stack *);
};

size_t stack_size(struct stack *s);

bool empty(struct stack *s);

void stack_push(struct stack *s, void *d);

void * stack_pop(struct stack *s);

#endif //DATA_STRUCTURES_IN_C_STACK_H
