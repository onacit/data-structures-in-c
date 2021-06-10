//
// Created by onacit on 2021-06-09.
//

#include <assert.h>
#include <stdlib.h>
#include "singly_linked_list.h"
#include "stack.h"

stack * stack_alloc() {
    stack *s = malloc(sizeof(stack));
    if (s == NULL) {
        return NULL;
    }
    s->list = singly_linked_list_alloc();
    if (s->list == NULL) {
        stack_free(s, NULL);
        return NULL;
    }
    return s;
}

void stack_free(stack *s, void (*a)(void *)) {
    assert(s != NULL);
    singly_linked_list_free(s->list, a);
    free(s);
}

int stack_push(stack *s, void *d) {
    assert(s != NULL);
    return singly_linked_list_insert(s->list, 0, d);
}

void * stack_pop(stack *s) {
    assert(!stack_empty(s));
    return singly_linked_list_delete(s->list, 0);
}

size_t stack_size(stack *s) {
    assert(s != NULL);
    return singly_linked_list_size(s->list);
}

bool stack_empty(stack *s) {
    assert(s != NULL);
    return singly_linked_list_empty(s->list);
}



