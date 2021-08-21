
#include <assert.h>
#include <stdlib.h>
#include "singly_linked_list.h"
#include "singly_linked_list_stack.h"

struct stack * singly_linked_list_stack() {
    struct list *l = singly_linked_list();
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

void singly_linked_list_stack_free(struct stack *const s) {
    assert(s != NULL);
    struct list *l = s->env;
    singly_linked_list_free(l);
    free(s);
}
