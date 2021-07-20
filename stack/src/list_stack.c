//
// Created by onacit on 2021-07-20.
//

#include <assert.h>
#include <stdlib.h>
#include "list_stack.h"

size_t list_stack_size(struct stack *s) {
    assert(s != NULL);
    struct list *l = s->env;
    return list_size(l);
}

bool list_stack_empty(struct stack *s) {
    assert(s != NULL);
    struct list *l = s->env;
    return list_empty_(l);
}

void list_stack_push(struct stack *s, void *d) {
    assert(s != NULL);
    struct list *l = s->env;
    list_insert_first_(l, d);
}

void * list_stack_pop(struct stack *s) {
    assert(s != NULL);
    struct list *l = s->env;
    return list_delete_first_(l);
}

struct stack * list_stack(struct list *l) {
    assert(l != NULL);
    struct stack *s = malloc(sizeof(struct stack *));
    if (s == NULL) {
        return NULL;
    }
    s->env = l;
    s->size = list_stack_size;
    s->empty = list_stack_empty;
    s->push = list_stack_push;
    s->pop = list_stack_pop;
    return s;
}

void list_stack_free(struct stack *s) {
    assert(s != NULL);
    s->env = NULL;
    free(s);
}