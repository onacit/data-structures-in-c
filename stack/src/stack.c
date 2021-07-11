//
// Created by onacit on 2021-06-09.
//

#include <assert.h>
#include <stdlib.h>
#include "stack.h"

size_t stack_size(struct stack *s) {
    assert(s != NULL);
    return s->size(s);
}

bool stack_size_zero_(struct stack *s) {
    assert(s != NULL);
    if (s->size_zero_ != NULL) {
        return s->size_zero_(s);
    }
    return stack_size(s) == 0;
}

void stack_push(struct stack *s, void *d) {
    assert(s != NULL);
    s->push(s, d);
}

void * stack_pop(struct stack *s) {
    assert(s != NULL);
    return s->pop(s);
}

