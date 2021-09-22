//
// Created by onacit on 2021-07-20.
//

#include <assert.h>
#include <stdlib.h>
#include "array_list.h"
#include "array_list_stack.h"

struct stack *array_list_stack() {
    struct list *l = array_list();
    if (l == NULL) {
        return NULL;
    }
    struct stack *s = list_stack(l);
    if (s == NULL) {
        free(l);
        return NULL;
    }
    s->env = l;
    return s;
}

void array_list_stack_free(struct stack *const s) {
    assert(s != NULL);
    struct list *l = s->env;
    array_list_free(l);
    free(s);
}
