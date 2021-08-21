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

bool stack_empty(struct stack *s) {
    assert(s != NULL);
    if (s->empty != NULL) {
        return s->empty(s);
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

