//
// Created by onacit on 2021-06-09.
//

#include <assert.h>
#include <stdlib.h>
#include "singly_linked_list.h"
#include "stack.h"

struct stack * stack() {
    struct stack *s = malloc(sizeof(struct stack));
    if (s == NULL) {
        return NULL;
    }
    s->list = singly_linked_list();
    if (s->list == NULL) {
        stack_free(s, NULL);
        return NULL;
    }
    return s;
}

void stack_free(struct stack *s, void (*f)(void *)) {
    assert(s != NULL);
    singly_linked_list_free(s->list, f);
    s->list = NULL;
    free(s);
}

int stack_push(struct stack *s, void *d) {
    assert(s != NULL);
    return singly_linked_list_insert(s->list, 0, d);
}

void * stack_pop(struct stack *s) {
    assert(s != NULL);
    return singly_linked_list_delete(s->list, 0);
}

size_t stack_size(struct stack *s) {
    assert(s != NULL);
    return singly_linked_list_size(s->list);
}

bool stack_empty(struct stack *s) {
    assert(s != NULL);
    return singly_linked_list_empty(s->list);
}


